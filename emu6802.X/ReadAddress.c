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

/*
 * 
 */
AB_t ab;
int MemAccess;

inline void readAddress(void){
    
    // read MPU address bus
    ab.h = PORTD;
    ab.l = PORTB;
    
    // Enable Mem access stretch
    MPU_MRDY = 0;
    // set MemAccess
    MemAccess = 1;
    
    return;
}

