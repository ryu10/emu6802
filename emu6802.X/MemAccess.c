/* 
 * File:   MemAccess.c
 * Author: ryu
 *
 * Created on July 31, 2022, 9:49 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "RomRam.h"
#include "PortAssign.h"
#include "MemAccess.h"

/*
 * 
 */

AB_t ab;
volatile int MemAccess;

void memAccess(){
    // readAddress();
    ab.h = PORTD;
    ab.l = PORTB;
    MPU_MRDY = 0;
    // Clear the CLC interrupt flag
    PIR0bits.CLC1IF = 0;
    if(MPU_RW){
        // MPU read = PIC Data bus output
        // MPU_DDIR = 0;
          asm("clrf    TRISC");
          if(ab.w < RAM_END){ // main ram
          asm("movf    PORTB,w");
          // iorlw   0xC0        //debug
          asm("movwf   FSR0L");
          asm("movlw   0x10");
          asm("addwf   PORTD,w");
          asm("movwf   FSR0H");
          // asm("clrf    TRISC");
          asm("movf    INDF0,w");
          asm("movwf   LATC");
            // LATC = ram[ab.w];
        }else if(ab.w >= ROM_BEG){ // 16k rom
          asm("movf    PORTB,w");
          asm("movwf   TBLPTRL");
          asm("movf    PORTD,w");
          asm("movwf   TBLPTRH");
          asm("clrf    TBLPTRU");
          asm("tblrd");
          // asm("clrf    TRISC");
          asm("movf    TABLAT,w");
          asm("movwf   LATC");
            // LATC = rom[ab.w - ROM_BEG];
        }else if(ab.w == UART_DREG){
            LATC = U3RXB;
        }else if(ab.w == UART_CREG){
            LATC = PIR9;
        }
        // Clear Mem Stretch
        MPU_MRDY = 1;
        // after a write phase, we should wait for at least tDHW = 30ns here but omit it for now
        // MPU_DDIR = 0xff;
        asm("setf    TRISC");
    }else{
        // MPU write = PIC Data bus input
        // while(MPU_E==0){;} // wait until the second half of MPU cycle
//                _delay(225*_XTAL_FREQ/1000000000); // 14 @ _XTAL_FREQ = 64000000, ~219ns
        // _delay(14); // 14 @ _XTAL_FREQ = 64000000, ~219ns
        // d = PORTC;
        if(ab.w < RAM_END){ // main ram
          // asm("setf   TRISC");
          asm("movf    PORTB,w");
          asm("movwf   FSR0L");
          asm("movlw   0x10");
          asm("addwf   PORTD,w");
          asm("movwf   FSR0H");
          while(MPU_E==0){;} 
          _delay(14);
          asm("movf    PORTC,w");
          asm("movwf   INDF0");
            // ram[ab.w] = d;
        }else if(ab.w == UART_DREG){
            while(MPU_E==0){;} 
            _delay(14);
            U3TXB = PORTC;
        }
        // Clear Mem Stretch
        MPU_MRDY = 1;
    }
}

