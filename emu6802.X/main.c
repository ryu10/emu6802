/* 
 * File:   main.c
 * Author: ryu10/RyuStudio
 *
 * Created on July 5, 2022, 11:20 PM
 */

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include "PortAssign.h"
#include "ReadAddress.h"
#include "RomRam.h"

/*
 * main
 */

//int MemAccess;

int main(int argc, char** argv) {
    uint8_t d;

    // Initialize the device
    SYSTEM_Initialize();

    // update pin input slew rate
//    SLRCONA = 0;
//    SLRCONB = 0;
//    SLRCONC = 0;
//    SLRCOND = 0;
//    SLRCONE = 0;

    // init romram;
    // done in "RomRam.h"

    // Assert MPU Reset#
    MPU_RES = 0;
    
    // set databus MPU read default
    MPU_DDIR = 0;
    
    // reset MRdy FF
    CLCSELECT = 1; // select CLC2=MRdy FF
    MRDY_FF_RES = 0;
    __delay_us(1);
    MRDY_FF_RES = 1;
    __delay_us(1);
    MRDY_FF_RES = 0;
    
    // Assert MPU MemRdy (normal operation)
    __delay_us(1);
    MPU_MRDY = 1;
    
    // copy first page of Altair binary to zero page
    cp_zpg();
    
    MemAccess = 0; 
    // Enable global interrupts
    INTERRUPT_GlobalInterruptHighEnable();
    
    // Release MPU Reset#
    __delay_us(5);
    MPU_RES = 1;

    // Print startup mesg.
    printf("MPU init done\r\n");

    while(1) {
        if(MemAccess){
            MPU_MRDY = 0; // extend mem cycle phase
         
            // Switch R/W
            if(MPU_RW){
                // MPU read = PIC Data bus output
                if(ab.w < ZPG_END){
                    LATC = zpg[ab.w];
                }else if(ab.w == fcb_addr[0]){
                    LATC = fcb[0];
                }else if(ab.w == fcb_addr[1]){
                    LATC = fcb[1];
                }else if(ab.w == fcb_addr[2]){
                    LATC = fcb[2];
                }else if(ab.w == fcb_addr[3]){
                    LATC = fcb[3];
                }else if(ab.w == fcb_addr[4]){
                    LATC = fcb[4];
                }else if(ab.w == fcb_addr[5]){
                    LATC = fcb[5];
                }else if(ab.w == fcb_addr[6]){
                    LATC = fcb[6];
                }else if(ab.w < ROM0_END){ // basic rom
                    LATC = rom0[ab.w - ROM0_BEG];
                }else if(ab.w < RAM0_END){ // main ram
                    LATC = ram0[ab.w - RAM0_BEG];
                }else if((ab.w >= RAM1_BEG) && (ab.w < RAM1_END)){ // mikbug work
                    LATC = ram1[ab.w - RAM1_BEG];
                }else if((ab.w >= ROM1_BEG) && (ab.w < ROM1_END)){ // basic patch
                    LATC = rom1[ab.w - ROM1_BEG];
                }else if(ab.w == UART_DREG){
                    LATC = U3RXB;
                }else if(ab.w == UART_CREG){
                    LATC = PIR9;
                }else if((ab.w >= ROM2_BEG) && (ab.w < ROM2_END)){ // mikbug
                    LATC = rom2[ab.w - ROM2_BEG];
                }else if(ab.w >= ROM3_BEG){ // vectors
                    LATC = rom3[ab.w - ROM3_BEG];
                }
            }else{
                // MPU write = PIC Data bus input
                MPU_DDIR = 0xff;
                while(MPU_E==0){;} // wait until the second half of MPU cycle
//                _delay(225*_XTAL_FREQ/1000000000); // 14 @ _XTAL_FREQ = 64000000, ~219ns
                _delay(14); // 14 @ _XTAL_FREQ = 64000000, ~219ns
                d = PORTC;
                if(ab.w < ZPG_END){
                    zpg[ab.w] = d;
                }else if(ab.w == fcb_addr[0]){
                    fcb[0] = d;
                }else if(ab.w == fcb_addr[1]){
                    fcb[1] = d;
                }else if(ab.w == fcb_addr[2]){
                    fcb[2] = d;
                }else if(ab.w == fcb_addr[3]){
                    fcb[3] = d;
                }else if(ab.w == fcb_addr[4]){
                    fcb[4] = d;
                }else if(ab.w == fcb_addr[5]){
                    fcb[5] = d;
                }else if(ab.w == fcb_addr[6]){
                    fcb[6] = d;
                }else if((ab.w >= RAM0_BEG) && (ab.w < RAM0_END)){ // main ram
                    ram0[ab.w - RAM0_BEG] = d;
                }else if((ab.w >= RAM1_BEG) && (ab.w < RAM1_END)){ // mikbug work
                    ram1[ab.w - RAM1_BEG] = d;
                }else if(ab.w == UART_DREG){
                    U3TXB = d;
                }
                MPU_DDIR = 0;
            }
            MemAccess = 0;
            // Clear Mem Stretch
            MPU_MRDY = 1;
        }
    }

    return (EXIT_SUCCESS);

}

