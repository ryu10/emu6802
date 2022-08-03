/* 
 * File:   MemAccess.h
 * Author: ryu
 *
 * Created on July 31, 2022, 9:50 AM
 */

#ifndef MEMACCESS_H
#define	MEMACCESS_H

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

void memAccess(void);

#ifdef	__cplusplus
}
#endif

#endif	/* MEMACCESS_H */

