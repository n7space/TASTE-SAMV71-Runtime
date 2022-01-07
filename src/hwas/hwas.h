/* Header file for function HWAS in C language
 * Generated by TASTE on 2021-11-29 11:46:28
 * Context Parameters present : NO
 * Provided interfaces : InterruptManagement_DisableInterrupt_Pi, InterruptManagement_EnableInterrupt_Pi,
 * InterruptSubscriptionManagement_SubscribeToInterrupt_Pi, RawMemoryAccess_ReadBuffer_Pi, RawMemoryAccess_ReadWord_Pi,
 * RawMemoryAccess_WriteBuffer_Pi, RawMemoryAccess_WriteWord_Pi Required interfaces : InterruptSubscription_Interrupt_Ri
 * User-defined properties for this function:
 *  |_ TASTE::Is_Component_Type = false
 * DO NOT EDIT THIS FILE, IT WILL BE OVERWRITTEN DURING THE BUILD
 */

#pragma once

#include "dataview-uniq.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __unix__
#include <stdlib.h>
#include <stdio.h>
#endif

    void hwas_startup(void);

    /* Provided interfaces */
    void hwas_PI_InterruptManagement_DisableInterrupt_Pi(const asn1SccInterruptNumber*);
    void hwas_PI_InterruptManagement_EnableInterrupt_Pi(const asn1SccInterruptNumber*);
    void hwas_PI_InterruptSubscriptionManagement_SubscribeToInterrupt_Pi(const asn1SccInterruptNumber*);
    void hwas_PI_RawMemoryAccess_ReadBuffer_Pi(const asn1SccSourceAddress*, asn1SccByteBuffer*);
    void hwas_PI_RawMemoryAccess_ReadWord_Pi(const asn1SccSourceAddress*, const asn1SccWordMask*, asn1SccWord*);
    void hwas_PI_RawMemoryAccess_WriteBuffer_Pi(const asn1SccDestinationAddress*, const asn1SccByteBuffer*);
    void hwas_PI_RawMemoryAccess_WriteWord_Pi(const asn1SccDestinationAddress*,
                                              const asn1SccWordMask*,
                                              const asn1SccWord*);
    void hwas_PI_RawMemoryAccess_ExclusiveReadWord_Pi(const asn1SccSourceAddress*,
                                                      const asn1SccWordMask*,
                                                      asn1SccWord*);
    bool hwas_PI_RawMemoryAccess_ExclusiveWriteWord_Pi(const asn1SccDestinationAddress*,
                                                       const asn1SccWordMask*,
                                                       const asn1SccWord*);

    /* Required interfaces */
    extern void hwas_RI_InterruptSubscription_Interrupt_Ri(const asn1SccInterrupt_Type*);

#ifdef __cplusplus
}
#endif
