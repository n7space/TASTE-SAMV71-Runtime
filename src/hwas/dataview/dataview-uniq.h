#ifndef GENERATED_ASN1SCC_dataview_uniq_H
#define GENERATED_ASN1SCC_dataview_uniq_H
/*
Code automatically generated by asn1scc tool
*/
#include "asn1crt.h"
#include "asn1crt_encoding.h"


#ifdef  __cplusplus
extern "C" {
#endif


typedef asn1SccUint asn1SccDestinationAddress;


flag asn1SccDestinationAddress_Equal(const asn1SccDestinationAddress* pVal1, const asn1SccDestinationAddress* pVal2);

void asn1SccDestinationAddress_Initialize(asn1SccDestinationAddress* pVal);

#define ERR_DESTINATIONADDRESS		1  /**/
flag asn1SccDestinationAddress_IsConstraintValid(const asn1SccDestinationAddress* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_DESTINATIONADDRESS		2  /**/
#define asn1SccDestinationAddress_REQUIRED_BYTES_FOR_ENCODING       4 
#define asn1SccDestinationAddress_REQUIRED_BITS_FOR_ENCODING        32

flag asn1SccDestinationAddress_Encode(const asn1SccDestinationAddress* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_DESTINATIONADDRESS		3  /**/
flag asn1SccDestinationAddress_Decode(asn1SccDestinationAddress* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_DESTINATIONADDRESS		4  /**/
#define asn1SccDestinationAddress_REQUIRED_BYTES_FOR_ACN_ENCODING       4 
#define asn1SccDestinationAddress_REQUIRED_BITS_FOR_ACN_ENCODING        32

flag asn1SccDestinationAddress_ACN_Encode(const asn1SccDestinationAddress* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_DESTINATIONADDRESS		5  /**/
flag asn1SccDestinationAddress_ACN_Decode(asn1SccDestinationAddress* pVal, BitStream* pBitStrm, int* pErrCode);
typedef asn1SccUint asn1SccSourceAddress;


flag asn1SccSourceAddress_Equal(const asn1SccSourceAddress* pVal1, const asn1SccSourceAddress* pVal2);

void asn1SccSourceAddress_Initialize(asn1SccSourceAddress* pVal);

#define ERR_SOURCEADDRESS		6  /**/
flag asn1SccSourceAddress_IsConstraintValid(const asn1SccSourceAddress* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_SOURCEADDRESS		7  /**/
#define asn1SccSourceAddress_REQUIRED_BYTES_FOR_ENCODING       4 
#define asn1SccSourceAddress_REQUIRED_BITS_FOR_ENCODING        32

flag asn1SccSourceAddress_Encode(const asn1SccSourceAddress* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_SOURCEADDRESS		8  /**/
flag asn1SccSourceAddress_Decode(asn1SccSourceAddress* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_SOURCEADDRESS		9  /**/
#define asn1SccSourceAddress_REQUIRED_BYTES_FOR_ACN_ENCODING       4 
#define asn1SccSourceAddress_REQUIRED_BITS_FOR_ACN_ENCODING        32

flag asn1SccSourceAddress_ACN_Encode(const asn1SccSourceAddress* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_SOURCEADDRESS		10  /**/
flag asn1SccSourceAddress_ACN_Decode(asn1SccSourceAddress* pVal, BitStream* pBitStrm, int* pErrCode);
typedef asn1SccUint asn1SccWord;


flag asn1SccWord_Equal(const asn1SccWord* pVal1, const asn1SccWord* pVal2);

void asn1SccWord_Initialize(asn1SccWord* pVal);

#define ERR_WORD		11  /**/
flag asn1SccWord_IsConstraintValid(const asn1SccWord* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_WORD		12  /**/
#define asn1SccWord_REQUIRED_BYTES_FOR_ENCODING       4 
#define asn1SccWord_REQUIRED_BITS_FOR_ENCODING        32

flag asn1SccWord_Encode(const asn1SccWord* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_WORD		13  /**/
flag asn1SccWord_Decode(asn1SccWord* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_WORD		14  /**/
#define asn1SccWord_REQUIRED_BYTES_FOR_ACN_ENCODING       4 
#define asn1SccWord_REQUIRED_BITS_FOR_ACN_ENCODING        32

flag asn1SccWord_ACN_Encode(const asn1SccWord* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_WORD		15  /**/
flag asn1SccWord_ACN_Decode(asn1SccWord* pVal, BitStream* pBitStrm, int* pErrCode);
typedef asn1SccUint asn1SccWordMask;


flag asn1SccWordMask_Equal(const asn1SccWordMask* pVal1, const asn1SccWordMask* pVal2);

void asn1SccWordMask_Initialize(asn1SccWordMask* pVal);

#define ERR_WORDMASK		16  /**/
flag asn1SccWordMask_IsConstraintValid(const asn1SccWordMask* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_WORDMASK		17  /**/
#define asn1SccWordMask_REQUIRED_BYTES_FOR_ENCODING       4 
#define asn1SccWordMask_REQUIRED_BITS_FOR_ENCODING        32

flag asn1SccWordMask_Encode(const asn1SccWordMask* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_WORDMASK		18  /**/
flag asn1SccWordMask_Decode(asn1SccWordMask* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_WORDMASK		19  /**/
#define asn1SccWordMask_REQUIRED_BYTES_FOR_ACN_ENCODING       4 
#define asn1SccWordMask_REQUIRED_BITS_FOR_ACN_ENCODING        32

flag asn1SccWordMask_ACN_Encode(const asn1SccWordMask* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_WORDMASK		20  /**/
flag asn1SccWordMask_ACN_Decode(asn1SccWordMask* pVal, BitStream* pBitStrm, int* pErrCode);
typedef asn1SccUint asn1SccBufferSize;


flag asn1SccBufferSize_Equal(const asn1SccBufferSize* pVal1, const asn1SccBufferSize* pVal2);

void asn1SccBufferSize_Initialize(asn1SccBufferSize* pVal);

#define ERR_BUFFERSIZE		21  /**/
flag asn1SccBufferSize_IsConstraintValid(const asn1SccBufferSize* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_BUFFERSIZE		22  /**/
#define asn1SccBufferSize_REQUIRED_BYTES_FOR_ENCODING       2 
#define asn1SccBufferSize_REQUIRED_BITS_FOR_ENCODING        16

flag asn1SccBufferSize_Encode(const asn1SccBufferSize* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_BUFFERSIZE		23  /**/
flag asn1SccBufferSize_Decode(asn1SccBufferSize* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_BUFFERSIZE		24  /**/
#define asn1SccBufferSize_REQUIRED_BYTES_FOR_ACN_ENCODING       2 
#define asn1SccBufferSize_REQUIRED_BITS_FOR_ACN_ENCODING        16

flag asn1SccBufferSize_ACN_Encode(const asn1SccBufferSize* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_BUFFERSIZE		25  /**/
flag asn1SccBufferSize_ACN_Decode(asn1SccBufferSize* pVal, BitStream* pBitStrm, int* pErrCode);
typedef asn1SccUint asn1SccInterruptNumber;


flag asn1SccInterruptNumber_Equal(const asn1SccInterruptNumber* pVal1, const asn1SccInterruptNumber* pVal2);

void asn1SccInterruptNumber_Initialize(asn1SccInterruptNumber* pVal);

#define ERR_INTERRUPTNUMBER		26  /**/
flag asn1SccInterruptNumber_IsConstraintValid(const asn1SccInterruptNumber* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_INTERRUPTNUMBER		27  /**/
#define asn1SccInterruptNumber_REQUIRED_BYTES_FOR_ENCODING       1 
#define asn1SccInterruptNumber_REQUIRED_BITS_FOR_ENCODING        8

flag asn1SccInterruptNumber_Encode(const asn1SccInterruptNumber* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_INTERRUPTNUMBER		28  /**/
flag asn1SccInterruptNumber_Decode(asn1SccInterruptNumber* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_INTERRUPTNUMBER		29  /**/
#define asn1SccInterruptNumber_REQUIRED_BYTES_FOR_ACN_ENCODING       1 
#define asn1SccInterruptNumber_REQUIRED_BITS_FOR_ACN_ENCODING        8

flag asn1SccInterruptNumber_ACN_Encode(const asn1SccInterruptNumber* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_INTERRUPTNUMBER		30  /**/
flag asn1SccInterruptNumber_ACN_Decode(asn1SccInterruptNumber* pVal, BitStream* pBitStrm, int* pErrCode);
/*-- asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type --------------------------------------------*/
typedef asn1SccInterruptNumber asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_interrupt;

typedef struct {
    asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_interrupt interrupt;

} asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type;

flag asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_interrupt_Equal(const asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_interrupt* pVal1, const asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_interrupt* pVal2);

flag asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_Equal(const asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type* pVal1, const asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type* pVal2);

void asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_interrupt_Initialize(asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_interrupt* pVal);
void asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_Initialize(asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type* pVal);

#define ERR_INTERRUPT_TYPE		51  /**/
#define ERR_INTERRUPT_TYPE_INTERRUPT		46  /**/
flag asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_IsConstraintValid(const asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_INTERRUPT_TYPE		52  /**/
#define ERR_UPER_ENCODE_INTERRUPT_TYPE_INTERRUPT		47  /**/
#define asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_REQUIRED_BYTES_FOR_ENCODING       1 
#define asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_REQUIRED_BITS_FOR_ENCODING        8

flag asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_Encode(const asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_INTERRUPT_TYPE		53  /**/
#define ERR_UPER_DECODE_INTERRUPT_TYPE_INTERRUPT		48  /**/
flag asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_Decode(asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_INTERRUPT_TYPE		54  /**/
#define ERR_ACN_ENCODE_INTERRUPT_TYPE_INTERRUPT		49  /**/
#define asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_REQUIRED_BYTES_FOR_ACN_ENCODING       1 
#define asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_REQUIRED_BITS_FOR_ACN_ENCODING        8

flag asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_ACN_Encode(const asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_INTERRUPT_TYPE		55  /**/
#define ERR_ACN_DECODE_INTERRUPT_TYPE_INTERRUPT		50  /**/
flag asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type_ACN_Decode(asn1SccInterruptSubscriptionInterfaceType_Interrupt_Type* pVal, BitStream* pBitStrm, int* pErrCode);
typedef asn1SccUint asn1SccByte;


flag asn1SccByte_Equal(const asn1SccByte* pVal1, const asn1SccByte* pVal2);

void asn1SccByte_Initialize(asn1SccByte* pVal);

#define ERR_BYTE		31  /**/
flag asn1SccByte_IsConstraintValid(const asn1SccByte* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_BYTE		32  /**/
#define asn1SccByte_REQUIRED_BYTES_FOR_ENCODING       1 
#define asn1SccByte_REQUIRED_BITS_FOR_ENCODING        8

flag asn1SccByte_Encode(const asn1SccByte* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_BYTE		33  /**/
flag asn1SccByte_Decode(asn1SccByte* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_BYTE		34  /**/
#define asn1SccByte_REQUIRED_BYTES_FOR_ACN_ENCODING       1 
#define asn1SccByte_REQUIRED_BITS_FOR_ACN_ENCODING        8

flag asn1SccByte_ACN_Encode(const asn1SccByte* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_BYTE		35  /**/
flag asn1SccByte_ACN_Decode(asn1SccByte* pVal, BitStream* pBitStrm, int* pErrCode);

typedef asn1SccByte asn1SccByteBuffer_elem;


typedef struct {
    int nCount; 
    
    asn1SccByteBuffer_elem arr[65535];
} asn1SccByteBuffer;

flag asn1SccByteBuffer_elem_Equal(const asn1SccByteBuffer_elem* pVal1, const asn1SccByteBuffer_elem* pVal2);

flag asn1SccByteBuffer_Equal(const asn1SccByteBuffer* pVal1, const asn1SccByteBuffer* pVal2);

void asn1SccByteBuffer_elem_Initialize(asn1SccByteBuffer_elem* pVal);
void asn1SccByteBuffer_Initialize(asn1SccByteBuffer* pVal);

#define ERR_BYTEBUFFER		41  /**/
#define ERR_BYTEBUFFER_ELM		36  /**/
flag asn1SccByteBuffer_IsConstraintValid(const asn1SccByteBuffer* pVal, int* pErrCode);

#define ERR_UPER_ENCODE_BYTEBUFFER		42  /**/
#define ERR_UPER_ENCODE_BYTEBUFFER_ELM		37  /**/
#define asn1SccByteBuffer_REQUIRED_BYTES_FOR_ENCODING       65537 
#define asn1SccByteBuffer_REQUIRED_BITS_FOR_ENCODING        524296

flag asn1SccByteBuffer_Encode(const asn1SccByteBuffer* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_UPER_DECODE_BYTEBUFFER		43  /**/
#define ERR_UPER_DECODE_BYTEBUFFER_ELM		38  /**/
flag asn1SccByteBuffer_Decode(asn1SccByteBuffer* pVal, BitStream* pBitStrm, int* pErrCode);

#define ERR_ACN_ENCODE_BYTEBUFFER		44  /**/
#define ERR_ACN_ENCODE_BYTEBUFFER_ELM		39  /**/
#define asn1SccByteBuffer_REQUIRED_BYTES_FOR_ACN_ENCODING       65537 
#define asn1SccByteBuffer_REQUIRED_BITS_FOR_ACN_ENCODING        524296

flag asn1SccByteBuffer_ACN_Encode(const asn1SccByteBuffer* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints);

#define ERR_ACN_DECODE_BYTEBUFFER		45  /**/
#define ERR_ACN_DECODE_BYTEBUFFER_ELM		40  /**/
flag asn1SccByteBuffer_ACN_Decode(asn1SccByteBuffer* pVal, BitStream* pBitStrm, int* pErrCode);

 

/* ================= Encoding/Decoding function prototypes =================
 * These functions are placed at the end of the file to make sure all types
 * have been declared first, in case of parameterized ACN encodings
 * ========================================================================= */

 


#ifdef  __cplusplus
}

#endif

#endif
