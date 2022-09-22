/* 
 * File:   ClockTimer.c
 * Author: ryu
 *
 * Created on August 13, 2022, 10:32 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

/*
 * 
 */

volatile unsigned char curr_time[4];
volatile unsigned char set_time[4];
volatile unsigned char read_time[4];
volatile int reset_tmrout;

void clockInit(){
  int i;
  
  for(i=0;i<4;i++){
    curr_time[i] = 0;
    set_time[i] = 0;
    read_time[i] = 0;
  }
  curr_time[0] = 4;

  reset_tmrout = 0;

  // start TU16A
  TU16APS = 0;
  TU16APRH = 0x0c;
  TU16APRL = 0x35;
  TU16ACON0 = TU16ACON0 | 0x80;
  
}

void clockPrepTime(unsigned char hour, unsigned char min){
  set_time[2] = min;
  set_time[3] = hour;
}

void clockSetTime(){
  int i;
  for(i=0;i<4;i++){
    curr_time[i] = set_time[i];
  }
}

void clockReadTime(unsigned char *t){
  int i;
  for(i=0;i<4;i++){
    read_time[i] = curr_time[i];
  }
}

void clockTick(unsigned char *t){

  t[0]++; //tick
  if(t[0]==10){
    t[0]=0;
    t[1]++; //sec
    if(t[1]==60){
      t[1]=0;
      t[2]++; //min
      if(t[2]==60){
        t[2]=0;
        t[3]++; //hr
        if(t[3]==24){
          t[3]=0;
        }
      }
    }
  }
}

