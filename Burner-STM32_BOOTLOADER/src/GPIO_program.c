/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 17 May 2022									  */
/* Version 			: V01											  */
/**********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"
void MGPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Mode)
{
	switch(copy_u8PORT)
	{
		/* GPIO PORT A */
		case GPIOA:
			if(copy_u8PIN <= 7)
			{	
				/*	Reset Configs */
				GPIOA_CRL &= ~((0b1111) << (copy_u8PIN * 4));
				/*	Set Mode	  */
				GPIOA_CRL |=  ((copy_u8Mode) << (copy_u8PIN * 4));
			}	
			else if(copy_u8PIN <= 15)
			{	
				/*	Reset Configs */
				GPIOA_CRH &= ~((0b1111) << ((copy_u8PIN - 8) * 4));
				/*	Set Mode	  */
				GPIOA_CRH |=  ((copy_u8Mode) << ((copy_u8PIN - 8) * 4));
			}
			break;
		
		/* GPIO PORT B */
		case GPIOB:
			if(copy_u8PIN <= 7)
			{	
				/*	Reset Configs */
				GPIOB_CRL &= ~((0b1111) << (copy_u8PIN * 4));
				/*	Set Mode	  */
				GPIOB_CRL |=  ((copy_u8Mode) << (copy_u8PIN * 4));
			}	
			else if(copy_u8PIN <= 15)
			{	
				/*	Reset Configs */
				GPIOB_CRH &= ~((0b1111) << ((copy_u8PIN - 8) * 4));
				/*	Set Mode	  */
				GPIOB_CRH |=  ((copy_u8Mode) << ((copy_u8PIN - 8) * 4));
			}
		break;
				
		/* GPIO PORT C */		
		case GPIOC:
			if(copy_u8PIN <= 7)
			{	
				/*	Reset Configs */
				GPIOC_CRL &= ~((0b1111) << (copy_u8PIN * 4));
				/*	Set Mode	  */
				GPIOC_CRL |=  ((copy_u8Mode) << (copy_u8PIN * 4));
			}	
			else if(copy_u8PIN <= 15)
			{	
				/*	Reset Configs */
				GPIOC_CRH &= ~((0b1111) << ((copy_u8PIN - 8) * 4));
				/*	Set Mode	  */
				GPIOC_CRH |=  ((copy_u8Mode) << ((copy_u8PIN - 8) * 4));
			}
		break;
	}	
	
}

void MGPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value)
{
	switch(copy_u8PORT)
	{
		case GPIOA:
			if(copy_u8Value == GPIO_HIGH)
			{
				/*	Set Value to High	*/
				SET_BIT(GPIOA_ODR , copy_u8PIN);
			}
			else if(copy_u8Value == GPIO_LOW)
			{
				/*	Set Value to Low	*/
				CLR_BIT(GPIOA_ODR , copy_u8PIN);
			}
		break;
		case GPIOB:
			if(copy_u8Value == GPIO_HIGH)
			{
				/*	Set Value to High	*/
				SET_BIT(GPIOB_ODR , copy_u8PIN);
			}
			else if(copy_u8Value == GPIO_LOW)
			{
				/*	Set Value to Low	*/
				CLR_BIT(GPIOB_ODR , copy_u8PIN);
			}
		break;
		case GPIOC:
			if(copy_u8Value == GPIO_HIGH)
			{
				/*	Set Value to High	*/
				SET_BIT(GPIOC_ODR , copy_u8PIN);
			}
			else if(copy_u8Value == GPIO_LOW)
			{
				/*	Set Value to Low	*/
				CLR_BIT(GPIOC_ODR , copy_u8PIN);
			}
		break;
	}
	
}

u8 MGPIO_u8GetPinValue(u8 copy_u8PORT , u8 copy_u8PIN)
{
	u8 LOC_u8Result = 0;
	switch(copy_u8PORT)
	{
		case GPIOA:	LOC_u8Result = GET_BIT(GPIOA_IDR , copy_u8PIN);		break;
		case GPIOB:	LOC_u8Result = GET_BIT(GPIOB_IDR , copy_u8PIN);		break;
		case GPIOC:	LOC_u8Result = GET_BIT(GPIOC_IDR , copy_u8PIN);		break;
	}
	return LOC_u8Result;
	
}
