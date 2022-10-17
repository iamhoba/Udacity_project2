/*
 * timer.h
 *
 * Created: 9/20/2022 8:12:15 PM
 *  Author: Ahmed Ehab
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/*All driver includes*/
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"

/*All driver function prototypes*/
void TIMER_init(uint8_t timerNumber, uint8_t timerMode); //initialize of timer
void TIMER_start(uint8_t timerNumber, uint32_t prescalar); //start timer
void TIMER_stop(uint8_t timerNumber); //stop timer
void TIMER_set_value( uint8_t timerNumber, uint8_t initValue); //set timer value
void TIMER_delay( uint8_t timerNumber, uint8_t overFlows); //set timer value

/*Timers macros*/
#define TIMER_0 0
#define TIMER_1 1
#define TIMER_2 2

/*Timer Prescalar macros*/
#define NO_PRESCALAR 1
#define PRESCALAR_8 8
#define PRESCALAR_64 64
#define PRESCALAR_256 256
#define PRESCALAR_1024 1024

/*Timer modes macros*/
#define NORMAL_MODE 0
#define PWM_PHASE_CORRECT_MODE 1
#define CTC_MODE 2
#define FAST_PWM 3

/*Timer 0 Counter Control register macros*/
#define CS00 0
#define CS01 1 
#define CS02 2
#define WGM01 3
#define COM00 4
#define COM01 5
#define WGM00 6
#define FOC0 7

/*Timer 1 Counter Control register A macros*/
#define WGM10 0
#define WGM11 1
#define FOC1B 2
#define FOC1A 3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

/*Timer 1 Counter Control register B macros*/
#define CS10 0
#define CS11 1
#define CS12 2
#define WGM12 3
#define WGM13 4
#define ICES1 6
#define ICNC1 7

/*Timer 2 Counter Control register macros*/
#define CS20 0
#define CS21 1
#define CS22 2
#define WGM21 3
#define COM20 4
#define COM21 5
#define WGM20 6
#define FOC2 7

/*Timer interrupt flag register macros*/
#define TOV0 0
#define OCF0 1
#define TOV1 2
#define OCF1B 3
#define OCF1A 4
#define ICF1 5
#define TOV2 6
#define OCF2 7

#endif /* TIMER_H_ */