 /**
   CLC1 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     clc1.c
 
   @Summary
     This is the generated driver implementation file for the CLC1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CLC1.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
         Device            :  PIC18F47Q84
         Driver Version    :  1.0.0
     The generated drivers are tested against the following:
         Compiler          :  XC8 2.31 and above or later
         MPLAB             :  MPLAB X 5.45
 */ 

 /*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/
 
 /**
   Section: Included Files
 */

#include <xc.h>
#include "clc1.h"
#include "interrupt_manager.h"
#include "../MemAccess.h"
#include "../PortAssign.h"
#include "../RomRam.h"

/**
  Section: CLC1 APIs
*/

void CLC1_Initialize(void)
{
    // Set the CLC1 to the options selected in the User Interface
    
    // SLCT 0; 
    CLCSELECT = 0x00;
    // G1POL inverted; G2POL not_inverted; G3POL not_inverted; G4POL not_inverted; POL not_inverted; 
    CLCnPOL = 0x01;
    // D1S CLCIN0 (CLCIN0PPS); 
    CLCnSEL0 = 0x00;
    // D2S CLCIN1 (CLCIN1PPS); 
    CLCnSEL1 = 0x01;
    // D3S CLCIN0 (CLCIN0PPS); 
    CLCnSEL2 = 0x00;
    // D4S CLCIN0 (CLCIN0PPS); 
    CLCnSEL3 = 0x00;
    // G1D3N disabled; G1D2N disabled; G1D4N disabled; G1D1T enabled; G1D3T disabled; G1D2T disabled; G1D4T disabled; G1D1N disabled; 
    CLCnGLS0 = 0x02;
    // G2D2N disabled; G2D1N disabled; G2D4N disabled; G2D3N disabled; G2D2T enabled; G2D1T disabled; G2D4T disabled; G2D3T disabled; 
    CLCnGLS1 = 0x08;
    // G3D1N disabled; G3D2N disabled; G3D3N disabled; G3D4N disabled; G3D1T disabled; G3D2T disabled; G3D3T disabled; G3D4T disabled; 
    CLCnGLS2 = 0x00;
    // G4D1N disabled; G4D2N disabled; G4D3N disabled; G4D4N disabled; G4D1T disabled; G4D2T disabled; G4D3T disabled; G4D4N disabled; 
    CLCnGLS3 = 0x00;
    // CLC1OUT 0; 
    CLCDATA = 0x00;
    // EN enabled; INTN disabled; INTP enabled; MODE AND-OR; 
    CLCnCON = 0x90;

    // Clear the CLC interrupt flag
    PIR0bits.CLC1IF = 0;
    // Enabling CLC1 interrupt.
    PIE0bits.CLC1IE = 1;
}

void __interrupt(irq(CLC1),base(8)) CLC1_ISR()
{
    
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

bool CLC1_OutputStatusGet(void)
{
    return(CLCDATAbits.CLC1OUT);
}
/**
 End of File
*/
