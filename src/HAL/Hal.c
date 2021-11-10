#include "Hal.h"

#include "assert.h"

#include "Pio/Pio.h"
#include "Nvic/Nvic.h"
#include "SystemConfig/SystemConfig.h"

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
    ByteFifo_init(&halUart->rxFifo, halUart->rxMemoryBlock, RX_FIFO_SIZE);
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
            Nvic_setInterruptPriority(Nvic_Irq_Uart0, 0);
            break;
        case Uart_Id_1:
            Nvic_enableInterrupt(Nvic_Irq_Uart1);
            Nvic_setInterruptPriority(Nvic_Irq_Uart1, 0);
            break;
        case Uart_Id_2:
            Nvic_enableInterrupt(Nvic_Irq_Uart2);
            Nvic_setInterruptPriority(Nvic_Irq_Uart2, 0);
            ;
            break;
        case Uart_Id_3:
            Nvic_enableInterrupt(Nvic_Irq_Uart3);
            Nvic_setInterruptPriority(Nvic_Irq_Uart3, 0);
            break;
        case Uart_Id_4:
            Nvic_enableInterrupt(Nvic_Irq_Uart4);
            Nvic_setInterruptPriority(Nvic_Irq_Uart4, 0);
            break;
    }
}
