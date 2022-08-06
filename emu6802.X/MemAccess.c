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

void memAccess(){
    asm("movff    PORTB,TBLPTRL");
    asm("movff    PORTD,TBLPTRH");
    asm("bcf    CLCnPOL,1"); // MPU_MRDY = 0; // G2POL = 0; CLCnPOL,1

    PIR0bits.CLC1IF = 0;     // Clear the CLC interrupt flag
    if(MPU_RW){
        // MPU read = PIC Data bus output
          asm("clrf    TRISC");        // MPU_DDIR = 0;
          if(TBLPTRH < (RAM_END>>8)){ // main ram
          asm("movf    PORTB,w");
          asm("movwf   FSR0L");
          asm("movlw   0x10");
          asm("addwf   PORTD,w");
          asm("movwf   FSR0H");
          asm("movf    INDF0,w");
          asm("movwf   LATC");
        }else if(TBLPTRH >= (ROM_BEG>>8)){ // 16k rom
          asm("movf    PORTB,w");
          asm("movwf   TBLPTRL");
          asm("movf    PORTD,w");
          asm("movwf   TBLPTRH");
          asm("clrf    TBLPTRU");
          asm("tblrd");
          asm("movf    TABLAT,w");
          asm("movwf   LATC");
        }else if(TBLPTRH == (UART_DREG>>8)){
          if(TBLPTRL == (UART_DREG & 0x00ff)){
            asm("movff U3RXB,LATC");
          }else{
          asm("movff PIR9,LATC");
          }
        }
        // Clear Mem Stretch
        asm("bsf    CLCnPOL,1"); // MPU_MRDY = 1; // G2POL = 1; CLCnPOL,1
        // after a write phase, we should wait for at least tDHW = 30ns here but omit it for now
        asm("setf    TRISC");        // MPU_DDIR = 0xff;
    }else{
        // MPU write = PIC Data bus input
        if(TBLPTRH < (RAM_END>>8)){ // main ram
          asm("movf    PORTB,w");
          asm("movwf   FSR0L");
          asm("movlw   0x10");
          asm("addwf   PORTD,w");
          asm("movwf   FSR0H");
          while(MPU_E==0){;} // wait until the second half of MPU cycle
          _delay(4); // 62.5ns * 4 = 250ns; cf. tDDW = 225ns @MC6802
          asm("movf    PORTC,w");
          asm("movwf   INDF0");
        }else if(TBLPTRH == (UART_DREG>>8)){
          if(TBLPTRL == (UART_DREG & 0x00ff)){
            while(MPU_E==0){;} 
            _delay(4); // 62.5ns * 4 = 250ns; cf. tDDW = 225ns @MC6802
            asm("movff PORTC,U3TXB"); // U3TXB = PORTC;
          }
        }
        // Clear Mem Stretch
        asm("bsf    CLCnPOL,1"); // MPU_MRDY = 1; // G2POL = 1; CLCnPOL,1
    }
}

