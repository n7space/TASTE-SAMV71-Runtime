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

#ifndef XDMAC_H
#define XDMAC_H

#include <Xdmac/XdmacRegisters.h>

typedef enum
{
    Xdmac_ChannelTransferType_SelfTriggered = 0,
    Xdmac_ChannelTransferType_Synchronized,
} Xdmac_ChannelTransferType;

typedef enum
{
    Xdmac_ChannelMemoryBurstSize_Single = 0,
    Xdmac_ChannelMemoryBurstSize_Four,
    Xdmac_ChannelMemoryBurstSize_Eight,
    Xdmac_ChannelMemoryBurstSize_Sixteen,
} Xdmac_ChannelMemoryBurstSize;

typedef enum
{
    Xdmac_ChannelSynchronization_PeriphToMem = 0,
    Xdmac_ChannelSynchronization_MemToPeriph,
} Xdmac_ChannelSynchronization;

typedef enum
{
    Xdmac_ChannelRequestTrigger_Hardware = 0,
    Xdmac_ChannelRequestTrigger_Software,
} Xdmac_ChannelRequestTrigger;

typedef enum
{
    Xdmac_ChannelMemset_NormalMode = 0,
    Xdmac_ChannelMemset_HardwareMode,
} Xdmac_ChannelMemset;

typedef enum
{
    Xdmac_ChannelChunkSize_1 = 0,
    Xdmac_ChannelChunkSize_2,
    Xdmac_ChannelChunkSize_4,
    Xdmac_ChannelChunkSize_8,
    Xdmac_ChannelChunkSize_16,
} Xdmac_ChannelChunkSize;

typedef enum
{
    Xdmac_ChannelDataWidth_Byte = 0,
    Xdmac_ChannelDataWidth_HalfWord,
    Xdmac_ChannelDataWidth_Word,
} Xdmac_ChannelDataWidth;

typedef enum
{
    Xdmac_ChannelAddressingMode_Fixed = 0,
    Xdmac_ChannelAddressingMode_Incremented,
    Xdmac_ChannelAddressingMode_uBlockStride,
    Xdmac_ChannelAddressingMode_uBlockAndDataStride,
} Xdmac_ChannelAddressingMode;

typedef enum
{
    Xdmac_ChannelPeripheralId_Usart0_Tx = 7,
    Xdmac_ChannelPeripheralId_Usart0_Rx = 8,
    Xdmac_ChannelPeripheralId_Uart4_Tx = 28,
    Xdmac_ChannelPeripheralId_Uart4_Rx = 29,
} Xdmac_ChannelPeripheralId;

typedef struct
{
    Xdmac_ChannelTransferType transferType;
    Xdmac_ChannelMemoryBurstSize memoryBurstSize;
    Xdmac_ChannelSynchronization synchronization;
    Xdmac_ChannelRequestTrigger requestTrigger;
    Xdmac_ChannelMemset memsetMode;
    Xdmac_ChannelChunkSize chunkSize;
    Xdmac_ChannelDataWidth dataWidth;
    Xdmac_ChannelAddressingMode sourceAddressingMode;
    Xdmac_ChannelAddressingMode destinationAddressingMode;
    Xdmac_ChannelPeripheralId peripheralId;
} Xdmac_ChannelDataConfig;

typedef enum
{
    Xdmac_LinkedListView_0 = 0,
    Xdmac_LinkedListView_1,
    Xdmac_LinkedListView_2,
    Xdmac_LinkedListView_3,
} Xdmac_LinkedListView;

typedef struct
{
    void* nextDescriptorAddress;
    Xdmac_LinkedListView nextDescriptorView;
    bool isNextDescriptorFetchEnabled;
    bool isNextDescriptorSourceUpdateEnabled;
    bool isNextDescriptorDestinationUpdateEnabled;
} Xdmac_DescriptorControl;

typedef struct
{
    void* sourceAddress;
    void* destinationAddress;
    uint32_t uBlockLength;
    uint32_t blockLength;
    Xdmac_ChannelDataConfig dataConfig;
    Xdmac_DescriptorControl linkedListDescriptor;
} Xdmac_ChannelConfig;

/// \brief A structure mapping the contents of a linked list node descriptor with view type 0.
typedef struct
{
    uint32_t nda; ///< Next Descriptor Address.
    uint32_t ubc; ///< Microblock Control.
    uint32_t ta;  ///< Transfer Address.
} Xdmac_LinkedListNode_View0;

typedef enum
{
    Xdmac_Channel_0,
    Xdmac_Channel_1,
    Xdmac_Channel_2,
    Xdmac_Channel_3,
    Xdmac_Channel_4,
    Xdmac_Channel_5,
    Xdmac_Channel_6,
    Xdmac_Channel_7,
    Xdmac_Channel_8,
    Xdmac_Channel_9,
    Xdmac_Channel_10,
    Xdmac_Channel_11,
    Xdmac_Channel_12,
    Xdmac_Channel_13,
    Xdmac_Channel_14,
    Xdmac_Channel_15,
    Xdmac_Channel_16,
    Xdmac_Channel_17,
    Xdmac_Channel_18,
    Xdmac_Channel_19,
    Xdmac_Channel_20,
    Xdmac_Channel_21,
    Xdmac_Channel_22,
    Xdmac_Channel_23,
    Xdmac_Number_Of_Channels,
}Xdmac_Channel;

/// \brief Function used to enable a channel.
/// \param [in] channel Identifier of the channel to enable.
void Xdmac_enableChannel(Xdmac_Channel const channel);

/// \brief Function used to disable a channel.
/// \param [in] channel Identifier of the channel to disable.
void Xdmac_disableChannel(Xdmac_Channel const channel);

/// \brief Function used to enable interrupts on a channel.
/// \param [in] channel Identifier of the channel to enable interrupts on.
void Xdmac_enableChannelIrqs(Xdmac_Channel const channel);

/// \brief Function used to enable interrupts on a channel.
/// \param [in] channel Identifier of the channel to enable interrupts on.
void Xdmac_disableChannelIrqs(Xdmac_Channel const channel);

#endif