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

#ifndef XDMAC_REGISTERS_H
#define XDMAC_REGISTERS_H

#include <stdint.h>

typedef struct
{
    volatile uint32_t cie;
    volatile uint32_t cid;
    volatile uint32_t cim;
    volatile uint32_t cis;
    volatile uint32_t csa;
    volatile uint32_t cda;
    volatile uint32_t cnda;
    volatile uint32_t cndc;
    volatile uint32_t cubc;
    volatile uint32_t cbc;
    volatile uint32_t cc;
    volatile uint32_t cds_msp;
    volatile uint32_t csus;
    volatile uint32_t cdus;
    volatile uint32_t reserved[2];
} Xdmac_ChannelRegisters;

typedef struct
{
    volatile uint32_t gtype;
    volatile uint32_t gcfg;
    volatile uint32_t gwac;
    volatile uint32_t gie;
    volatile uint32_t gid;
    volatile uint32_t gim;
    volatile uint32_t gis;
    volatile uint32_t ge;
    volatile uint32_t gd;
    volatile uint32_t gs;
    volatile uint32_t grs;
    volatile uint32_t gws;
    volatile uint32_t grws;
    volatile uint32_t grwr;
    volatile uint32_t gswr;
    volatile uint32_t gsws;
    volatile uint32_t gswf;
    volatile uint32_t reserved[3];
    volatile Xdmac_ChannelRegisters channelRegs[24];
} Xdmac_Registers;

#endif
