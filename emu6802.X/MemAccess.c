/* 
 * File:   MemAccess.c
 * Author: ryu
 *
 * Created on July 31, 2022, 9:49 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "RomRam.h"
#include "ReadAddress.h"
#include "PortAssign.h"

/*
 * 
 */

void memAccess(){
    uint8_t d;

    if(MPU_RW){
        // MPU read = PIC Data bus output
        MPU_DDIR = 0;
        if((ab.w >= RAM_BEG) && (ab.w < RAM_END)){ // main ram
            LATC = ram[ab.w - RAM_BEG];
        }else if(ab.w == UART_DREG){
            LATC = U3RXB;
        }else if(ab.w == UART_CREG){
            LATC = PIR9;
        }else if(ab.w >= ROM_BEG){ // 16k rom
            LATC = rom[ab.w - ROM_BEG];
        }
        // Clear Mem Stretch
        MPU_MRDY = 1;
        // after a write phase, we should wait for at least tDHW = 30ns here but omit it for now
        MPU_DDIR = 0xff;
    }else{
        // MPU write = PIC Data bus input
        while(MPU_E==0){;} // wait until the second half of MPU cycle
//                _delay(225*_XTAL_FREQ/1000000000); // 14 @ _XTAL_FREQ = 64000000, ~219ns
        _delay(14); // 14 @ _XTAL_FREQ = 64000000, ~219ns
        d = PORTC;
        if((ab.w >= RAM_BEG) && (ab.w < RAM_END)){ // main ram
            ram[ab.w - RAM_BEG] = d;
        }else if(ab.w == UART_DREG){
            U3TXB = d;
        }
        // Clear Mem Stretch
        MPU_MRDY = 1;
    }
}

