/*
 * main.c
 *
 *  Created on: Jun 24, 2022
 *      Author: badrm
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "FPEC_interface.h"
#include "PARSER_interface.h"
#include "SYSTICK_interface.h"
#define SCB_VTOR   *((volatile u32*)0xE000ED08)

u8 RecordBuffer[100] = {0};
typedef void (*FunctionPtr)(void);
FunctionPtr JumpAddress = 0;
void JumpToAddress()
{
	SCB_VTOR = 0x08001000;
	JumpAddress = *(FunctionPtr*)(0x08001004);
	JumpAddress();
}
void main()
{
	u8 Local_u8ReceiveState,FrameIndex=0,Local_u8FirstWrite=0,Local_u8SrtartIndicator=1;
	/* Start RCC as HSI */
	RCC_voidInitSysClock();
	/* Enable UART */
	RCC_voidEnableClock(RCC_APB2,14);
	/* Enable GPIOA  */
	RCC_voidEnableClock(RCC_APB2,2);
	/* Enable FPEC   */
	RCC_voidEnableClock(RCC_AHB,4);
	/* TX AFPP */
	MGPIO_voidSetPinDirection(GPIOA,9,OUTPUT_FREQ_2MHZ_AFPP);
	/* RX Input Floating */
	MGPIO_voidSetPinDirection(GPIOA,10,INPUT_FLOATING);
	/* Initialize UART */
	MUSART_voidInit();
	/* Initialize SYSTICK */
	MSTK_voidInit();
	/* if nothing is received then for 30 seconds go to the current existing flashed object file */
	MSTK_voidSetIntervalSingle(30000000, JumpToAddress);
	while(1)
		{
			/* check if it's first time to enter the loop so we acknowledge ESP it's running */
			if(Local_u8SrtartIndicator)
			{
				MUSART_voidTransimit("OK");
				Local_u8SrtartIndicator=0;
			}
			Local_u8ReceiveState = MUSART_u8Receive( &(RecordBuffer[FrameIndex]) );
			/* check if received data */
			if (Local_u8ReceiveState == 1)
			{
				MSTK_voidStopInterval();
				/* end of frame $ */
				if(RecordBuffer[FrameIndex] == '$')
				{
					/* if it's first time erase first 4 pages of flash */
					if (Local_u8FirstWrite == 0)
					{
						MFPEC_voidEraseApplicationSection();
						Local_u8FirstWrite = 1;
					}

					/* Parse */
					MFPEC_voidParseRecord(RecordBuffer);
					MUSART_voidTransimit("OK");
					/* check for end of file if it's reached, jump to new flashed object file */
					if(RecordBuffer[0] == ':' &&RecordBuffer[1] == '0' && RecordBuffer[2] == '0' && RecordBuffer[3] == '0' && RecordBuffer[4] == '0' && RecordBuffer[5] == '0' && RecordBuffer[6] == '0' && RecordBuffer[7] == '0' && RecordBuffer[8] == '1' && RecordBuffer[9] == 'F' && RecordBuffer[10] == 'F')
					{
						JumpToAddress();
					}
					FrameIndex = 0;
				}

				else
				{
					if(RecordBuffer[FrameIndex] != '\r')
						FrameIndex ++ ;
				}
				MSTK_voidSetIntervalSingle(30000000, JumpToAddress);

			}

			else
			{

			}

		}
}
