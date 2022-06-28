/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 20 May 2022									  */
/* Version 			: V01											  */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
void (*MSTK_Callback) (void);
static u8 MSTK_u8IntervalMode;
void MSTK_voidInit(void)
{
	/* Disable SysTick peripheral */
	CLR_BIT(STK_CTRL , 0);
	/* Disable Interrupt for SysTick */
	CLR_BIT(STK_CTRL , 1);
	/* SET Clock on SysTick peripheral to AHB or AHB/8 (1,0) */
	switch (SYSTICK_CLOCK)
	{
		case AHB_DIV_8: CLR_BIT(STK_CTRL , 2);		break;
		case AHB: 		SET_BIT(STK_CTRL , 2);		break;
	}
}

void MSTK_voidStopInterval(void)
{	
	/* Disable SysTick peripheral */
	CLR_BIT(STK_CTRL , 0);
	/* Disable Interrupt for SysTick */
	CLR_BIT(STK_CTRL , 1);
	/* Stop Counting */
	STK_LOAD = 0;
	STK_VAL = 0;
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	/* Fill Load register with ticks count */
	STK_LOAD = Copy_u32Ticks;
	/* Enable SysTick peripheral */
	SET_BIT(STK_CTRL , 0);
	/* Delay for ticks count */
	while(GET_BIT(STK_CTRL , 16) == 0){}
	/* Stop Timer */
	MSTK_voidStopInterval();
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_Ptr) (void))
{
	/* Reset Timer */
	CLR_BIT(STK_CTRL,0);
	STK_VAL = 0;
	/* Fill Load register with ticks count */
	STK_LOAD = Copy_u32Ticks;
	/* Enable SysTick peripheral */
	SET_BIT(STK_CTRL , 0);
	/* Setting callback function to function we want execute after single interval */
	MSTK_Callback = Copy_Ptr;
	/* Enable SysTick interrupt peripheral */
	SET_BIT(STK_CTRL , 1);
	/* Determine single interval needed */
	MSTK_u8IntervalMode = Single;
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_Ptr) (void))
{
	/* Fill Load register with ticks count */
	STK_LOAD = Copy_u32Ticks;
	/* Enable SysTick peripheral */
	SET_BIT(STK_CTRL , 0);
	/* Setting callback function to function we want execute after single interval */
	MSTK_Callback = Copy_Ptr;
	/* Enable SysTick interrupt peripheral */
	SET_BIT(STK_CTRL , 1);
	/* Determine single interval needed */
	MSTK_u8IntervalMode = Periodic;
}



void SysTick_Handler(void)
{ 
	u8 Local_u8Temp;
	/* Execute callback function */
	MSTK_Callback();
	/* Stop periodic SysTick if single is determined */
	if(MSTK_u8IntervalMode == Single)
	{
		MSTK_voidStopInterval();
	}
	/* Clear interrupt flag */
	Local_u8Temp = GET_BIT(STK_CTRL , 16);
}

u32 MSTK_u32GetRemainingTicks(void)
{
	u32 Local_u32Remaining;
	Local_u32Remaining = STK_VAL;
	return Local_u32Remaining;
}

u32 MSTK_u32GetElapsedTicks(void)
{
	u32 Local_u32Elapsed;
	Local_u32Elapsed = STK_LOAD - STK_VAL;
	return Local_u32Elapsed;
}
