/* 
 * File:   ClockTimer.h
 * Author: ryu
 *
 * Created on August 13, 2022, 10:31 AM
 */

#ifndef CLOCKTIMER_H
#define	CLOCKTIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

extern unsigned char curr_time[];
extern unsigned char read_time[];
extern unsigned char set_time[];
extern volatile int reset_tmrout;

void clockInit(void);
void clockPrepTime(unsigned char hour, unsigned char min);
void clockSetTime(unsigned char *);
void clockReadTime(unsigned char *);
void clockTick(unsigned char *);

#ifdef	__cplusplus
}
#endif

#endif	/* CLOCKTIMER_H */

