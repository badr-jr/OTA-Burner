/**********************************************************************/
/* Author			: Badr Mohamed									  */
/* Date				: 20 May 2022									  */
/* Version 			: V01											  */
/**********************************************************************/


#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define STK_BASE_ADDRESS		0xE000E010

#define AHB			1
#define AHB_DIV_8	0

#define Single      0
#define Periodic    1


#define STK_CTRL				*((volatile u32*) (STK_BASE_ADDRESS + 0x00))
#define STK_LOAD				*((volatile u32*) (STK_BASE_ADDRESS + 0x04))
#define STK_VAL					*((volatile u32*) (STK_BASE_ADDRESS + 0x08))
#define STK_CALIB				*((volatile u32*) (STK_BASE_ADDRESS + 0x0C))

	


#endif
