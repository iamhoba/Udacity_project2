/*
 * interrupt.h
 *
 * Created: 10/8/2022 9:15:57 PM
 *  Author: Ahmed Ehab
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/*All driver includes*/
#include "../../Utilities/registers.h"
#include "../../Utilities/types.h"

/*External interrupt requests*/ 
#define EXT_INT_0 __vector_1 
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3
#define TIMER_0_INT __vector_10

/*Set global interrupts*/
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/*Clear global interrupts*/
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/*ISR definition*/
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

/*All driver function prototypes*/
uint8_t EXT_INT_init(uint8_t intNumber);				//enable external interrupts
uint8_t TIMER_INT_init(uint8_t timerNumber);			//enable timer interrupts
void INT_init(void);								//enable global interrupts

/*External interrupts macros*/
#define INT0 6
#define INT1 7
#define INT2 5
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2 6

/*Timer interrupt mask register macros*/
#define TOIE0 0
#define OCIE0 1
#define TOIE1 2
#define OCIE1B 3
#define OCIE1A 4
#define TOIE2 6
#define OCIE2 7

/*Timers macros*/
#define TIMER_0 0
#define TIMER_1 1
#define TIMER_2 2


#endif /* INTERRUPT_H_ */