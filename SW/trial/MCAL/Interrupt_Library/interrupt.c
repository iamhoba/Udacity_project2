/*
 * interrupt.c
 *
 * Created: 10/8/2022 9:31:10 PM
 *  Author: Ahmed Ehab
 */ 

#include "interrupt.h"


/*Enable external interrupts*/
uint8_t EXT_INT_init(uint8_t intNumber){
	switch (intNumber){
		case INT0:
		MCUCR |= (1<<ISC00) | (1<<ISC01);		//choose external interrupt 0 sense rising edge
		GICR |= (1<<INT0);						//Enable external interrupt 0
		break;
		case INT1:
		MCUCR |= (1<<ISC10) | (1<<ISC11);		//choose external interrupt 1 sense rising edge
		GICR |= (1<<INT1);						//Enable external interrupt 1
		break;
		case INT2:
		MCUCSR |= (1<<ISC2);					//choose external interrupt 2 sense rising edge
		GICR |= (1<<INT2);						//Enable external interrupt 2
		break;		
		default:
		return ERROR;
	}
	return OK;
}


/*Enable global interrupts*/
void INT_init(void){
	sei();										//Enable global interrupts
}


/*Enable timer interrupts*/
uint8_t TIMER_INT_init(uint8_t timerNumber){
	switch (timerNumber){
		case TIMER_0:
		TIMSK |= (1<<OCIE0);					//Enable Timer 0 interrupt
		break;
		case TIMER_1:
		TIMSK |= (1<<OCIE1A);					//Enable Timer 1 interrupt
		TIMSK |= (1<<OCIE1B);
		break;
		case TIMER_2:
		TIMSK |= (1<<OCIE2);					//Enable Timer 2 interrupt
		break;
		default:
		return ERROR;
	}
	return OK;
}