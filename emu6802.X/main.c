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
    
    // set databus MPU write default
    MPU_DDIR = 0xff;
    
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
    
    // copy altair basic img to ram0[] area]
    cp_basic();

    // set mikbug 'G' vector to 0x0000 altair start address
    ram[0x3148 - RAM_BEG] = 0x00;
    ram[0x3149 - RAM_BEG] = 0x00;
    
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
            if(MPU_RW){
                // MPU read = PIC Data bus output
                MPU_DDIR = 0;
                if(ab.w < RAM_END){ // main ram
                    LATC = ram[ab.w];
                }else if(ab.w == UART_DREG){
                    LATC = U3RXB;
                }else if(ab.w == UART_CREG){
                    LATC = PIR9;
                }else if(ab.w >= ROM_BEG){ // 16k rom
                    LATC = rom[ab.w - ROM_BEG];
                }
                MemAccess = 0; 
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
                if(ab.w < RAM_END){ // main ram
                    ram[ab.w] = d;
                }else if(ab.w == UART_DREG){
                    U3TXB = d;
                }
                MemAccess = 0; 
                // Clear Mem Stretch
                MPU_MRDY = 1;
            }
        }
    }

    return (EXIT_SUCCESS);

}

