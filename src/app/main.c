#include "FreeRTOS.h"
#include "task.h"

#include <Fpu/Fpu.h>
#include <Nvic/Nvic.h>
#include <Pio/Pio.h>
#include <Pmc/Pmc.h>
#include <SystemConfig/SystemConfig.h>
#include <Uart/Uart.h>
#include <Wdt/Wdt.h>

#include <assert.h>
#include <stdlib.h>

static void prvSetupHardware();
static void prvSetupWatchdog();
static void prvSetupFpu();
static void prvSetupClock();
static void prvSetupPio();
static void prvSetupNvic();
static void prvSetupUart();

static void prvUartSendDataTask(void* pvParameters);

void vApplicationMallocFailedHook();
void vApplicationStackOverflowHook(TaskHandle_t pxTask, char* pcTaskName);
void vApplicationIdleHook();
void vApplicationTickHook();

#define UART_BAUDRATE 38400
#define UART_TIMEOUT 100000u
#define TASK_PIORITY (tskIDLE_PRIORITY + 2)

static Uart uart;

int
main()
{
    prvSetupHardware();

    xTaskCreate(prvUartSendDataTask, "UartSendData", configMINIMAL_STACK_SIZE, NULL, TASK_PIORITY, NULL);

    vTaskStartScheduler();

    for(;;) {
        ;
    }

    return EXIT_SUCCESS;
}

static void
prvSetupHardware()
{
    prvSetupWatchdog();
    prvSetupFpu();
    prvSetupClock();
    prvSetupPio();
    prvSetupNvic();
    prvSetupUart();
}

static void
prvSetupWatchdog()
{
    Wdt_Config wdtConfig = {
        .counterValue = 0x0FFF,
        .deltaValue = 0x0FFF,
        .isResetEnabled = false,
        .isFaultInterruptEnabled = false,
        .isDisabled = true,
        .isHaltedOnIdle = false,
        .isHaltedOnDebug = false,
    };

    Wdt wdt;
    Wdt_init(&wdt);
    Wdt_setConfig(&wdt, &wdtConfig);
}

static void
prvSetupFpu()
{
    Fpu fpu;
    Fpu_init(&fpu);
    Fpu_startup(&fpu);
}

static void
prvSetupClock()
{
    int errCode = 0;

    Pmc_Config pmcConfig = SystemConfig_getPmcDefaultConfig();
    Pmc_setConfig(&pmcConfig, &errCode);

    assert(errCode == 0);
}

static void
prvSetupPio()
{
    Pmc_enablePeripheralClk(Pmc_PeripheralId_PioD);
    Pmc_enablePeripheralClk(Pmc_PeripheralId_Uart4);

    Pio pio;
    Pio_init(Pio_Port_D, &pio);

    Pio_Port_Config pioConfig = {
        .pinsConfig = {
            .pull = Pio_Pull_Up,
            .filter = Pio_Filter_None,
            .isMultiDriveEnabled = false,
            .isSchmittTriggerDisabled = false,
            .irq = Pio_Irq_None,
        },
        .debounceFilterDiv = 0
    };

    pioConfig.pins = PIO_PIN_18;
    pioConfig.pinsConfig.control = Pio_Control_PeripheralC;
    pioConfig.pinsConfig.direction = Pio_Direction_Input;
    Pio_setPortConfig(&pio, &pioConfig);

    pioConfig.pins = PIO_PIN_19;
    pioConfig.pinsConfig.control = Pio_Control_PeripheralC;
    pioConfig.pinsConfig.direction = Pio_Direction_Output;
    Pio_setPortConfig(&pio, &pioConfig);
}

static void
prvSetupNvic()
{
    Nvic_enableInterrupt(Nvic_Irq_Uart4);
    Nvic_setInterruptPriority(Nvic_Irq_Uart4, 0);
}

static void
prvSetupUart()
{
    Uart_Config uartConfig = { .isTxEnabled = true,
                               .isRxEnabled = true,
                               .isTestModeEnabled = false,
                               .parity = Uart_Parity_None,
                               .baudRate = UART_BAUDRATE,
                               .baudRateClkSrc = Uart_BaudRateClk_PeripheralCk,
                               .baudRateClkFreq = SystemConfig_DefaultPeriphClock };

    Uart_init(Uart_Id_4, &uart);
    Uart_setConfig(&uart, &uartConfig);
}

static void
prvUartSendDataTask(void* pvParameters)
{
    (void)pvParameters;

    Uart_write(&uart, 0x48, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x65, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x6c, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x6c, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x6f, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x2c, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x20, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x57, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x6f, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x72, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x6c, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x64, UART_TIMEOUT, NULL);
    Uart_write(&uart, 0x21, UART_TIMEOUT, NULL);
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
