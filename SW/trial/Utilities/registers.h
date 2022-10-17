/*
 * registers.h
 * Created: 9/10/2022 5:10:32 PM
 *  Author: Ahmed Ehab
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "types.h"
//PORTA registers
#define PORTA *((volatile uint8_t*)0x3B) // 8 bit register
#define DDRA *((volatile uint8_t*)0x3A) // 8 bit register
#define PINA *((volatile uint8_t*)0x39) // 8 bit register

//PORTB registers
#define PORTB *((volatile uint8_t*)0x38) // 8 bit register
#define DDRB *((volatile uint8_t*)0x37) // 8 bit register
#define PINB *((volatile uint8_t*)0x36) // 8 bit register

//PORTC registers
#define PORTC *((volatile uint8_t*)0x35) // 8 bit register
#define DDRC *((volatile uint8_t*)0x34) // 8 bit register
#define PINC *((volatile uint8_t*)0x33) // 8 bit register

//PORTD registers
#define PORTD *((volatile uint8_t*)0x32) // 8 bit register
#define DDRD *((volatile uint8_t*)0x31) // 8 bit register
#define PIND *((volatile uint8_t*)0x30) // 8 bit register


//TIMER0 registers
#define TCCR0 *((volatile uint8_t*)0x53) // 8 bit register
#define TCNT0 *((volatile uint8_t*)0x52) // 8 bit register
#define TIFR *((volatile uint8_t*)0x58) // 8 bit register

//TIMER1 registers
#define TCCR1A *((volatile uint8_t*)0x4F) // 8 bit register
#define TCCR1B *((volatile uint8_t*)0x4E) // 8 bit register
#define TCNT1H *((volatile uint8_t*)0x4D) // 8 bit register
#define TCNT1L *((volatile uint8_t*)0x4C) // 8 bit register

//TIMER2 registers
#define TCCR2 *((volatile uint8_t*)0x45) // 8 bit register
#define TCNT2 *((volatile uint8_t*)0x44) // 8 bit register

//Timer interrupt
#define TIMSK *((volatile uint8_t*)0x59) // 8 bit register


//External interrupts registers
#define MCUCR *((volatile uint8_t*)0x55) // 8 bit register
#define MCUCSR *((volatile uint8_t*)0x54) // 8 bit register
#define GICR *((volatile uint8_t*)0x5B) // 8 bit register
#define GIFT *((volatile uint8_t*)0x5A) // 8 bit register

#define WDTCR *((volatile uint8_t*)0x41) // 8 bit register

#endif /* REGISTERS_H_ */