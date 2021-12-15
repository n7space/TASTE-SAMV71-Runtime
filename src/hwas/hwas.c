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

#include <Nvic/Nvic.h>

#include <string.h>
#include <assert.h>

#include <FreeRTOS.h>
#include <queue.h>
#include <task.h>

static volatile bool interruptSubscribe[Nvic_InterruptCount] = { 0 };

#define HWAS_INTERRUPT_QUEUE_SIZE 100
#define HWAS_INTERRUPT_QUEUE_ITEM_SIZE (sizeof(asn1SccInterrupt_Type))
#define HWAS_INTERRUPT_STACK_SIZE 100
#define HWAS_INTERRUPT_PRIORITY 1

#define PERIPH_INTERRUPT_PRIORITY 2

__attribute__((section(".sdramMemorySection"))) static volatile QueueHandle_t hwasInterruptQueueHandle;

__attribute__((section(".sdramMemorySection"))) static uint8_t
        hwasInterruptQueueStorageBuffer[HWAS_INTERRUPT_QUEUE_SIZE * HWAS_INTERRUPT_QUEUE_ITEM_SIZE];

__attribute__((section(".sdramMemorySection"))) static StaticQueue_t hwasInterruptQueueBuffer;
__attribute__((section(".sdramMemorySection"))) static StackType_t hwasStackBuffer[HWAS_INTERRUPT_STACK_SIZE];
__attribute__((section(".sdramMemorySection"))) static StaticTask_t hwasTaskBuffer;

void
PIOA_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioA]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioA };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
PIOB_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioB]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioB };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
PIOC_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioC]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioC };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
PIOD_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioD]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioD };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
PIOE_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_PioE]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_PioE };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
ISI_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Isi]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Isi };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
GMAC_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Gmac]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Gmac };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
SPI0_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Spi0]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Spi0 };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
SPI1_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Spi1]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Spi1 };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
TWIHS0_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Twihs0]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Twihs0 };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
TWIHS1_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Twihs1]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Twihs1 };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
TWIHS2_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Twihs2]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Twihs2 };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
MCAN0_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Mcan0_Irq0]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Mcan0_Irq0 };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
    if(interruptSubscribe[Nvic_Irq_Mcan0_Irq1]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Mcan0_Irq1 };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
MCAN1_Handler(void)
{
    if(interruptSubscribe[Nvic_Irq_Mcan1_Irq0]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Mcan1_Irq0 };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
    if(interruptSubscribe[Nvic_Irq_Mcan1_Irq1]) {
        asn1SccInterrupt_Type irq = { .interrupt = Nvic_Irq_Mcan1_Irq1 };
        hwas_RI_InterruptSubscription_Interrupt_Ri(&irq);
    }
}

void
HwasInterruptHandlerTask(void* args)
{
    (void)args;
    while(1) {
        asn1SccInterrupt_Type value;
        if(xQueueReceive(hwasInterruptQueueHandle, &value, portMAX_DELAY) == pdTRUE) {
            hwas_RI_InterruptSubscription_Interrupt_Ri(&value);
        } else {
            assert(false && "Error while reading the queue");
            break;
        }
    }
}

void
hwas_startup(void)
{
    memset((void*)interruptSubscribe, 0, Nvic_InterruptCount);
    hwasInterruptQueueHandle = xQueueCreateStatic(HWAS_INTERRUPT_QUEUE_SIZE,
                                                  HWAS_INTERRUPT_QUEUE_ITEM_SIZE,
                                                  hwasInterruptQueueStorageBuffer,
                                                  &hwasInterruptQueueBuffer);
    assert(hwasInterruptQueueHandle != NULL);
    assert(xTaskCreateStatic(HwasInterruptHandlerTask,
                             "HwasInterruptHandlerTask",
                             HWAS_INTERRUPT_STACK_SIZE,
                             NULL,
                             HWAS_INTERRUPT_PRIORITY,
                             hwasStackBuffer,
                             &hwasTaskBuffer)
           != NULL);
}

void
hwas_PI_InterruptManagement_DisableInterrupt_Pi(const asn1SccInterruptNumber* IN_interrupt)
{
    Nvic_disableInterrupt((Nvic_Irq)*IN_interrupt);
}

void
hwas_PI_InterruptManagement_EnableInterrupt_Pi(const asn1SccInterruptNumber* IN_interrupt)
{
    Nvic_setInterruptPriority((Nvic_Irq)*IN_interrupt, PERIPH_INTERRUPT_PRIORITY);
    Nvic_enableInterrupt((Nvic_Irq)*IN_interrupt);
}

void
hwas_PI_InterruptSubscriptionManagement_SubscribeToInterrupt_Pi(const asn1SccInterruptNumber* IN_interrupt)
{
    interruptSubscribe[*IN_interrupt] = true;
}

void
hwas_PI_RawMemoryAccess_ReadBuffer_Pi(const asn1SccSourceAddress* IN_address, asn1SccByteBuffer* OUT_buffer)
{
    uint32_t* address = (uint32_t*)((uint32_t)*IN_address);
    for(int i = 0; i < OUT_buffer->nCount; i++) {
        OUT_buffer->arr[i] = *address;
        address++;
    }
}

void
hwas_PI_RawMemoryAccess_ReadWord_Pi(const asn1SccSourceAddress* IN_address,
                                    const asn1SccWordMask* IN_mask,
                                    asn1SccWord* OUT_value)
{
    uint32_t* address = (uint32_t*)((uint32_t)*IN_address);
    uint32_t maskValue = (uint32_t)*IN_mask;
    uint32_t* addressOut = (uint32_t*)OUT_value;
    *addressOut = maskValue & *address;
}

void
hwas_PI_RawMemoryAccess_WriteBuffer_Pi(const asn1SccDestinationAddress* IN_address, const asn1SccByteBuffer* IN_buffer)
{
    uint32_t* address = (uint32_t*)((uint32_t)*IN_address);
    for(int i = 0; i < IN_buffer->nCount; i++) {
        *address = (uint32_t)IN_buffer->arr[i];
        address++;
    }
}

void
hwas_PI_RawMemoryAccess_WriteWord_Pi(const asn1SccDestinationAddress* IN_address,
                                     const asn1SccWordMask* IN_mask,
                                     const asn1SccWord* IN_value)
{
    uint32_t* address = (uint32_t*)((uint32_t)*IN_address);
    uint32_t regValue = (uint32_t)*address;
    uint32_t mask = (uint32_t)*IN_mask;
    uint32_t valueToSet = (uint32_t)*IN_value;
    regValue &= ~(mask);
    regValue |= (mask & valueToSet);

    *address = regValue;
}
