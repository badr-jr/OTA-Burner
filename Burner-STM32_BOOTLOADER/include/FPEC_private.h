/*
 * FPEC_private.h
 *
 *  Created on: Jun 25, 2022
 *      Author: badrm
 */

#ifndef FPEC_PRIVATE_H_
#define FPEC_PRIVATE_H_


typedef struct{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 Reserved;
	volatile u32 OBR;
	volatile u32 WRPR;
}FPEC_REGISTERS;
#define FPEC		((volatile FPEC_REGISTERS *)0x40022000)



#endif /* FPEC_PRIVATE_H_ */
