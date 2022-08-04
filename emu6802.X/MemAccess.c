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
    ab.l = PORTB;
    ab.h = PORTD;
    asm("bcf    CLCnPOL,1"); // MPU_MRDY = 0; // G2POL = 0; CLCnPOL,1

    PIR0bits.CLC1IF = 0;     // Clear the CLC interrupt flag
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
        }else if(ab.w >= ROM_BEG){ // 16k rom
          asm("movf    PORTB,w");
          asm("movwf   TBLPTRL");
          asm("movf    PORTD,w");
          asm("movwf   TBLPTRH");
          asm("clrf    TBLPTRU");
          asm("tblrd");
          asm("movf    TABLAT,w");
          asm("movwf   LATC");
        }else if(ab.w == UART_DREG){
          asm("movff U3RXB,LATC");
        }else if(ab.w == UART_CREG){
          asm("movff PIR9,LATC");
        }
        // Clear Mem Stretch
        asm("bsf    CLCnPOL,1"); // MPU_MRDY = 1; // G2POL = 1; CLCnPOL,1
        // after a write phase, we should wait for at least tDHW = 30ns here but omit it for now
        asm("setf    TRISC");        // MPU_DDIR = 0xff;
    }else{
        // MPU write = PIC Data bus input
        if(ab.w < RAM_END){ // main ram
          asm("movf    PORTB,w");
          asm("movwf   FSR0L");
          asm("movlw   0x10");
          asm("addwf   PORTD,w");
          asm("movwf   FSR0H");
          while(MPU_E==0){;} // wait until the second half of MPU cycle
          _delay(14); // _delay(225*_XTAL_FREQ/1000000000); // 14 @ _XTAL_FREQ = 64000000, ~219ns
          asm("movf    PORTC,w");
          asm("movwf   INDF0");
        }else if(ab.w == UART_DREG){
            while(MPU_E==0){;} 
            _delay(14);
          asm("movff PORTC,U3TXB"); // U3TXB = PORTC;
        }
        // Clear Mem Stretch
        asm("bsf    CLCnPOL,1"); // MPU_MRDY = 1; // G2POL = 1; CLCnPOL,1
    }
}

