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
                if(ab.w < RAM0_END){ // read ram
                    LATC = ram0[ab.w - RAM0_BEG];
                }else if(ab.w >= ROM0_BEG){ // read rom
                    LATC = rom0[ab.w - ROM0_BEG];
                }else if(ab.w == UART_DREG){
                    LATC = U3RXB;
                }else if(ab.w == UART_CREG){
                    LATC = PIR9;
                }
            }else{
                // MPU write = PIC Data bus input
                MPU_DDIR = 0xff;
                while(MPU_E==0){;} // wait until the second half of MPU cycle
//                _delay(225*_XTAL_FREQ/1000000000); // 14 @ _XTAL_FREQ = 64000000, ~219ns
                _delay(14); // 14 @ _XTAL_FREQ = 64000000, ~219ns
                if(ab.w < RAM0_END){ // read ram
                    ram0[ab.w - RAM0_BEG] = PORTC;
                }else if(ab.w == UART_DREG){
                    U3TXB = PORTC;
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

