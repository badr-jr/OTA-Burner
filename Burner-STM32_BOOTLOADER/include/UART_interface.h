/*
 * UART_config.h
 *
 *  Created on: Jun 16, 2022
 *      Author: badrm
 */

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H


void MUSART_voidInit(void);
void MUSART_voidTransimit(u8 *arr);
u8 MUSART_u8Receive(u8 *Copy_u8ptrData);

#endif
