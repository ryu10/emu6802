/* 
 * File:   PortAssign.h
 * Author: ryu
 *
 * Created on July 9, 2022, 10:01 PM
 */

#ifndef PORTASSIGN_H
#define	PORTASSIGN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"

#define MPU_E   RA0 // RA0 IN   6802 E
#define MPU_VMA RA1 // RA1 IN   6802 VMA
// #define MPU_MR     IO_RA2_LAT // RA2 OUT  6802 MR
// #define MPU_EXTAL  IO_RA3_LAT // RA3 OUT  6802 EXTAL
#define MPU_RES    IO_RA4_LAT // RA4 OUT  6802 #RES
#define MPU_RW  RA5 // RA5 IN   6802 r/#w

#define MPU_DDIR TRISC // Data bus (RC) dir 0xff: Input, 0x00: Output

    // Mrdy FF, use 'CLCSELECT = 1;' (select CLC2) before accessing MPU_MRDY/MRDY_FF_RES
#define MPU_MRDY G2POL // CLC2:GATE2 (1:H, 0:L)
#define MRDY_FF_RES G3POL // CLC2:GATE3 (1:H, 0:L)

    
#ifdef	__cplusplus
}
#endif

#endif	/* PORTASSIGN_H */

