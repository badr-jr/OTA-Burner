/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 16 May 2022									  */
/* Version 			: V01											  */
/**********************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H
void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 copy_u8BusId, u8 copy_u8PerId);
void RCC_voidDisableClock(u8 copy_u8BusId, u8 copy_u8PerId);
#define RCC_AHB		0
#define RCC_APB1	1
#define RCC_APB2	2

#endif
