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

#ifndef SAMV71_UART_SERIAL_H
#define SAMV71_UART_SERIAL_H

#include "Uart/Uart.h"

/// \brief Uart configuration structure
typedef struct
{
    Uart_Id id;         /// Uart device identifier (0-4)
    Uart_Parity parity; //< used parity bits
    uint32_t baudrate;  //< chosen baud rate
} Hal_Uart_Config;

/// \brief uart structure
typedef struct
{
    Uart uart;
    ByteFifo rxFifo;
    ByteFifo txFifo;
} Hal_Uart;

/// \brief Starts up, initializes and configures Uart and coresponding periferals
/// \param [in] halUart Hal_Uart structure contains uart device descriptor and relevant fifos.
/// \param [in] halUartConfig configuration structure
void Hal_uart_init(Hal_Uart* const halUart, Hal_Uart_Config halUartConfig);

/// \brief Asynchronously sends bytes over uart.
/// \param [in] halUart Hal_Uart structure contains uart device descriptor and relevant fifos.
/// \param [in] buffer array containing bytes to send
/// \param [in] length length of array of bytes
/// \param [in] txHandler handler called after successful array transmission
void Hal_uart_write(Hal_Uart* const halUart,
                    uint8_t* const buffer,
                    const uint16_t length,
                    const Uart_TxHandler* const txHandler);

/// \brief Asynchronously receives bytes over uart.
/// \param [in] halUart Hal_Uart structure contains uart device descriptor and relevant fifos.
/// \param [in] buffer array where received bytes will be storedx
/// \param [in] length length of array of bytes
/// \param [in] rxHandler handler called after successful array reception or after maching character was found
void Hal_uart_read(Hal_Uart* const halUart,
                   uint8_t* const buffer,
                   const uint16_t length,
                   const Uart_RxHandler rxHandler);

/// \brief Initializes USART 1, which is connected to virtual com port gateway
/**
 * Initializes pmc for pio port B and for usart 1
 * Initializes pio PB4 (TXD1)
 * Initializes USART1 Mode Register (MR) - no parity, 1 stop bit
 * Initializes USART1 baudrate 115200
 */
void Hal_console_usart_init(void);

/// \brief Synchroniously writes bytes over USART1
/// \param [in] buffer array containing bytes to send
/// \param [in] count length of array of bytes
void Hal_console_usart_write(const uint8_t* const buffer, const uint16_t count);

#endif
