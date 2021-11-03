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

#ifndef INIT_H
#define INIT_H

/**
 * @file    Init.h
 * @brief   Init - SAMV71Q21 Xplained board initialization
 *
 * The Init component is used by TASTE runtime to initialize SAMV71Q21 Xplained board,
 * the following sequence will be used:
 *
 * ConfigureStartup (copying relevant sections into SRAM)
 * Configure Wdt (watchdog)
 * Configure Pmc (peripheral power)
 * Configure Fpu (floating point unit)
 * Configure Pio (input/output pins)
 * Configure Sdramc (SDRAM controller)
 * Configure FreeRTOS to use SDRAM for task stacks
 * Configure Uart via Hal (Uart for use by AdaRtl)
 * Initialize and start FreeRTOS
 *
 */

void
Init_setup_hardware(void);

#endif