#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include <Uart/Uart.h>
#include <Init/Init.h>

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

#define UART_BAUDRATE 38400
#define UART_TIMEOUT 100000u
#define TASK1_PIORITY 1 //(tskIDLE_PRIORITY + 2)
#define TASK2_PIORITY 2 //(tskIDLE_PRIORITY + 1)

#define TASK1_MSG "\n\rHello from task1\t Received: "
#define TASK2_MSG "\n\rHello from task2\t Sent: "

/* The rate at which data is sent to the queue.  The 200ms value is converted
to ticks using the portTICK_PERIOD_MS constant. */
#define TASK1_FREQUENCY (100 / portTICK_PERIOD_MS)
#define TASK2_FREQUENCY (500 / portTICK_PERIOD_MS)

Uart consoleUart;
/* The queue used by both tasks. */
static QueueHandle_t xQueue = NULL;
uint8_t buffer[25];

int
main()
{
    Init_setup_hardware();

    /* Create the queue. */
    xQueue = xQueueCreate(1, sizeof(uint32_t));

    xTaskCreate(prvTask2, "Task2", configMINIMAL_STACK_SIZE, NULL, TASK2_PIORITY, NULL);
    xTaskCreate(prvTask1, "Task1", configMINIMAL_STACK_SIZE, NULL, TASK1_PIORITY, NULL);

    vTaskStartScheduler();

    for (;;) {
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

    for (;;) {
        /* Send to the queue - causing the queue receive task to unblock and
            toggle the LED.  0 is used as the block time so the sending operation
            will not block - it shouldn't need to block as the queue should always
            be empty at this point in the code. */
        /* Place this task in the blocked state until it is time to run again. */
        // vTaskDelayUntil(&xNextWakeTime, TASK1_FREQUENCY);

        xQueueReceive(xQueue, &ulReceivedValue, TASK1_FREQUENCY);
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

    for (;;) {
        /* Wait until something arrives in the queue - this task will block
        indefinitely provided INCLUDE_vTaskSuspend is set to 1 in
        FreeRTOSConfig.h. */
        xQueueSend(xQueue, &ulValueToSend, portMAX_DELAY);

        consoleWrite((uint8_t*)TASK2_MSG, sizeof(TASK2_MSG));
        consoleWrite(&ulValueToSend, 1);

        ulValueToSend++;
        if (ulValueToSend > 'z') {
            ulValueToSend = 'A';
        }
        // /* Place this task in the blocked state until it is time to run again. */
        vTaskDelayUntil(&xNextWakeTime, TASK2_FREQUENCY);
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
    for (uint16_t i = 0; i < size; i++) {
        Uart_write(&consoleUart, buffer[i], UART_TIMEOUT, NULL);
    }
}