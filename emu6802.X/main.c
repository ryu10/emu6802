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
#include "MemAccess.h"
#include "RomRam.h"

/*
 * main
 */

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
    
    // set databus MPU write default
    MPU_DDIR = 0xff;

    // // set RA4 ODCON - Open Drain
    // ODCONAbits.ODCA4 = 1;
    
    // set IRQ FF
    CLCSELECT = 5; // select CLC6 = IRQ FF
    __delay_us(1);
    IRQ_FF_RES = 1;
    __delay_us(1);
    IRQ_FF_RES = 0;

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
    // leave CLC2 selected for future access

    // copy altair basic img to ram0[] area]
    cp_basic();

    // set mikbug 'G' vector to 0x0000 abasic start address
    ram[0x2f48 - RAM_BEG] = 0x00;
    ram[0x2f49 - RAM_BEG] = 0x00;
    
    // Enable global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Print startup mesg.
    printf("MPU init done\r\n");

    // Release MPU Reset#
    __delay_us(5);
    MPU_RES = 1;


    while(1) {
        ;
    }

    return (EXIT_SUCCESS);

}

