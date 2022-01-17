#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include <Uart/Uart.h>
#include <Xdmac/xdmad.h>
#include <Nvic/Nvic.h>
#include <Pmc/Pmc.h>

#include <Init/Init.h>
#include <Hal/Hal.h>

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/// FreeRTOS functions declaration
void vApplicationMallocFailedHook();
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char* pcTaskName);
void vApplicationIdleHook();
void vApplicationTickHook();

/// FreeRTOS task funcitons declaration
static void prvTask1(void* pvParameters);

/// Functions declarations
void Gen_array(uint8_t* const src_buf, const size_t size);

#define UART_BAUDRATE 38400
#define TASK1_PIORITY 2

/** The buffer size for transfer  */
#define BUFFER_SIZE 90

static uint8_t src_buf[BUFFER_SIZE];

static SemaphoreHandle_t uartSemaphore = NULL;
static StaticSemaphore_t uartSemaphore_buffer;

volatile bool memToMemPassed = false;
volatile bool memToPeriphPassed = false;

sXdmad xdmac;
Hal_Uart halUart;

Uart_TxHandler txHandler = {
    .callback = NULL,
    .arg = &halUart,
};

static ByteFifo*
UartTxCallback(void* private_data)
{
    xSemaphoreGiveFromISR(uartSemaphore, NULL);
    return NULL;
}

Uart_TxHandler m_uart_tx_handler = {
    .callback = UartTxCallback,
    .arg = NULL,
};

void
UART4_Handler(void)
{
    Uart_handleInterrupt(&halUart.uart);
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

    uartSemaphore = xSemaphoreCreateBinaryStatic(&uartSemaphore_buffer);
    xSemaphoreGive(uartSemaphore);
    Gen_array(src_buf, BUFFER_SIZE);
    xTaskCreate(prvTask1, "Task1", 3 * configMINIMAL_STACK_SIZE, NULL, TASK1_PIORITY, NULL);
    vTaskStartScheduler();

    return EXIT_SUCCESS;
}

static void
prvTask1(void* pvParameters)
{
    while(1) {
        xSemaphoreTake(uartSemaphore, portMAX_DELAY);
        Hal_uart_write(&halUart, src_buf, BUFFER_SIZE, &m_uart_tx_handler);
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
Gen_array(uint8_t* const src_buf, const size_t size)
{
    /* Initialize source and destination buffer */
    for(int i = 0; i < size; i++) {
        src_buf[i] = '!' + i;
    }
}
