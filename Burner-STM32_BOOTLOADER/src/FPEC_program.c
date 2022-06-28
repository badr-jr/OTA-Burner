/*
 * FPEC_program.c
 *
 *  Created on: Jun 25, 2022
 *      Author: badrm
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "FPEC_interface.h"
#include "FPEC_private.h"



void MFPEC_voidErasePage(u8 Copy_u8PageNum)
{
	/* Check if flash operation is in progress and wait */
	while (GET_BIT(FPEC->SR,0) == 1);
	/* check if FPEC and FLASH_CR register is locked */
	if ( GET_BIT(FPEC->CR,7) == 1)
		{
			/* Unlock flash memory and FLASH_CR register using 2 keys */
			FPEC ->KEYR = 0x45670123;
			FPEC ->KEYR = 0xCDEF89AB;
		}
	/* Erase page chosen */
	SET_BIT(FPEC->CR,1);
	/* Indicate address of page to be erased */
	FPEC->AR = (u32)(Copy_u8PageNum * 1024)+0x08000000;
	/* start erase operation */
	SET_BIT(FPEC->CR,6);
	/* Check if flash operation is in progress and wait */
	while (GET_BIT(FPEC->SR,0) == 1);
	/* end of operation */
	SET_BIT(FPEC->SR,5);
	CLR_BIT(FPEC->CR,1);
}


void MFPEC_voidEraseApplicationSection()
{
	u8 i;
	for(i=4 ; i<64 ; i++)
	{
		MFPEC_voidErasePage(i);
	}
}

void MFPEC_voidFlashRecord(u32 Copy_u32RecordAddress, u16* Copy_u16RecordData, u8 Copy_u8RecordLength)
{
	u8 i;
	/* Check if flash operation is in progress and wait */
	while (GET_BIT(FPEC->SR,0) == 1);
	/* check if FPEC and FLASH_CR register is locked */
	if ( GET_BIT(FPEC->CR,7) == 1)
		{
			/* Unlock flash memory and FLASH_CR register using 2 keys */
			FPEC ->KEYR = 0x45670123;
			FPEC ->KEYR = 0xCDEF89AB;
		}
	for(i=0 ; i< Copy_u8RecordLength ; i++)
	{
		/* Flash programming chosen */
		SET_BIT(FPEC->CR,0);
		/* Here we follow half word writing operation so we write 2 locations in single time */
		*((volatile u16*)Copy_u32RecordAddress) = Copy_u16RecordData[i];
		Copy_u32RecordAddress += 2 ;
		/* Check if flash operation is in progress and wait */
		while (GET_BIT(FPEC->SR,0) == 1);
		/* end of operation */
		SET_BIT(FPEC->SR,5);
		CLR_BIT(FPEC->CR,0);
	}
}
