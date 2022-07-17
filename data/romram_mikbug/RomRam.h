/* 
 * File:   RomRam.h
 * Author: ryu
 *
 * Created on July 10, 2022, 2:17 PM
 */

#include <xc.h>

#ifndef ROMRAM_H
#define	ROMRAM_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ROM0_BEG 0xe000
#define ROM0_END 0x10000
#define ROM0_SIZ (ROM0_END - ROM0_BEG) // mikbug 512b + blank 1.5kB + vecs 16b
    
//#define ROM1_BEG 0xfff0
//#define ROM1_END 0x10000 
//#define ROM1_SIZ (ROM1_END - ROM1_BEG) // reset vecs 16b
    
#define RAM0_BEG 0x0000
#define RAM0_END 0x2000 // 0x1ffff
#define RAM0_SIZ (RAM0_END - RAM0_BEG) // 2kB
    
#define UART_DREG 0x8019 // UART Data
#define UART_CREG 0x8018 // UART Ctrl
    
extern const uint8_t rom0[];
//extern const uint8_t rom1[];
extern uint8_t ram0[];    

#ifdef	__cplusplus
}
#endif

#endif	/* ROMRAM_H */

