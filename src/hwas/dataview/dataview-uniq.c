/*
Code automatically generated by asn1scc tool
*/
#include <limits.h>
#include <string.h>
#include <math.h>

#include "asn1crt_encoding.h"
#include "asn1crt_encoding_uper.h"
#include "asn1crt_encoding_acn.h"

#include "dataview-uniq.h"



flag asn1SccDestinationAddress_Equal(const asn1SccDestinationAddress* pVal1, const asn1SccDestinationAddress* pVal2)
{
	return (*(pVal1)) == (*(pVal2));

}

void asn1SccDestinationAddress_Initialize(asn1SccDestinationAddress* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}

flag asn1SccDestinationAddress_IsConstraintValid(const asn1SccDestinationAddress* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = ((*(pVal)) <= 4294967295UL);
    *pErrCode = ret ? 0 :  ERR_DESTINATIONADDRESS; 

	return ret;
}

flag asn1SccDestinationAddress_Encode(const asn1SccDestinationAddress* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	*pErrCode = 0;
	ret = bCheckConstraints ? asn1SccDestinationAddress_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 4294967295LL);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccDestinationAddress_Decode(asn1SccDestinationAddress* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : ERR_UPER_DECODE_DESTINATIONADDRESS;

	return ret  && asn1SccDestinationAddress_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccDestinationAddress_ACN_Encode(const asn1SccDestinationAddress* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    *pErrCode = 0;
	ret = bCheckConstraints ? asn1SccDestinationAddress_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 4294967295LL);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccDestinationAddress_ACN_Decode(asn1SccDestinationAddress* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_DESTINATIONADDRESS;

    return ret && asn1SccDestinationAddress_IsConstraintValid(pVal, pErrCode);
}



flag asn1SccSourceAddress_Equal(const asn1SccSourceAddress* pVal1, const asn1SccSourceAddress* pVal2)
{
	return (*(pVal1)) == (*(pVal2));

}

void asn1SccSourceAddress_Initialize(asn1SccSourceAddress* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}

flag asn1SccSourceAddress_IsConstraintValid(const asn1SccSourceAddress* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = ((*(pVal)) <= 4294967295UL);
    *pErrCode = ret ? 0 :  ERR_SOURCEADDRESS; 

	return ret;
}

flag asn1SccSourceAddress_Encode(const asn1SccSourceAddress* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	*pErrCode = 0;
	ret = bCheckConstraints ? asn1SccSourceAddress_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 4294967295LL);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccSourceAddress_Decode(asn1SccSourceAddress* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : ERR_UPER_DECODE_SOURCEADDRESS;

	return ret  && asn1SccSourceAddress_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccSourceAddress_ACN_Encode(const asn1SccSourceAddress* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    *pErrCode = 0;
	ret = bCheckConstraints ? asn1SccSourceAddress_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 4294967295LL);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccSourceAddress_ACN_Decode(asn1SccSourceAddress* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_SOURCEADDRESS;

    return ret && asn1SccSourceAddress_IsConstraintValid(pVal, pErrCode);
}



flag asn1SccWord_Equal(const asn1SccWord* pVal1, const asn1SccWord* pVal2)
{
	return (*(pVal1)) == (*(pVal2));

}

void asn1SccWord_Initialize(asn1SccWord* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}

flag asn1SccWord_IsConstraintValid(const asn1SccWord* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = ((*(pVal)) <= 4294967295UL);
    *pErrCode = ret ? 0 :  ERR_WORD; 

	return ret;
}

flag asn1SccWord_Encode(const asn1SccWord* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	*pErrCode = 0;
	ret = bCheckConstraints ? asn1SccWord_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 4294967295LL);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccWord_Decode(asn1SccWord* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : ERR_UPER_DECODE_WORD;

	return ret  && asn1SccWord_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccWord_ACN_Encode(const asn1SccWord* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    *pErrCode = 0;
	ret = bCheckConstraints ? asn1SccWord_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 4294967295LL);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccWord_ACN_Decode(asn1SccWord* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_WORD;

    return ret && asn1SccWord_IsConstraintValid(pVal, pErrCode);
}



flag asn1SccWordMask_Equal(const asn1SccWordMask* pVal1, const asn1SccWordMask* pVal2)
{
	return (*(pVal1)) == (*(pVal2));

}

void asn1SccWordMask_Initialize(asn1SccWordMask* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}

flag asn1SccWordMask_IsConstraintValid(const asn1SccWordMask* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = ((*(pVal)) <= 4294967295UL);
    *pErrCode = ret ? 0 :  ERR_WORDMASK; 

	return ret;
}

flag asn1SccWordMask_Encode(const asn1SccWordMask* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	*pErrCode = 0;
	ret = bCheckConstraints ? asn1SccWordMask_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 4294967295LL);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccWordMask_Decode(asn1SccWordMask* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : ERR_UPER_DECODE_WORDMASK;

	return ret  && asn1SccWordMask_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccWordMask_ACN_Encode(const asn1SccWordMask* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    *pErrCode = 0;
	ret = bCheckConstraints ? asn1SccWordMask_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 4294967295LL);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccWordMask_ACN_Decode(asn1SccWordMask* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 4294967295LL);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_WORDMASK;

    return ret && asn1SccWordMask_IsConstraintValid(pVal, pErrCode);
}



flag asn1SccBufferSize_Equal(const asn1SccBufferSize* pVal1, const asn1SccBufferSize* pVal2)
{
	return (*(pVal1)) == (*(pVal2));

}

void asn1SccBufferSize_Initialize(asn1SccBufferSize* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}

flag asn1SccBufferSize_IsConstraintValid(const asn1SccBufferSize* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = ((*(pVal)) <= 65535UL);
    *pErrCode = ret ? 0 :  ERR_BUFFERSIZE; 

	return ret;
}

flag asn1SccBufferSize_Encode(const asn1SccBufferSize* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	*pErrCode = 0;
	ret = bCheckConstraints ? asn1SccBufferSize_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 65535);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccBufferSize_Decode(asn1SccBufferSize* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 65535);
	*pErrCode = ret ? 0 : ERR_UPER_DECODE_BUFFERSIZE;

	return ret  && asn1SccBufferSize_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccBufferSize_ACN_Encode(const asn1SccBufferSize* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    *pErrCode = 0;
	ret = bCheckConstraints ? asn1SccBufferSize_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 65535);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccBufferSize_ACN_Decode(asn1SccBufferSize* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 65535);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_BUFFERSIZE;

    return ret && asn1SccBufferSize_IsConstraintValid(pVal, pErrCode);
}



flag asn1SccInterruptNumber_Equal(const asn1SccInterruptNumber* pVal1, const asn1SccInterruptNumber* pVal2)
{
	return (*(pVal1)) == (*(pVal2));

}

void asn1SccInterruptNumber_Initialize(asn1SccInterruptNumber* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}

flag asn1SccInterruptNumber_IsConstraintValid(const asn1SccInterruptNumber* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = ((*(pVal)) <= 255UL);
    *pErrCode = ret ? 0 :  ERR_INTERRUPTNUMBER; 

	return ret;
}

flag asn1SccInterruptNumber_Encode(const asn1SccInterruptNumber* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	*pErrCode = 0;
	ret = bCheckConstraints ? asn1SccInterruptNumber_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 255);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccInterruptNumber_Decode(asn1SccInterruptNumber* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 255);
	*pErrCode = ret ? 0 : ERR_UPER_DECODE_INTERRUPTNUMBER;

	return ret  && asn1SccInterruptNumber_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccInterruptNumber_ACN_Encode(const asn1SccInterruptNumber* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    *pErrCode = 0;
	ret = bCheckConstraints ? asn1SccInterruptNumber_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 255);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccInterruptNumber_ACN_Decode(asn1SccInterruptNumber* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 255);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_INTERRUPTNUMBER;

    return ret && asn1SccInterruptNumber_IsConstraintValid(pVal, pErrCode);
}



flag asn1SccInterrupt_Type_interrupt_Equal(const asn1SccInterrupt_Type_interrupt* pVal1, const asn1SccInterrupt_Type_interrupt* pVal2)
{
	return (*(pVal1)) == (*(pVal2));

}

flag asn1SccInterrupt_Type_Equal(const asn1SccInterrupt_Type* pVal1, const asn1SccInterrupt_Type* pVal2)
{
	flag ret=TRUE;

    ret = asn1SccInterrupt_Type_interrupt_Equal((&(pVal1->interrupt)), (&(pVal2->interrupt)));

	return ret;

}

void asn1SccInterrupt_Type_interrupt_Initialize(asn1SccInterrupt_Type_interrupt* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}
void asn1SccInterrupt_Type_Initialize(asn1SccInterrupt_Type* pVal)
{
	(void)pVal;



	/*set interrupt */
	asn1SccInterrupt_Type_interrupt_Initialize((&(pVal->interrupt)));
}

flag asn1SccInterrupt_Type_IsConstraintValid(const asn1SccInterrupt_Type* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = (pVal->interrupt <= 255UL);
    if (ret) {
        ret = (pVal->interrupt <= 255UL);
    }
    *pErrCode = ret ? 0 :  ERR_INTERRUPT_TYPE_INTERRUPT; 

	return ret;
}

flag asn1SccInterrupt_Type_Encode(const asn1SccInterrupt_Type* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	*pErrCode = 0;
	ret = bCheckConstraints ? asn1SccInterrupt_Type_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    /*Encode interrupt */
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->interrupt, 0, 255);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccInterrupt_Type_Decode(asn1SccInterrupt_Type* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode interrupt */
	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->interrupt)), 0, 255);
	*pErrCode = ret ? 0 : ERR_UPER_DECODE_INTERRUPT_TYPE_INTERRUPT;

	return ret  && asn1SccInterrupt_Type_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccInterrupt_Type_ACN_Encode(const asn1SccInterrupt_Type* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    *pErrCode = 0;
	ret = bCheckConstraints ? asn1SccInterrupt_Type_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    /*Encode interrupt */
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->interrupt, 0, 255);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccInterrupt_Type_ACN_Decode(asn1SccInterrupt_Type* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	/*Decode interrupt */
	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->interrupt)), 0, 255);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_INTERRUPT_TYPE_INTERRUPT;

    return ret && asn1SccInterrupt_Type_IsConstraintValid(pVal, pErrCode);
}



flag asn1SccByte_Equal(const asn1SccByte* pVal1, const asn1SccByte* pVal2)
{
	return (*(pVal1)) == (*(pVal2));

}

void asn1SccByte_Initialize(asn1SccByte* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}

flag asn1SccByte_IsConstraintValid(const asn1SccByte* pVal, int* pErrCode)
{
    flag ret = TRUE;
    ret = ((*(pVal)) <= 255UL);
    *pErrCode = ret ? 0 :  ERR_BYTE; 

	return ret;
}

flag asn1SccByte_Encode(const asn1SccByte* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	*pErrCode = 0;
	ret = bCheckConstraints ? asn1SccByte_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 255);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccByte_Decode(asn1SccByte* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 255);
	*pErrCode = ret ? 0 : ERR_UPER_DECODE_BYTE;

	return ret  && asn1SccByte_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccByte_ACN_Encode(const asn1SccByte* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

    *pErrCode = 0;
	ret = bCheckConstraints ? asn1SccByte_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintPosWholeNumber(pBitStrm, (*(pVal)), 0, 255);
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccByte_ACN_Decode(asn1SccByte* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;


	ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, pVal, 0, 255);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_BYTE;

    return ret && asn1SccByte_IsConstraintValid(pVal, pErrCode);
}



flag asn1SccByteBuffer_elem_Equal(const asn1SccByteBuffer_elem* pVal1, const asn1SccByteBuffer_elem* pVal2)
{
	return (*(pVal1)) == (*(pVal2));

}

flag asn1SccByteBuffer_Equal(const asn1SccByteBuffer* pVal1, const asn1SccByteBuffer* pVal2)
{
	flag ret=TRUE;
    int i1;

    ret = (pVal1->nCount == pVal2->nCount);
    for(i1 = 0; ret && i1 < pVal1->nCount; i1++) 
    {
    	ret = asn1SccByteBuffer_elem_Equal((&(pVal1->arr[i1])), (&(pVal2->arr[i1])));
    }

	return ret;

}

void asn1SccByteBuffer_elem_Initialize(asn1SccByteBuffer_elem* pVal)
{
	(void)pVal;


	(*(pVal)) = 0;
}
void asn1SccByteBuffer_Initialize(asn1SccByteBuffer* pVal)
{
	(void)pVal;

    int i1;

	i1 = 0;
	while (i1< 65535) {
	    asn1SccByteBuffer_elem_Initialize((&(pVal->arr[i1])));
	    i1 = i1 + 1;
	}
	pVal->nCount = 0;
}

flag asn1SccByteBuffer_IsConstraintValid(const asn1SccByteBuffer* pVal, int* pErrCode)
{
    flag ret = TRUE;
    int i1;
    ret = (pVal->nCount <= 65535);
    *pErrCode = ret ? 0 :  ERR_BYTEBUFFER; 
    if (ret) {
        for(i1 = 0; ret && i1 < pVal->nCount; i1++) 
        {
        	ret = (pVal->arr[i1] <= 255UL);
        	if (ret) {
        	    ret = (pVal->arr[i1] <= 255UL);
        	}
        	*pErrCode = ret ? 0 :  ERR_BYTEBUFFER_ELM; 
        }
    }

	return ret;
}

flag asn1SccByteBuffer_Encode(const asn1SccByteBuffer* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;


	int i1;
	*pErrCode = 0;
	ret = bCheckConstraints ? asn1SccByteBuffer_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 0, 65535);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->arr[i1], 0, 255);
	    }
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccByteBuffer_Decode(asn1SccByteBuffer* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;

	int i1;
	asn1SccSint nCount;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 0, 65535);
	*pErrCode = ret ? 0 : ERR_UPER_DECODE_BYTEBUFFER;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->arr[i1])), 0, 255);
		*pErrCode = ret ? 0 : ERR_UPER_DECODE_BYTEBUFFER_ELM;
	}

	return ret  && asn1SccByteBuffer_IsConstraintValid(pVal, pErrCode);
}

flag asn1SccByteBuffer_ACN_Encode(const asn1SccByteBuffer* pVal, BitStream* pBitStrm, int* pErrCode, flag bCheckConstraints)
{
    flag ret = TRUE;

	int i1;
    *pErrCode = 0;
	ret = bCheckConstraints ? asn1SccByteBuffer_IsConstraintValid(pVal, pErrCode) : TRUE ;
	if (ret && *pErrCode == 0) {
	    BitStream_EncodeConstraintWholeNumber(pBitStrm, pVal->nCount, 0, 65535);
	    	
	    for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	    {
	    	BitStream_EncodeConstraintPosWholeNumber(pBitStrm, pVal->arr[i1], 0, 255);
	    }
    } /*COVERAGE_IGNORE*/

	
    return ret;
}

flag asn1SccByteBuffer_ACN_Decode(asn1SccByteBuffer* pVal, BitStream* pBitStrm, int* pErrCode)
{
    flag ret = TRUE;
	*pErrCode = 0;

	int i1;
	asn1SccSint nCount;

	ret = BitStream_DecodeConstraintWholeNumber(pBitStrm, &nCount, 0, 65535);
	*pErrCode = ret ? 0 : ERR_ACN_DECODE_BYTEBUFFER;
	pVal->nCount = (long)nCount;
		
	for(i1=0; (i1 < (int)pVal->nCount) && ret; i1++) 
	{
		ret = BitStream_DecodeConstraintPosWholeNumber(pBitStrm, (&(pVal->arr[i1])), 0, 255);
		*pErrCode = ret ? 0 : ERR_ACN_DECODE_BYTEBUFFER_ELM;
	}

    return ret && asn1SccByteBuffer_IsConstraintValid(pVal, pErrCode);
}

