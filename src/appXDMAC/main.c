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
void Print_array(uint8_t* const buffer, const size_t size, const size_t edgeSize);
void Gen_array(uint8_t* const src_buf, uint8_t* const dst_buf, const size_t size);

#define UART_BAUDRATE 38400
#define TASK1_PIORITY 1

/** Micro-block length for single transfer  */
#define MICROBLOCK_LEN 90

/** Block length for single transfer  */
#define BLOCK_LEN 1

/** The buffer size for transfer  */
#define BUFFER_SIZE 90

/** XDMA channel used in this example. */
#define XDMA_CH 0

static uint8_t dst_buf[BUFFER_SIZE];
static uint8_t src_buf[BUFFER_SIZE];

volatile bool memToMemPassed = false;
volatile bool memToPeriphPassed = false;

sXdmad xdmac;
Hal_Uart halUart;

Uart_TxHandler txHandler = {
    .callback = NULL,
    .arg = &halUart,
};

#define TEST_FAILED "Test Fail.\n\r"
#define TEST_OK "Test Ok.\n\r"

void Mem_to_mem_callback(uint32_t status, void* arguments);
void Mem_to_periph_callback(uint32_t status, void* arguments);

static ByteFifo*
UartTxCallback(void* private_data)
{
    memToPeriphPassed = true;
    return NULL;
}

Uart_TxHandler m_uart_tx_handler = {
    .callback = UartTxCallback,
    .arg = NULL,
};

// void
// XDMAC_Handler(void)
// {
//     XDMAD_Handler(&xdmac);
// }

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

    Gen_array(src_buf, dst_buf, BUFFER_SIZE);
    Print_array(src_buf, BUFFER_SIZE, 5);
    xTaskCreate(prvTask1, "Task1", configMINIMAL_STACK_SIZE, NULL, TASK1_PIORITY, NULL);
    vTaskStartScheduler();

    return EXIT_SUCCESS;
}

static inline void
Dma_init()
{
    Pmc_enablePeripheralClk(Pmc_PeripheralId_Xdmac);

    Nvic_clearInterruptPending(Nvic_Irq_Xdmac);
    Nvic_setInterruptPriority(Nvic_Irq_Xdmac, 0);
    Nvic_enableInterrupt(Nvic_Irq_Xdmac);

    XDMAD_Initialize(&xdmac, 0);
}

static inline void
Dma_test_mem_to_mem()
{
    uint32_t channelNumber = XDMAD_AllocateChannel(&xdmac, XDMAD_TRANSFER_MEMORY, XDMAD_TRANSFER_MEMORY);
    XDMAD_PrepareChannel(&xdmac, channelNumber);
    sXdmadCfg config = {
        .mbr_ubc = MICROBLOCK_LEN,
        .mbr_sa = (uint32_t)src_buf,
        .mbr_da = (uint32_t)dst_buf,
        .mbr_cfg = XDMAC_CC_TYPE_MEM_TRAN | XDMAC_CC_MBSIZE_SINGLE | XDMAC_CC_MEMSET_NORMAL_MODE | XDMAC_CC_DWIDTH_BYTE
                   | XDMAC_CC_SIF_AHB_IF0 | XDMAC_CC_DIF_AHB_IF0 | XDMAC_CC_SAM_INCREMENTED_AM
                   | XDMAC_CC_DAM_INCREMENTED_AM,
        .mbr_bc = BLOCK_LEN - 1,
        .mbr_ds = 0,
        .mbr_sus = 0,
        .mbr_dus = 0,
    };

    XDMAD_ConfigureTransfer(
            &xdmac, channelNumber, &config, 0, 0, XDMAC_CIE_BIE | XDMAC_CIE_RBIE | XDMAC_CIE_WBIE | XDMAC_CIE_ROIE);
    XDMAD_SetCallback(&xdmac, channelNumber, Mem_to_mem_callback, NULL);
    XDMAD_StartTransfer(&xdmac, channelNumber);
    while(!memToMemPassed) {
    }
}

static inline void
Dma_test_mem_to_periph()
{
    Hal_uart_write(&halUart, src_buf, BUFFER_SIZE, m_uart_tx_handler);
    // uint32_t channelNumber = XDMAD_AllocateChannel(&xdmac, XDMAD_TRANSFER_MEMORY, Pmc_PeripheralId_Uart4);
    // XDMAD_PrepareChannel(&xdmac, channelNumber);

    // uint32_t periphID = xdmac.XdmaChannels[channelNumber].bDstTxIfID << XDMAC_CC_PERID_Pos;

    // sXdmadCfg config = {
    //     .mbr_ubc = MICROBLOCK_LEN,
    //     .mbr_sa = (uint32_t)src_buf,
    //     .mbr_da = (uint32_t)&halUart.uart.reg->thr,
    //     .mbr_cfg = XDMAC_CC_TYPE_PER_TRAN | XDMAC_CC_MBSIZE_SINGLE | XDMAC_CC_DSYNC_MEM2PER
    //                | XDMAC_CC_SWREQ_HWR_CONNECTED | XDMAC_CC_MEMSET_NORMAL_MODE | XDMAC_CC_DWIDTH_BYTE
    //                | XDMAC_CC_SIF_AHB_IF1 | XDMAC_CC_DIF_AHB_IF1 | XDMAC_CC_SAM_INCREMENTED_AM |
    //                XDMAC_CC_DAM_FIXED_AM | periphID,
    //     .mbr_bc = BLOCK_LEN - 1,
    //     .mbr_ds = 0,
    //     .mbr_sus = 0,
    //     .mbr_dus = 0,
    // };
    // XDMAD_ConfigureTransfer(
    //         &xdmac, channelNumber, &config, 0, 0, XDMAC_CIE_BIE | XDMAC_CIE_RBIE | XDMAC_CIE_WBIE |
    //         XDMAC_CIE_ROIE);
    // XDMAD_SetCallback(&xdmac, channelNumber, Mem_to_periph_callback, NULL);
    // XDMAD_StartTransfer(&xdmac, channelNumber);
    while(!memToPeriphPassed) {
    }
}

static void
prvTask1(void* pvParameters)
{
    // Dma_init();
    // Dma_test_mem_to_mem();
    Dma_test_mem_to_periph();
    while(1) {
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
Gen_array(uint8_t* const src_buf, uint8_t* const dst_buf, const size_t size)
{
    /* Initialize source and destination buffer */
    for(int i = 0; i < size; i++) {
        src_buf[i] = '!' + i;
        dst_buf[i] = 0;
    }
}

void
Test_array(const uint8_t* const src_buf, const uint8_t* const dst_buf, const size_t size)
{
    /* Verify the transferred data */
    for(int i = 0; i < size; i++) {
        if(src_buf[i] != dst_buf[i]) {
            Hal_console_usart_write(TEST_FAILED, strlen(TEST_FAILED));
            while(1) {
            }
        }
    }
}

void
Print_array(uint8_t* const buffer, const size_t size, const size_t edgeSize)
{
    for(int i = 0; i < size; i++) {
        if((i % 5) == 0)
            Hal_console_usart_write("\n\r", 2);
        Hal_console_usart_write(&buffer[i], 1);
        Hal_console_usart_write("  ", 2);
    }
}

void
Mem_to_mem_callback(uint32_t status, void* arguments)
{
    (void)arguments;
    Test_array(src_buf, dst_buf, BUFFER_SIZE);

    Print_array(dst_buf, BUFFER_SIZE, 5);
    Hal_console_usart_write(TEST_OK, strlen(TEST_OK));
    memToMemPassed = true;
}

void
Mem_to_periph_callback(uint32_t status, void* arguments)
{
    (void)arguments;
    memToPeriphPassed = true;
}