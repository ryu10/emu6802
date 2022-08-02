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
#define RAM_BEG 0x0000  // when enabling 128B internal ram
#define RAM_END 0x3180
#define RAM_SIZ (RAM_END - RAM_BEG) // 0x3180 (12,672 bytes)

extern uint8_t ram[];


/* rom: main rom 16KB */
#define ROM_BEG 0xC000
#define ROM_END 0x10000
#define ROM_SIZ (ROM_END - ROM_BEG) // 0x4000 (16KB)

extern const uint8_t rom[];

/* UART */
#define UART_DREG 0x8019 // UART Data
#define UART_CREG 0x8018 // UART Ctrl

extern void cp_basic();

#ifdef	__cplusplus
}
#endif

#endif	/* ROMRAM_H */
