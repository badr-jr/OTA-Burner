/*
 * FPEC_parser.c
 *
 *  Created on: Jun 25, 2022
 *      Author: badrm
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FPEC_interface.h"
u16 Data[100] = {0};
u32 Address= 0x08000000;


u8 AsciToHex(u8 Copy_u8Asci)
{
	u8 Result;
	/* convert string number to integer number */
	if ( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		Result = Copy_u8Asci - 48;
	}
	/* convert hex characters to hex integers */
	else
	{
		Result = Copy_u8Asci - 55;
	}

	return Result;
}
void ParseData(u8* Copy_u8RecordFrame)
{
	u8 CountLow,CountHigh,CC,i;
	u8 Digit0,Digit1,Digit2,Digit3;
	u8 DataCounter = 0;

	/* Get Character Count (number of bytes in data part) */
	CountHigh = AsciToHex (Copy_u8RecordFrame[1]);
	CountLow  = AsciToHex (Copy_u8RecordFrame[2]);
	CC = (CountHigh<<4) | CountLow;

	/* Get Address */

	Digit0 = AsciToHex (Copy_u8RecordFrame[3]);
	Digit1 = AsciToHex (Copy_u8RecordFrame[4]);
	Digit2 = AsciToHex (Copy_u8RecordFrame[5]);
	Digit3 = AsciToHex (Copy_u8RecordFrame[6]);

	/* Clear Low Part of Address */
	Address = Address & 0xFFFF0000;
	Address = Address | (Digit3) | (Digit2 << 4) | (Digit1 << 8) | (Digit0<<12);

	for (i=0;i<CC/2; i++)
	{
		Digit0 = AsciToHex (Copy_u8RecordFrame[4*i+9]);
		Digit1 = AsciToHex (Copy_u8RecordFrame[4*i+10]);
		Digit2 = AsciToHex (Copy_u8RecordFrame[4*i+11]);
		Digit3 = AsciToHex (Copy_u8RecordFrame[4*i+12]);

		Data[DataCounter] = (Digit3 << 8) | (Digit2 << 12) | (Digit1) | (Digit0 << 4);
		DataCounter++;
	}

	MFPEC_voidFlashRecord(Address,Data,CC/2);
}

void MFPEC_voidParseHighAdress(u8* Copy_u8RecordFrame)
{
 	// /* Get address in hex form and convert it from string to numbers */
	//u8 AddressDigit0,AddressDigit1,AddressDigit2,AddressDigit3;
	//AddressDigit0 = AsciToHex (Copy_u8RecordFrame[9]);
	//AddressDigit1 = AsciToHex (Copy_u8RecordFrame[10]);
	//AddressDigit2 = AsciToHex (Copy_u8RecordFrame[11]);
	//AddressDigit3 = AsciToHex (Copy_u8RecordFrame[12]);
	/* Clear High Part of Address */
	//Address = Address & (u32)0x0000FFFF;
	/* Set high part of address */
	//Address = Address | (u32)((u32)(AddressDigit0 << 28) | (u32)(AddressDigit1 << 24) | (u32)(AddressDigit2 << 20) | (u32)(AddressDigit3 << 16));
}
/* check if this is a command record or data record */
void MFPEC_voidParseRecord(u8* Copy_u8RecordFrame)
{
	switch (Copy_u8RecordFrame[8])
	{
	/* data record */
	case '0': ParseData(Copy_u8RecordFrame); break;
	/* command record */
	case '4': MFPEC_voidParseHighAdress(Copy_u8RecordFrame); break;
	}
}
