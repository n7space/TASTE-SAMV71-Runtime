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

#include <assert.h>

extern Uart consoleUart;

static void Init_setup_watchdog(void);
static void Init_setup_pmc(void);
static void Init_setup_fpu(void);
static void Init_setup_pio(void);
static void Init_setup_nvic(void);
static void Init_setup_uart(void);

#define UART_BAUDRATE 38400

void
Init_setup_hardware(void)
{
    Init_setup_watchdog();
    Init_setup_pmc();
    Init_setup_fpu();
    Init_setup_pio();
    Init_setup_nvic();
    Init_setup_uart();
}


static void
Init_setup_watchdog(void)
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
Init_setup_nvic(void)
{
    Nvic_enableInterrupt(Nvic_Irq_Uart4);
    Nvic_setInterruptPriority(Nvic_Irq_Uart4, 0);
}

static void
Init_setup_uart(void)
{
    Uart_Config uartConfig = { .isTxEnabled = true,
                               .isRxEnabled = true,
                               .isTestModeEnabled = false,
                               .parity = Uart_Parity_None,
                               .baudRate = UART_BAUDRATE,
                               .baudRateClkSrc = Uart_BaudRateClk_PeripheralCk,
                               .baudRateClkFreq = SystemConfig_DefaultPeriphClock };

    Uart_init(Uart_Id_4, &consoleUart);
    Uart_setConfig(&consoleUart, &uartConfig);
}
