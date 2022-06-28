/*
 * UART_config.h
 *
 *  Created on: Jun 16, 2022
 *      Author: badrm
 */

#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}MUART1;

#define MUSART1			((volatile MUART1*) 0x40013800)

#endif
