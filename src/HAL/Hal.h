

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

#ifndef RX_FIFO_SIZE
#define RX_FIFO_SIZE 100
#endif

#ifndef TX_FIFO_SIZE
#define TX_FIFO_SIZE 100
#endif

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
    uint8_t rxMemoryBlock[RX_FIFO_SIZE];
    ByteFifo rxFifo;
    uint8_t txMemoryBlock[TX_FIFO_SIZE];
    ByteFifo txFifo;
} Hal_Uart;

/// \brief Starts up, initializes and configures UArt
void Hal_uart_init(Hal_Uart* halUart, Hal_Uart_Config halUartConfig);

bool Hal_uart_write(Hal_Uart* halUart, uint8_t* buffer, uint16_t length, const Uart_TxHandler txHandler);
bool Hal_uart_read(Hal_Uart* halUart, uint8_t* buffer, uint16_t length, const Uart_RxHandler rxHandler);

void Hal_uart_start_read(Hal_Uart* halUart);

#endif
