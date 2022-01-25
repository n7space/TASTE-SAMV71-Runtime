/**@file
 * This file is part of the TASTE Runtime SAMV71.
 *
 * @copyright 2021 N7 Space Sp. z o.o.
 *
 * TASTE Runtime SAMV71 was developed under a programme of,
 * and funded by, the European Space Agency (the "ESA").
 *
 * Licensed under the ESA Public License (ESA-PL) Permissive,
 * Version 2.3 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     https://essr.esa.int/license/list
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include <Uart/Uart.h>
#include <Init/Init.h>
#include <Hal/Hal.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

static void prvTask1(void* pvParameters);
static void prvTask2(void* pvParameters);

void vApplicationMallocFailedHook();
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char* pcTaskName);
void vApplicationIdleHook();
void vApplicationTickHook();

void consoleWrite(uint8_t* buffer, uint16_t size);
ByteFifo* uartTxEndCallback(void* arg);

#define UART_BAUDRATE 38400
#define UART_TIMEOUT 100000u
#define TASK1_PIORITY 1
#define TASK2_PIORITY 2

#define TASK1_MSG "\n\rHello from task1\t Received: "
#define TASK2_MSG "\n\rHello from task2\t Sent: "

/* The rate at which data is sent to the queue.  The 200ms value is converted
to ticks using the portTICK_PERIOD_MS constant. */
#define TASK1_DELAY (100 / portTICK_PERIOD_MS)
#define TASK2_DELAY (500 / portTICK_PERIOD_MS)

Hal_Uart halUart;

Uart_TxHandler txHandler = {
    .callback = uartTxEndCallback,
    .arg = &halUart,
};

static SemaphoreHandle_t binarySemaphore;

/* The queue used by both tasks. */
static QueueHandle_t xQueue = NULL;
uint8_t buffer[25];

void
UART4_Handler(void)
{
    Uart_handleInterrupt(&halUart.uart, &errCode);
}

int
main()
{
    Init_setup_hardware();

    Hal_Uart_Config config = {
        .id = Uart_Id_4,
        .parity = Uart_Parity_None,
        .baudrate = UART_BAUDRATE,
    };

    Hal_uart_init(&halUart, config);

    /* Create the queue. */
    xQueue = xQueueCreate(1, sizeof(uint32_t));

    /// Create binary semaphore
    binarySemaphore = xSemaphoreCreateBinary();
    xSemaphoreGive(binarySemaphore);

    xTaskCreate(prvTask2, "Task2", configMINIMAL_STACK_SIZE, NULL, TASK2_PIORITY, NULL);
    xTaskCreate(prvTask1, "Task1", configMINIMAL_STACK_SIZE, NULL, TASK1_PIORITY, NULL);

    vTaskStartScheduler();

    for(;;) {
        ;
    }

    return EXIT_SUCCESS;
}

static void
prvTask1(void* pvParameters)
{
    uint8_t ulReceivedValue;

    TickType_t xNextWakeTime;
    (void)pvParameters;

    /* Initialise xNextWakeTime - this only needs to be done once. */
    xNextWakeTime = xTaskGetTickCount();

    for(;;) {
        /** Wait until something arrives in the queue - this task will block
         * for 100ms
         */
        xQueueReceive(xQueue, &ulReceivedValue, TASK1_DELAY);
        consoleWrite((uint8_t*)TASK1_MSG, sizeof(TASK1_MSG));
        consoleWrite(&ulReceivedValue, 1);
    }
}

static void
prvTask2(void* pvParameters)
{
    uint8_t ulValueToSend = 'A';
    TickType_t xNextWakeTime;
    (void)pvParameters;

    /* Initialise xNextWakeTime - this only needs to be done once. */
    xNextWakeTime = xTaskGetTickCount();

    for(;;) {
        /** Send to the queue - causing the queue receive task to unblock.
         * Sending operation will not block - it shouldn't need to block
         * as the queue should always  be empty at this point in the code.
         */
        xQueueSend(xQueue, &ulValueToSend, portMAX_DELAY);

        consoleWrite((uint8_t*)TASK2_MSG, sizeof(TASK2_MSG));
        consoleWrite(&ulValueToSend, 1);

        ulValueToSend++;
        if(ulValueToSend > 'z') {
            ulValueToSend = 'A';
        }
        // Place this task in the blocked state until it is time to run again. */
        vTaskDelayUntil(&xNextWakeTime, TASK2_DELAY);
    }
}

void
vApplicationMallocFailedHook()
{
    configASSERT(0);
}

void
vApplicationStackOverflowHook(TaskHandle_t pxTask, char* pcTaskName)
{
    (void)pxTask;
    (void)pcTaskName;

    configASSERT(0);
}

void
vApplicationIdleHook()
{
    volatile size_t xFreeHeapSpace = xPortGetFreeHeapSize();
    (void)xFreeHeapSpace;
}

void
vApplicationTickHook()
{
}

void
consoleWrite(uint8_t* buffer, uint16_t size)
{
    xSemaphoreTake(binarySemaphore, portMAX_DELAY);
    Hal_uart_write(&halUart, buffer, size, &txHandler);
}

ByteFifo*
uartTxEndCallback(void* arg)
{
    BaseType_t taskWoken;
    xSemaphoreGiveFromISR(binarySemaphore, &taskWoken);
    return NULL;
}
