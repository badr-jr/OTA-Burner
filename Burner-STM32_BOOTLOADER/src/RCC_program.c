/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 16 May 2022									  */
/* Version 			: V01											  */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
	#if 	RCC_CLOCK_TYPE	==	RCC_HSE_CRYSTAL
		RCC_CR   = 0x00010000;	/* HSE Crystal Enabled (With no bypass) */
		RCC_CFGR = 0x00000001;	/* HSE Now Is Enabled On Clock 			*/
	#elif 	RCC_CLOCK_TYPE	==	RCC_HSE_RC
		RCC_CR 	 = 0x00050000;	/* HSE RC Enabled (With bypass) */
		RCC_CFGR = 0x00000001;	/* HSE Now Is Enabled On Clock 	*/
	#elif 	RCC_CLOCK_TYPE	==	RCC_HSI
		RCC_CR 	 = 0x00000081;	/* HSI Enabled (Trimming value preserved) */
		RCC_CFGR = 0x00000000;	/* HSI Now Is Enabled On Clock 			  */
		
	#elif 	RCC_CLOCK_TYPE	==	RCC_PLL
		#if RCC_PLL_INPUTE  ==	RCC_PLL_IN_HSI_DIV_2

		#elif RCC_PLL_INPUTE  ==	RCC_PLL_IN_HSE_DIV_2

		#elif RCC_PLL_INPUTE  ==	RCC_PLL_IN_HSE

		#endif
	#else
		#error ("You Choosed Wrong Clock Type")
	#endif
	
}

void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId){
	
	if(copy_u8PerId <= 31)
	{
		switch(copy_u8BusId)
		{
			case RCC_AHB	: SET_BIT(RCC_AHBENR ,  copy_u8PerId);	break;
			case RCC_APB1	: SET_BIT(RCC_APB1ENR , copy_u8PerId);	break;
			case RCC_APB2	: SET_BIT(RCC_APB2ENR , copy_u8PerId);	break;
		}
	}
	else
	{
		/* Error */
	}
	
}

void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_u8PerId){

	if(copy_u8PerId <= 31)
	{
		switch(copy_u8BusId)
		{
			case RCC_AHB	: CLR_BIT(RCC_AHBENR  , copy_u8PerId);	break;
			case RCC_APB1	: CLR_BIT(RCC_APB1ENR , copy_u8PerId);	break;
			case RCC_APB2	: CLR_BIT(RCC_APB2ENR , copy_u8PerId);	break;
		}
	}
	else
	{
		/* Error */
	}

}
