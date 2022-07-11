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
//#include "RomRam.h"

/*
 * main
 */

//int MemAccess;

int main(int argc, char** argv) {

    // Initialize the device
    SYSTEM_Initialize();
    
    // init romram;
    // done in "RomRam.h"

    // Assert MPU Reset#
    MPU_RES = 0;
    
    // set databus read
    MPU_DDIR = 0xff;
    
    // reset MRdy FF
    CLCSELECT = 1; // select CLC2=MRdy FF
    MRDY_FF_RES = 0;
    MRDY_FF_RES = 1;
    __delay_us(1);
    MRDY_FF_RES = 0;
    // Assert MPU MemRdy (normal operation)
    MPU_MRDY = 1;
    
    
    MemAccess = 0; 
    // Enable global interrupts
    INTERRUPT_GlobalInterruptHighEnable();
    
    // Release MPU Reset#
    __delay_us(5);
    MPU_RES = 1;

    // Print startup mesg.
    printf("MPU init done!1234\r\n");

    CLCSELECT = 1; // select CLC2=MRdy FF
    
    while(1) {
        if(MemAccess){
            printf("VMA detected. Address= %04x %02x:%02x\r\n", ab.w, ab.h, ab.l);
            while(1){;}
         
            // Switch R/W
            if(MPU_RW){
                // MPU read = PIC Data bus output
                MPU_DDIR = 0; // PIC Data bus output
            // Switch mem acc range
                
                MPU_DDIR = 0xff; // PIC Data bus input
            }else{
                // MPU write = PIC Data bus input
            // Switch mem acc range
            }
            MemAccess = 0;
            // Clear Mem Stretch
            MPU_MRDY = 1;
        }
    }

    return (EXIT_SUCCESS);

}

