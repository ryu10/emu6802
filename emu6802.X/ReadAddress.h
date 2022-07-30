/* 
 * File:   ReadAddress.h
 * Author: ryu
 *
 * Created on July 10, 2022, 1:39 AM
 */

#ifndef READADDRESS_H
#define	READADDRESS_H

#include "PortAssign.h"

#ifdef	__cplusplus
extern "C" {
#endif
    
typedef union  {
    unsigned int w; //16 bit Address
    struct {
        unsigned char l; //Address low
        unsigned char h; //Address high
    };
}AB_t;

extern AB_t ab;
extern volatile int MemAccess;

inline void readAddress(void);
 

#ifdef	__cplusplus
}
#endif

#endif	/* READADDRESS_H */

