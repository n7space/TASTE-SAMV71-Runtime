#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include <Init/Init.h>
#include <Hal/Hal.h>
#include <Xdmac/xdmad.h>

#include <assert.h>
#include <stdlib.h>

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

typedef struct __attribute__((packed)) ContextStateFrame
{
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t return_address;
    uint32_t xpsr;
} sContextStateFrame;

// NOTE: If you are using CMSIS, the registers can also be
// accessed through CoreDebug->DHCSR & CoreDebug_DHCSR_C_DEBUGEN_Msk
#define HALT_IF_DEBUGGING()                                                                                            \
    do {                                                                                                               \
        if((*(volatile uint32_t*)0xE000EDF0) & (1 << 0)) {                                                             \
            __asm("bkpt 1");                                                                                           \
        }                                                                                                              \
    } while(0)

#define HARDFAULT_HANDLING_ASM(_x)                                                                                     \
    __asm volatile("tst lr, #4 \n"                                                                                     \
                   "ite eq \n"                                                                                         \
                   "mrseq r0, msp \n"                                                                                  \
                   "mrsne r0, psp \n"                                                                                  \
                   "b my_fault_handler_c \n")

// Disable optimizations for this function so "frame" argument
// does not get optimized away
__attribute__((optimize("O0"))) void
my_fault_handler_c(sContextStateFrame* frame)
{
    // If and only if a debugger is attached, execute a breakpoint
    // instruction so we can take a look at what triggered the fault
    HALT_IF_DEBUGGING();

    // Logic for dealing with the exception. Typically:
    //  - log the fault which occurred for postmortem analysis
    //  - If the fault is recoverable,
    //    - clear errors and return back to Thread Mode
    //  - else
    //    - reboot system
}

void
HardFault_Handler(void)
{
    HARDFAULT_HANDLING_ASM();
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
