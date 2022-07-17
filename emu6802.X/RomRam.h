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

/* ram0: main ram */
#define RAM0_BEG 0x0000
#define RAM0_END 0x2800
#define RAM0_SIZ (RAM0_END - RAM0_BEG) // 0x2800 (10,240 bytes)

extern uint8_t ram0[];

/* ram1: mikbug work */
#define RAM1_BEG 0x7f00
#define RAM1_END 0x7f80
#define RAM1_SIZ (RAM1_END - RAM1_BEG) // 0x0080 (128 bytes)

extern uint8_t ram1[];

/* rom1: abas68 patch */
#define ROM1_BEG 0x7f80
#define ROM1_END 0x7f98
#define ROM1_SIZ (ROM1_END - ROM1_BEG) // 0x0018 (24 bytes)

extern const uint8_t rom1[];

/* UART */
#define UART_DREG 0x8019 // UART Data
#define UART_CREG 0x8018 // UART Ctrl

/* rom2: mikbug */
#define ROM2_BEG 0xe000
#define ROM2_END 0xe200
#define ROM2_SIZ (ROM2_END - ROM2_BEG) // 0x0200 (512 bytes)

extern const uint8_t rom2[];

/* rom3: vectors */
#define ROM3_BEG 0xfff8
#define ROM3_END 0x10000
#define ROM3_SIZ (ROM3_END - ROM3_BEG) // 0x0008 (8 bytes)

extern const uint8_t rom3[];

extern void cp_basic();


#ifdef	__cplusplus
}
#endif

#endif	/* ROMRAM_H */
