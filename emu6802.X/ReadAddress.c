/* 
 * File:   ReadAddress.c
 * Author: ryu
 *
 * Created on July 10, 2022, 1:44 AM
 */

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include "ReadAddress.h"
#include "PortAssign.h"
#include "RomRam.h"

/*
 * 
 */
AB_t ab;
volatile int MemAccess;

inline void readAddress(void){
    
    // read MPU address bus
    ab.h = PORTD;
    ab.l = PORTB;
    if(ab.w < RAM0_BEG){ return ; } // do not disrupt hw ram access
    
    // Enable Mem access stretch
//    CLCSELECT = 1; // select CLC2=MRdy FF
    MPU_MRDY = 0;
    // set MemAccess
    MemAccess = 1;
    
    return;
}

