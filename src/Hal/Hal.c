#include "Hal.h"
#include "UsartRegisters.h"

#include "assert.h"

#include "Pio/Pio.h"
#include "Nvic/Nvic.h"
#include "SystemConfig/SystemConfig.h"

#include "FreeRTOS/FreeRTOSConfig.h"

#define USART_BAUD_RATE 115200

/**
 * @brief UART priotity definition
 * System interrupts priorities levels must be smaller than
 * kernel interrupts levels. The lower the priority value the
 * higher the priority is. Thus, the UART interrupt priority value
 * must be equal or greater then configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY.
 */

#define UART_INTERRUPT_PRIORITY configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY

static void Hal_uart_init_pio(Uart_Id id);
static void Hal_uart_init_uart0_pio(Pio_Port* const port,
                                    Pio_Port_Config* const pioConfigTx,
                                    Pio_Port_Config* const pioConfigRx);
static void Hal_uart_init_uart1_pio(Pio_Port* const port,
                                    Pio_Port_Config* const pioConfigTx,
                                    Pio_Port_Config* const pioConfigRx);
static void Hal_uart_init_uart2_pio(Pio_Port* const port,
                                    Pio_Port_Config* const pioConfigTx,
                                    Pio_Port_Config* const pioConfigRx);
static void Hal_uart_init_uart3_pio(Pio_Port* const port,
                                    Pio_Port_Config* const pioConfigTx,
                                    Pio_Port_Config* const pioConfigRx);
static void Hal_uart_init_uart4_pio(Pio_Port* const port,
                                    Pio_Port_Config* const pioConfigTx,
                                    Pio_Port_Config* const pioConfigRx);

static void Hal_uart_init_pmc(Uart_Id id);
static void Hal_uart_init_nvic(Uart_Id id);

void
Hal_uart_init(Hal_Uart* halUart, Hal_Uart_Config halUartConfig)
{
    assert(halUartConfig.id <= Uart_Id_4);
    assert((halUartConfig.parity <= Uart_Parity_Odd) || (halUartConfig.parity == Uart_Parity_None));

    Hal_uart_init_pmc(halUartConfig.id);
    Hal_uart_init_pio(halUartConfig.id);
    Hal_uart_init_nvic(halUartConfig.id);

    Uart_startup(&halUart->uart);
    Uart_init(halUartConfig.id, &halUart->uart);

    Uart_Config config = { .isTxEnabled = true,
                           .isRxEnabled = true,
                           .isTestModeEnabled = false,
                           .parity = halUartConfig.parity,
                           .baudRate = halUartConfig.baudrate,
                           .baudRateClkSrc = Uart_BaudRateClk_PeripheralCk,
                           .baudRateClkFreq = SystemConfig_DefaultPeriphClock };
    Uart_setConfig(&halUart->uart, &config);
}

void
Hal_uart_write(Hal_Uart* halUart, uint8_t* buffer, uint16_t length, const Uart_TxHandler txHandler)
{
    ByteFifo_initFromBytes(&halUart->txFifo, buffer, length);
    Uart_writeAsync(&halUart->uart, &halUart->txFifo, txHandler);
}

void
Hal_uart_read(Hal_Uart* halUart, uint8_t* buffer, uint16_t length, const Uart_RxHandler rxHandler)
{
    ByteFifo_init(&halUart->rxFifo, buffer, length);
    Uart_readAsync(&halUart->uart, &halUart->rxFifo, rxHandler);
}

static inline void
Hal_uart_init_pio(Uart_Id id)
{
    Pio_Port port;
    Pio_Port_Config pioConfigTx = {
        .pinsConfig = {
            .pull = Pio_Pull_Up,
            .filter = Pio_Filter_None,
            .isMultiDriveEnabled = false,
            .isSchmittTriggerDisabled = false,
            .irq = Pio_Irq_None,
            .direction = Pio_Direction_Output,
        },
        .debounceFilterDiv = 0
    };
    pioConfigTx.pinsConfig.direction = Pio_Direction_Output;

    Pio_Port_Config pioConfigRx = pioConfigRx;
    pioConfigRx.pinsConfig.direction = Pio_Direction_Input;

    switch(id) {
        case Uart_Id_0:
            Hal_uart_init_uart0_pio(&port, &pioConfigTx, &pioConfigRx);
            break;
        case Uart_Id_1:
            Hal_uart_init_uart1_pio(&port, &pioConfigTx, &pioConfigRx);
            break;
        case Uart_Id_2:
            Hal_uart_init_uart2_pio(&port, &pioConfigTx, &pioConfigRx);
            break;
        case Uart_Id_3:
            Hal_uart_init_uart3_pio(&port, &pioConfigTx, &pioConfigRx);
            break;
        case Uart_Id_4:
            Hal_uart_init_uart4_pio(&port, &pioConfigTx, &pioConfigRx);
            break;
    }
    Pio pio;
    Pio_init(port, &pio);
    Pio_setPortConfig(&pio, &pioConfigTx);
    Pio_setPortConfig(&pio, &pioConfigRx);
}

inline static void
Hal_uart_init_uart0_pio(Pio_Port* const port, Pio_Port_Config* const pioConfigTx, Pio_Port_Config* const pioConfigRx)
{
    *port = Pio_Port_A;

    pioConfigRx->pins = PIO_PIN_9;
    pioConfigRx->pinsConfig.control = Pio_Control_PeripheralA;

    pioConfigTx->pins = PIO_PIN_10;
    pioConfigTx->pinsConfig.control = Pio_Control_PeripheralA;
}
inline static void
Hal_uart_init_uart1_pio(Pio_Port* const port, Pio_Port_Config* const pioConfigTx, Pio_Port_Config* const pioConfigRx)
{
    *port = Pio_Port_A;

    pioConfigRx->pins = PIO_PIN_5;
    pioConfigRx->pinsConfig.control = Pio_Control_PeripheralC;

    pioConfigTx->pins = PIO_PIN_6;
    pioConfigTx->pinsConfig.control = Pio_Control_PeripheralC;
}
inline static void
Hal_uart_init_uart2_pio(Pio_Port* const port, Pio_Port_Config* const pioConfigTx, Pio_Port_Config* const pioConfigRx)
{
    *port = Pio_Port_D;

    pioConfigRx->pins = PIO_PIN_25;
    pioConfigRx->pinsConfig.control = Pio_Control_PeripheralC;

    pioConfigTx->pins = PIO_PIN_26;
    pioConfigTx->pinsConfig.control = Pio_Control_PeripheralC;
}
inline static void
Hal_uart_init_uart3_pio(Pio_Port* const port, Pio_Port_Config* const pioConfigTx, Pio_Port_Config* const pioConfigRx)
{
    *port = Pio_Port_D;

    pioConfigRx->pins = PIO_PIN_28;
    pioConfigRx->pinsConfig.control = Pio_Control_PeripheralA;

    pioConfigTx->pins = PIO_PIN_30;
    pioConfigTx->pinsConfig.control = Pio_Control_PeripheralA;
}
inline static void
Hal_uart_init_uart4_pio(Pio_Port* const port, Pio_Port_Config* const pioConfigTx, Pio_Port_Config* const pioConfigRx)
{
    *port = Pio_Port_D;

    pioConfigRx->pins = PIO_PIN_18;
    pioConfigRx->pinsConfig.control = Pio_Control_PeripheralC;

    pioConfigTx->pins = PIO_PIN_19;
    pioConfigTx->pinsConfig.control = Pio_Control_PeripheralC;
}

inline static void
Hal_uart_init_pmc(Uart_Id id)
{
    switch(id) {
        case Uart_Id_0:
            Pmc_enablePeripheralClk(Pmc_PeripheralId_PioA);
            Pmc_enablePeripheralClk(Pmc_PeripheralId_Uart0);
            break;
        case Uart_Id_1:
            Pmc_enablePeripheralClk(Pmc_PeripheralId_PioA);
            Pmc_enablePeripheralClk(Pmc_PeripheralId_Uart1);
            break;
        case Uart_Id_2:
            Pmc_enablePeripheralClk(Pmc_PeripheralId_PioD);
            Pmc_enablePeripheralClk(Pmc_PeripheralId_Uart2);
            break;
        case Uart_Id_3:
            Pmc_enablePeripheralClk(Pmc_PeripheralId_PioD);
            Pmc_enablePeripheralClk(Pmc_PeripheralId_Uart3);
            break;
        case Uart_Id_4:
            Pmc_enablePeripheralClk(Pmc_PeripheralId_PioD);
            Pmc_enablePeripheralClk(Pmc_PeripheralId_Uart4);
            break;
    }
}

inline inline static void
Hal_uart_init_nvic(Uart_Id id)
{
    switch(id) {
        case Uart_Id_0:
            Nvic_enableInterrupt(Nvic_Irq_Uart0);
            Nvic_setInterruptPriority(Nvic_Irq_Uart0, UART_INTERRUPT_PRIORITY);
            break;
        case Uart_Id_1:
            Nvic_enableInterrupt(Nvic_Irq_Uart1);
            Nvic_setInterruptPriority(Nvic_Irq_Uart1, UART_INTERRUPT_PRIORITY);
            break;
        case Uart_Id_2:
            Nvic_enableInterrupt(Nvic_Irq_Uart2);
            Nvic_setInterruptPriority(Nvic_Irq_Uart2, UART_INTERRUPT_PRIORITY);
            ;
            break;
        case Uart_Id_3:
            Nvic_enableInterrupt(Nvic_Irq_Uart3);
            Nvic_setInterruptPriority(Nvic_Irq_Uart3, UART_INTERRUPT_PRIORITY);
            break;
        case Uart_Id_4:
            Nvic_enableInterrupt(Nvic_Irq_Uart4);
            Nvic_setInterruptPriority(Nvic_Irq_Uart4, UART_INTERRUPT_PRIORITY);
            break;
    }
}

inline void
Hal_console_usart_init_pio(void)
{
    Pio pioB;
    Pio_init(Pio_Port_B, &pioB);

    Pio_Pin_Config pinConf;
    pinConf.control = Pio_Control_PeripheralD;
    pinConf.direction = Pio_Direction_Input;
    pinConf.pull = Pio_Pull_None;
    pinConf.filter = Pio_Filter_None;
    pinConf.isMultiDriveEnabled = false;
    pinConf.isSchmittTriggerDisabled = false;
    pinConf.irq = Pio_Irq_None;

    Pio_setPinsConfig(&pioB, PIO_PIN_4, &pinConf);
}

inline void
Hal_console_usart_init_pmc(void)
{
    Pmc_enablePeripheralClk(Pmc_PeripheralId_PioB);
    Pmc_enablePeripheralClk(Pmc_PeripheralId_Usart1);
}

inline void
Hal_console_usart_init_mode(void)
{
    // cppcheck-suppress misra2012_11_4
    uint32_t* US_MR = (uint32_t*)USART1_MR_ADDRESS;

    *US_MR = 0;                                                      // Clear
    *US_MR |= USART_MR_MODE_NORMAL << USART_MR_MODE_OFFSET;          // USART_MODE NORMAL
    *US_MR |= USART_MR_USCLKS_MCK << USART_MR_USCLKS_OFFSET;         // USCLKS PCK
    *US_MR |= USART_MR_CHRL_8BIT << USART_MR_CHRL_OFFSET;            // CHRL 8BIT
    *US_MR |= USART_MR_SYNC_ASYNCHRONOUS << USART_MR_SYNC_OFFSET;    // SYNC Asynchronous
    *US_MR |= USART_MR_PAR_NO << USART_MR_PAR_OFFSET;                // PAR No parity
    *US_MR |= USART_MR_NBSTOP_1_BIT << USART_MR_NBSTOP_OFFSET;       // NBSTOP 1 stop bit
    *US_MR |= USART_MR_CHMODE_NORMAL << USART_MR_CHMODE_OFFSET;      // CHMODE Normal mode
    *US_MR |= USART_MR_MSBF_LSB << USART_MR_MSBF_OFFSET;             // MSBF MSB
    *US_MR |= USART_MR_MODE9_CHRL << USART_MR_MODE9_OFFSET;          // MODE9 CHRL defines length
    *US_MR |= USART_MR_CLKO_NO_SCK << USART_MR_CLKO_OFFSET;          // CLKO does not drive SCK pin
    *US_MR |= USART_MR_OVER_16X << USART_MR_OVER_OFFSET;             // OVER 16x oversampling
    *US_MR |= USART_MR_INACK_NOT_GEN << USART_MR_INACK_OFFSET;       // INACK NSCK is not generated
    *US_MR |= USART_MR_DSNACK_NO_NACK << USART_MR_DSNACK_OFFSET;     // DSNACK don't care - no NACK
    *US_MR |= USART_MR_VAR_SYNC_DISABLE << USART_MR_VAR_SYNC_OFFSET; // VAR_SYNC MODSYNC defines sync
    *US_MR |= USART_MR_INVDATA_DISABLED << USART_MR_INVDATA_OFFSET;  // INVDATA do not invert data
    *US_MR |= USART_MR_MAX_ITERATION_DISABLE
              << USART_MR_MAX_ITERATION_OFFSET;                  // MAX_ITERATION don't care - valid in ISO7816 protocol
    *US_MR |= USART_MR_FILTER_DISABLE << USART_MR_FILTER_OFFSET; // FILTER do not filter incomming data
    *US_MR |= USART_MR_MAN_DISABLE << USART_MR_MAN_OFFSET;       // MAN manchester coding disabled
    *US_MR |= USART_MR_MODSYNC_DISABLE << USART_MR_MODSYNC_OFFSET; // MODSYNC don't care - manchester disabled
    *US_MR |= USART_MR_ONEBIT_1_BIT << USART_MR_ONEBIT_OFFSET;     // ONEBIT 1 bit start frame delimiterx
}

inline void
Hal_console_usart_init_baudrate()
{
    // cppcheck-suppress misra2012_11_4
    uint32_t* US_BRGR = (uint32_t*)USART1_BRGR_ADDRESS;
    // BaudRate = CLK / ((coarseDiv + fineDiv / 8) * 16)
    uint32_t coarseDiv = SystemConfig_DefaultPeriphClock / (16u * USART_BAUD_RATE);
    uint64_t fineDiv = 8uLL
                       * (((uint64_t)SystemConfig_DefaultPeriphClock * 1000uLL / (16uLL * USART_BAUD_RATE))
                          - (uint64_t)coarseDiv * 1000uLL);
    fineDiv /= 1000uLL;

    *US_BRGR = coarseDiv | ((uint32_t)fineDiv << USART_BRGR_FINE_DIV_OFFSET);
}

inline void
Hal_console_usart_init_bus_matrix()
{
    // cppcheck-suppress misra2012_11_4
    uint32_t* CCFG_SYSIO = (uint32_t*)MATRIX_CCFG_SYSIO_ADDR;
    // Assign the PB4 pin to the PIO controller (TDI is the default function)
    *CCFG_SYSIO |= MATRIX_CCFG_SYSIO_PB4_SELECTED << MATRIX_CCFG_SYSIO_SYSIO4_OFFSET;
}

inline void
Hal_console_usart_init_tx_enable()
{
    // cppcheck-suppress misra2012_11_4
    uint32_t* US_CR = (uint32_t*)USART1_CR_ADDRESS;
    *US_CR = USART_CR_TXEN_ENABLE << USART_CR_TXEN_OFFSET; // Enable the transmitter
}

void
Hal_console_usart_init(void)
{
    Hal_console_usart_init_bus_matrix();
    Hal_console_usart_init_pmc();
    Hal_console_usart_init_pio();

    Hal_console_usart_init_mode();
    Hal_console_usart_init_baudrate();
    Hal_console_usart_init_tx_enable();
}

inline void
waitForTransmitterReady(void)
{
    volatile uint32_t* const US_CSR = (uint32_t*)USART1_CSR_ADDRESS;
    while(((*US_CSR) & USART_CSR_TXRDY_MASK) == 0)
        asm volatile("nop");
}

inline void
writeByte(const uint8_t data)
{
    waitForTransmitterReady();

    volatile uint32_t* const US_THR = (uint32_t*)USART1_THR_ADDRESS;
    *US_THR = data;
}

void
Hal_console_usart_write(const uint8_t* const buffer, const uint16_t count)
{
    for(uint32_t i = 0; i < count; i++) {
        writeByte(buffer[i]);
    }

    waitForTransmitterReady();
}
