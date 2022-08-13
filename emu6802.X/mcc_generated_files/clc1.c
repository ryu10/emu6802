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
#include "../ClockTimer.h"

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
//    asm("bsf      LATA,4");  // test isr startup time
    asm("movff    PORTB,TBLPTRL");
    asm("movff    PORTD,TBLPTRH");
    asm("bcf    CLCnPOL,1"); // MPU_MRDY = 0; // G2POL = 0; CLCnPOL,1

// reset clock timer interrupt out
    if(reset_tmrout){
        asm("movlw   0x05");  // select CLC6
        asm("movwf  CLCSELECT");
        asm("bsf    CLCnPOL,3"); // set G4POL = pull CLCOUT HIGH
        asm("bcf    CLCnPOL,3"); // reset G4POL for future pullup
        asm("movlw   0x01"); // select CLC2
        asm("movwf  CLCSELECT");
        reset_tmrout = 0;
    }

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
        }else if(TBLPTRH == (TIMER_BASE>>8)){
          if(TBLPTRL == TIMER_RES){ // reset timer output
            asm("movlw   0x05");  // select CLC6
            asm("movwf  CLCSELECT");
            asm("bsf    CLCnPOL,3"); // set G4POL = pull CLCOUT HIGH
            asm("bcf    CLCnPOL,3"); // reset G4POL for future pullup
            asm("movlw   0x01"); // select CLC2
            asm("movwf  CLCSELECT");
          }else if(TBLPTRL == TIMER_CON0){
            asm("movff TU16ACON0,LATC");
          }else if(TBLPTRL == TIMER_CON1){
            asm("movff TU16ACON1,LATC");
          // }else if(TBLPTRL == TIMER_HLT){
          //   asm("movff TU16AHLT,LATC");
          }else if(TBLPTRL == TIMER_PS){
            asm("movff TU16APS,LATC");
          }else if(TBLPTRL == TIMER_TMRL){
            asm("movff TU16ATMRL,LATC");
          }else if(TBLPTRL == TIMER_TMRH){
            asm("movff TU16ATMRH,LATC");
          }else if(TBLPTRL == TIMER_PRL){
            asm("movff TU16APRL,LATC");
          }else if(TBLPTRL == TIMER_PRH){
            asm("movff TU16APRH,LATC");
          }else if(TBLPTRL == TIMER_CLK){
            asm("movff TU16ACLK,LATC");
          }
        }else if(TBLPTRH == (TCLK_BASE>>8)){
          if(TBLPTRL == TCLK_TICK){
            LATC = curr_time[0];
          }else if(TBLPTRL == TCLK_SEC){
            LATC = curr_time[1];
          }else if(TBLPTRL == TCLK_MIN){
            LATC = curr_time[2];
          }else if(TBLPTRL == TCLK_HOUR){
            LATC = curr_time[3];
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
          // while(MPU_E==0){;} // wait until the second half of MPU cycle
          asm("_l_mpuecheck:");
          asm("btfss    PORTA,0"); // MPU_E = RA0
          asm("bra    _l_mpuecheck");
          // _delay(4); // 62.5ns * 4 = 250ns; cf. tDDW = 225ns @MC6802
          asm("movf    PORTC,w");
          asm("movwf   INDF0");
        }else if(TBLPTRH == (UART_DREG>>8)){
          if(TBLPTRL == (UART_DREG & 0x00ff)){
            // while(MPU_E==0){;} 
            asm("_l_mpuecheck1:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck1");
            // _delay(4); // 62.5ns * 4 = 250ns; cf. tDDW = 225ns @MC6802
            asm("movff PORTC,U3TXB"); // U3TXB = PORTC;
          }
        }else if(TBLPTRH == (TIMER_BASE>>8)){
          if(TBLPTRL == TIMER_CON0){
            asm("_l_mpuecheck20:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck20");
            asm("movff PORTC,TU16ACON0");
          }else if(TBLPTRL == TIMER_CON1){
            asm("_l_mpuecheck21:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck21");
            asm("movff PORTC,TU16ACON1");
          }else if(TBLPTRL == TIMER_PS){
            asm("_l_mpuecheck22:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck22");
            asm("movff PORTC,TU16APS");
          }else if(TBLPTRL == TIMER_TMRH){
            asm("_l_mpuecheck23:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck23");
            asm("movff PORTC,TU16ATMRH");
          }else if(TBLPTRL == TIMER_TMRL){
            asm("_l_mpuecheck24:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck24");
            asm("movff PORTC,TU16ATMRL");
          }else if(TBLPTRL == TIMER_PRH){
            asm("_l_mpuecheck25:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck25");
            asm("movff PORTC,TU16APRH");
          }else if(TBLPTRL == TIMER_PRL){
            asm("_l_mpuecheck26:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck26");
            asm("movff PORTC,TU16APRL");
          }else if(TBLPTRL == TIMER_CLK){
            asm("_l_mpuecheck27:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck27");
            asm("movff PORTC,TU16ACLK");
          }
        }else if(TBLPTRH == (TCLK_BASE>>8)){
          if(TBLPTRL == TCLK_TICK){
            asm("_l_mpuecheck30:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck30");
            set_time[0] = PORTC;
          }else if(TBLPTRL == TCLK_SEC){
            asm("_l_mpuecheck31:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck31");
            set_time[1] = PORTC;
          }else if(TBLPTRL == TCLK_MIN){
            asm("_l_mpuecheck32:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck32");
            set_time[2] = PORTC;
          }else if(TBLPTRL == TCLK_HOUR){
            asm("_l_mpuecheck33:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck33");
            set_time[3] = PORTC;
          }else if(TBLPTRL == TCLK_SET){
            asm("_l_mpuecheck34:");
            asm("btfss    PORTA,0"); // MPU_E = RA0
            asm("bra    _l_mpuecheck34");
            curr_time[3] = set_time[3]; 
            curr_time[2] = set_time[2]; 
            curr_time[1] = set_time[1]; 
            curr_time[0] = set_time[0]; 
          }
        }
        // Clear Mem Stretch
        asm("bsf    CLCnPOL,1"); // MPU_MRDY = 1; // G2POL = 1; CLCnPOL,1
    }
//    asm("bcf      LATA,4"); // test isr startup time
}

bool CLC1_OutputStatusGet(void)
{
    return(CLCDATAbits.CLC1OUT);
}
/**
 End of File
*/
