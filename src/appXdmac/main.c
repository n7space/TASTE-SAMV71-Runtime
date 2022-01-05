#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include <Uart/Uart.h>
#include <Init/Init.h>
#include <Hal/Hal.h>
#include <Xdmac/xdmad.h>

#include <Pmc/Pmc.h>
#include <Nvic/Nvic.h>

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void vApplicationMallocFailedHook();
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char* pcTaskName);
void vApplicationIdleHook();
void vApplicationTickHook();

#define BUFFER_SIZE 10

static uint8_t sourceBuffer[BUFFER_SIZE] = {};
static uint8_t destinationBuffer[BUFFER_SIZE] = {};

int
main()
{
    Init_setup_hardware();

    Pmc_enablePeripheralClk(Pmc_PeripheralId_Xdmac);
    Nvic_setInterruptPriority(Nvic_Irq_Xdmac, 1);
    Nvic_enableInterrupt(Nvic_Irq_Xdmac);

    /*Init source and destination buffers*/
    for(int i = 0; i < BUFFER_SIZE; i++) {
        sourceBuffer[i] = i + 'A';
        destinationBuffer[i] = 0;
    }
    // Xdmac xdmac(0x);
    for(;;) {
        ;
    }

    return EXIT_SUCCESS;
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
