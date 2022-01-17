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

void vApplicationMallocFailedHook();
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char* pcTaskName);
void vApplicationIdleHook();
void vApplicationTickHook();

static void prvTask1(void* pvParameters);

#define UART_BAUDRATE 38400
#define TASK1_PIORITY 1

Hal_Uart halUart;

volatile bool flag = false;

void
UART4_Handler(void)
{
    flag = true;
    Uart_handleInterrupt(&halUart.uart);
}

Uart_TxHandler txHandler = {
    .callback = NULL,
    .arg = &halUart,
};

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
    xTaskCreate(prvTask1, "Task1", configMINIMAL_STACK_SIZE, NULL, TASK1_PIORITY, NULL);

    vTaskStartScheduler();

    return EXIT_SUCCESS;
}

static void
prvTask1(void* pvParameters)
{
    const uint32_t expectedData1 = 0xdecafbad;
    const uint32_t expectedData2 = 0x600dcafe;
    const uint32_t expectedData3 = 0xbadcafe1;

    volatile uint32_t testData = expectedData1;
    volatile uint32_t memVal;
    volatile uint32_t* address = &testData;
    volatile uint32_t result;
    volatile uint32_t newValue = expectedData2;

    __asm volatile("   ldrex  %[memVal],   [%[address]]  \n\r" : [ memVal ] "=&r"(memVal) : [ address ] "r"(address));
    /* : "memory"); */
    halUart.uart.reg->ier = UART_IER_TXEMPTY_MASK;

    // while(flag == false) {
    //     halUart.uart.reg->idr = UART_IDR_TXEMPTY_MASK;
    // }

    /// Write
    __asm volatile("    strex   %[result],  %[newValue], [%[address]] \n\r"
                   /* "    dmb" */
                   : [ result ] "=&r"(result), [ address ] "+r"(address)
                   : [ newValue ] "r"(newValue));
    /* : "memory"); */

    for(;;) {
        ;
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