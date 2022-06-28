/*
 * FPEC_private.h
 *
 *  Created on: Jun 25, 2022
 *      Author: badrm
 */

#ifndef FPEC_INTERFACE_H_
#define FPEC_INTERFACE_H_

void MFPEC_voidFlashRecord(u32 Copy_u32RecordAddress, u16* Copy_u16RecordData, u8 Copy_u8RecordLength);
void MFPEC_voidEraseApplicationSection();

#endif /* FPEC_PRIVATE_H_ */
