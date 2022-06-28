/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 17 May 2022									  */
/* Version 			: V01											  */
/**********************************************************************/

#ifndef GPIO_INTERFACE_H

#define GPIO_INTERFACE_H

#define GPIO_HIGH	1
#define GPIO_LOW	0

/*		GPIO PORTS		*/
#define 	GPIOA	0
#define 	GPIOB	1
#define 	GPIOC	2

/*		PORTS PINS		*/
#define 	PIN0	0
#define 	PIN1	1
#define 	PIN2	2
#define 	PIN3	3
#define 	PIN4	4
#define 	PIN5	5
#define 	PIN6	6
#define 	PIN7	7
#define 	PIN8	8
#define 	PIN9	9
#define 	PIN10	10
#define 	PIN11	11
#define 	PIN12	12
#define 	PIN13	13
#define 	PIN14	14
#define 	PIN15	15

/*		GPIO OUTPUT Modes	(10MHZ)	*/
#define 	OUTPUT_FREQ_10MHZ_PP	0b0001	
#define 	OUTPUT_FREQ_10MHZ_OD	0b0101	
#define 	OUTPUT_FREQ_10MHZ_AFPP	0b1001	
#define 	OUTPUT_FREQ_10MHZ_AFOD	0b1101	

/*		GPIO OUTPUT Modes	(2MHZ)	*/
#define 	OUTPUT_FREQ_2MHZ_PP		0b0010	
#define 	OUTPUT_FREQ_2MHZ_OD		0b0110	
#define 	OUTPUT_FREQ_2MHZ_AFPP	0b1010	
#define 	OUTPUT_FREQ_2MHZ_AFOD	0b1110	

/*		GPIO OUTPUT Modes	(50MHZ)	*/
#define 	OUTPUT_FREQ_50MHZ_PP	0b0011	
#define 	OUTPUT_FREQ_50MHZ_OD	0b0111	
#define 	OUTPUT_FREQ_50MHZ_AFPP	0b1011	
#define 	OUTPUT_FREQ_50MHZ_AFOD	0b1111	

/*		GPIO Input Modes			*/
#define 	INPUT_ANALOG			0b0000
#define 	INPUT_FLOATING			0b0100	
#define 	INPUT_PULL_UP_DOWN		0b1000		

void MGPIO_voidSetPinDirection(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Mode);
void MGPIO_voidSetPinValue(u8 copy_u8PORT , u8 copy_u8PIN , u8 copy_u8Value);
u8 MGPIO_u8GetPinValue(u8 copy_u8PORT , u8 copy_u8PIN);
#endif
