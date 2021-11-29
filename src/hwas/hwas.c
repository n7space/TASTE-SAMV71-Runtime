/* Body file for function HWAS
 * Generated by TASTE on 2021-11-29 11:46:27
 * You can edit this file, it will not be overwritten
 * Provided interfaces : InterruptManagement_DisableInterrupt_Pi, InterruptManagement_EnableInterrupt_Pi,
 * InterruptSubscriptionManagement_SubscribeToInterrupt_Pi, RawMemoryAccess_ReadBuffer_Pi, RawMemoryAccess_ReadWord_Pi,
 * RawMemoryAccess_WriteBuffer_Pi, RawMemoryAccess_WriteWord_Pi Required interfaces : InterruptSubscription_Interrupt_Ri
 * User-defined properties for this function:
 *   |_ TASTE::Is_Component_Type = false
 * Timers              :
 */

#include "hwas.h"
//#include <stdio.h>

void
hwas_startup(void)
{
    // Write your initialisation code, but DO NOT CALL REQUIRED INTERFACES
    // puts ("[HWAS] Startup");
}

void
hwas_PI_InterruptManagement_DisableInterrupt_Pi(const asn1SccInterruptNumber* IN_interrupt)

{
    // Write your code here
}
void
hwas_PI_InterruptManagement_EnableInterrupt_Pi(const asn1SccInterruptNumber* IN_interrupt)

{
    // Write your code here
}
void
hwas_PI_InterruptSubscriptionManagement_SubscribeToInterrupt_Pi(const asn1SccInterruptNumber* IN_interrupt)

{
    // Write your code here
}
void
hwas_PI_RawMemoryAccess_ReadBuffer_Pi(const asn1SccSourceAddress* IN_address, asn1SccByteBuffer* OUT_buffer)

{
    // Write your code here
}
void
hwas_PI_RawMemoryAccess_ReadWord_Pi(const asn1SccSourceAddress* IN_address,
                                    const asn1SccWordMask* IN_mask,
                                    asn1SccWord* OUT_value)

{
    // Write your code here
}
void
hwas_PI_RawMemoryAccess_WriteBuffer_Pi(const asn1SccDestinationAddress* IN_address, const asn1SccByteBuffer* IN_buffer)

{
    // Write your code here
}
void
hwas_PI_RawMemoryAccess_WriteWord_Pi(const asn1SccDestinationAddress* IN_address,
                                     const asn1SccWordMask* IN_mask,
                                     const asn1SccWord* IN_value)

{
    // Write your code here
}
