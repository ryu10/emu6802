/* 
 * File:   RomRam.h
 * Author: ryu
 *
 * Created on July 10, 2022, 2:17 PM
 */

#ifndef ROMRAM_H
#define	ROMRAM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
    

/* rom0: Altair Basic */
#define ROM0_BEG 0x0000
#define ROM0_END 0x1af3
#define ROM0_SIZ (ROM0_END - ROM0_BEG) // 0x1af3 (6,899 bytes)

extern const uint8_t rom0[];

/* ram: main ram */
#define RAM_BEG 0x0000 
#define RAM_END 0x3000
#define RAM_SIZ (RAM_END - RAM_BEG) // 0x3000 (12,288 bytes)

extern volatile uint8_t ram[];


/* rom: main rom 16KB */
#define ROM_BEG 0xC000
#define ROM_END 0x10000
#define ROM_SIZ (ROM_END - ROM_BEG) // 0x4000 (16KB)

extern const uint8_t rom[];

/* UART */
#define UART_DREG 0x8019 // UART Data
#define UART_CREG 0x8018 // UART Ctrl

/* PIC TIMER TU16A */

#define TIMER_BASE 0xa000 // Timer registers
#define TIMER_CON0 0x07 // 0x0387: TU16ACON0
#define TIMER_CON1 0x08 // 0x0388: TU16ACON1
#define TIMER_HLT  0x09 // 0x0389: TU16AHLT
#define TIMER_PS   0x0a // 0x038A: TU16APS
#define TIMER_TMRH 0x0b // 0x038B: TU16ATMRH / TU16ACRH
#define TIMER_TMRL 0x0c // 0x03: TU16ATMRL / TU16ACRL
#define TIMER_PRH  0x0d // 0x038D: TU16APRH
#define TIMER_PRL  0x0e // 0x0399: TU16APRL
#define TIMER_CLK  0x0f // 0x038F: TU16ACLK
#define TIMER_RES  0x1f // reset interrupt FF
/* copy basic binary to ram */
extern void cp_basic(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ROMRAM_H */
