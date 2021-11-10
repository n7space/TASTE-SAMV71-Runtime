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

#include "Init.h"

#include "Wdt/Wdt.h"
#include "Fpu/Fpu.h"
#include "Pmc/Pmc.h"
#include "SystemConfig/SystemConfig.h"
#include "Pio/Pio.h"
#include "Nvic/Nvic.h"
#include "Uart/Uart.h"
#include "Sdramc/Sdramc.h"

#include "HAL/Hal.h"

#include <assert.h>
#include <string.h>

extern Uart consoleUart;
extern Hal_Uart halUart;

static void Init_setup_watchdog(void);
static void Init_setup_pmc(void);
static void Init_setup_fpu(void);
static void Init_setup_pio(void);
static void Init_setup_nvic(void);
static void Init_setup_console_usart(void);
static void Init_setup_sdram(void);

static void Init_setup_sdram_pio(void);
static void Init_setup_sdram_pio_portA(void);
static void Init_setup_sdram_pio_portC(void);
static void Init_setup_sdram_pio_portD(void);
static void Init_setup_sdram_pio_portE(void);
static void Init_setup_sdram_pio_pin(Pio* const pio, const uint32_t pin, const Pio_Control control);
static void Init_setup_sdram_pmc(void);
static void Init_setup_sdram_config(Sdramc* const sdramc);

#define UART_BAUDRATE 38400

void
Init_setup_hardware(void)
{
    Init_setup_watchdog();
    Init_setup_pmc();
    Init_setup_fpu();
    Init_setup_pio();
    Init_setup_nvic();
    Init_setup_console_usart();
    Init_setup_sdram();
}

static void
Init_setup_watchdog(void)
{
    const Wdt_Config wdtConfig = {
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
Init_setup_fpu(void)
{
    Fpu fpu;
    Fpu_init(&fpu);
    Fpu_startup(&fpu);
}

static void
Init_setup_pmc(void)
{
    int errCode = 0;

    Pmc_Config pmcConfig = SystemConfig_getPmcDefaultConfig();
    Pmc_setConfig(&pmcConfig, &errCode);

    assert(errCode == 0);
}

static void
Init_setup_pio(void)
{
}

static void
Init_setup_nvic(void)
{
}

static void
Init_setup_console_usart(void)
{
    Hal_console_usart_init();
}

static void
Init_setup_sdram(void)
{
    Sdramc sdramc;
    Init_setup_sdram_pio();
    Init_setup_sdram_pmc();
    Sdramc_init(&sdramc);
    Sdramc_startup(&sdramc);
    Init_setup_sdram_config(&sdramc);
    Sdramc_performInitializationSequence(&sdramc, SystemConfig_DefaultCoreClock);
}

static inline void
Init_setup_sdram_pio(void)
{
    Init_setup_sdram_pio_portA();
    Init_setup_sdram_pio_portC();
    Init_setup_sdram_pio_portD();
    Init_setup_sdram_pio_portE();
}

static inline void
Init_setup_sdram_pio_portA(void)
{
    Pio portA;
    Pio_init(Pio_Port_A, &portA);
    Pmc_enablePeripheralClk(Pmc_PeripheralId_PioA);
    Init_setup_sdram_pio_pin(&portA, PIO_PIN_20, Pio_Control_PeripheralC); // Connected
    Init_setup_sdram_pio_pin(&portA, PIO_PIN_15, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portA, PIO_PIN_16, Pio_Control_PeripheralA); // Connected
}

static inline void
Init_setup_sdram_pio_portC(void)
{
    Pio portC;
    Pio_init(Pio_Port_C, &portC);
    Pmc_enablePeripheralClk(Pmc_PeripheralId_PioC);
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_18, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_20, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_21, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_22, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_23, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_24, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_25, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_26, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_27, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_28, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_29, Pio_Control_PeripheralA); // Connected

    Init_setup_sdram_pio_pin(&portC, PIO_PIN_0, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_1, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_2, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_3, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_4, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_5, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_6, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portC, PIO_PIN_7, Pio_Control_PeripheralA); // Connected

    Init_setup_sdram_pio_pin(&portC, PIO_PIN_15, Pio_Control_PeripheralA); // Connected
}

static inline void
Init_setup_sdram_pio_portD(void)
{
    Pio portD;
    Pio_init(Pio_Port_D, &portD);
    Pmc_enablePeripheralClk(Pmc_PeripheralId_PioD);
    Init_setup_sdram_pio_pin(&portD, PIO_PIN_17, Pio_Control_PeripheralC); // Connected

    Init_setup_sdram_pio_pin(&portD, PIO_PIN_15, Pio_Control_PeripheralC); // Connected
    Init_setup_sdram_pio_pin(&portD, PIO_PIN_16, Pio_Control_PeripheralC); // Connected

    Init_setup_sdram_pio_pin(&portD, PIO_PIN_13, Pio_Control_PeripheralC); // Connected Shared PC13
    Init_setup_sdram_pio_pin(&portD, PIO_PIN_23, Pio_Control_PeripheralC); // Connected
    Init_setup_sdram_pio_pin(&portD, PIO_PIN_14, Pio_Control_PeripheralC); // Connected
    Init_setup_sdram_pio_pin(&portD, PIO_PIN_29, Pio_Control_PeripheralC); // Connected
}

static inline void
Init_setup_sdram_pio_portE(void)
{
    Pio portE;
    Pio_init(Pio_Port_E, &portE);
    Pmc_enablePeripheralClk(Pmc_PeripheralId_PioE);
    Init_setup_sdram_pio_pin(&portE, PIO_PIN_0, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portE, PIO_PIN_1, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portE, PIO_PIN_2, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portE, PIO_PIN_3, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portE, PIO_PIN_4, Pio_Control_PeripheralA); // Connected
    Init_setup_sdram_pio_pin(&portE, PIO_PIN_5, Pio_Control_PeripheralA); // Connected
}

static inline void
Init_setup_sdram_pio_pin(Pio* const pio, const uint32_t pin, const Pio_Control control)
{
    Pio_Pin_Config config;
    memset(&config, 0, sizeof(Pio_Pin_Config));
    config.control = control;
    config.pull = Pio_Pull_Up;
    Pio_setPinsConfig(pio, pin, &config);
}

static inline void
Init_setup_sdram_pmc(void)
{
    Pmc_enablePeripheralClk(Pmc_PeripheralId_Smc);
    Pmc_enablePeripheralClk(Pmc_PeripheralId_Sdramc);
}

static inline void
Init_setup_sdram_config(Sdramc* const sdramc)
{
    // These values apply to IS42S16100H chip
    const Sdramc_Config IS42S16100H_SDRAM_CONFIG = {
        .refreshTimerCount = 1172, // Value 15.625 us for 75 MHz
        .columnBits = Sdramc_NumberOfColumnBits_Col8,
        .rowBits = Sdramc_NumberOfRowBits_Row11,
        .banks = Sdramc_NumberOfBanks_Bank2,
        .casLatency = Sdramc_CasLatency_Latency3,
        .dataBusWidth = Sdramc_DataBusWidth_16bits,
        .writeRecoveryDelay = 5,
        .rowCycleDelayAndRowRefreshCycle = 13,
        .rowPrechargeDelay = 5,
        .rowToColumnDelay = 5,
        .activeToPrechargeDelay = 9,
        .exitSelfRefreshToActiveDelay = 15,
        .lowPowerConfiguration = Sdramc_LowPowerConfiguration_Disabled,
        .partialArraySelfRefresh = 0,
        .temperatureCompensatedSelfRefresh = 0,
        .driveStrength = 0,
        .lowPowerEnableTimeout = Sdramc_LowPowerEnableTimeout_LpLastXfer128,
        .deviceType = Sdramc_MemoryDeviceType_Sdram,
        .loadModeRegisterCommandToActiveOrRefreshCommand = 2,
        .supportUnalignedAccess = Sdramc_SupportUnalignedAccess_Supported,
        .isRefreshErrorStatusInterruptEnabled = false,
    };

    Sdramc_setConfig(sdramc, &IS42S16100H_SDRAM_CONFIG);
}