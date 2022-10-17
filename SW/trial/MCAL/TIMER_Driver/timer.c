/*
 * timer.c
 *
 * Created: 9/20/2022 8:12:26 PM
 *  Author: Ahmed Ehab
 */ 

#include "timer.h"

void TIMER_init(uint8_t timerNumber, uint8_t timerMode){
	switch (timerNumber)
	{
		case TIMER_0:
		TCNT0 = 0x00;						//initial value of timer 0
		switch (timerMode){
			case NORMAL_MODE:				 //normal mode
			TCCR0 = 0x00;
			break;
			case PWM_PHASE_CORRECT_MODE:	//pwm phase correct mode
			TCCR0 = 0x00;					//stop timer
			TCCR0 |= (1<<WGM00);			//set timer to pwm phase correct mode 
			break;
			case CTC_MODE:					//ctc mode
			TCCR0 = 0x00;					//stop timer
			TCCR0 |= (1<<WGM01);			//set timer to ctc mode
			break;
			case FAST_PWM:					//fast pwm mode
			TCCR0 = 0x00;					//stop timer
			TCCR0 |= (1<<WGM00);			//set timer to fast pwm mode
			TCCR0 |= (1<<WGM01);				
			break;
		}
		break;
		case TIMER_1:
		TCNT1H = 0x00;						//initial value of timer 0
		TCNT1L = 0x00;
		switch (timerMode){
			case NORMAL_MODE:				 //normal mode
			TCCR1A = 0x00;
			TCCR1B = 0x00;
			break;
			case PWM_PHASE_CORRECT_MODE:	//pwm phase correct mode
			TCCR1A = 0x00;					//stop timer
			TCCR1B = 0x00;
			TCCR1A |= (1<<WGM10);			//set timer to pwm phase correct mode
			TCCR1A |= (1<<WGM11);			//set timer to pwm phase correct mode
			break;
			case CTC_MODE:					//ctc mode
			TCCR1A = 0x00;					//stop timer
			TCCR1B = 0x00;
			TCCR1B |= (1<<WGM12);			//set timer to ctc mode
			break;
			case FAST_PWM:					//fast pwm mode
			TCCR1A = 0x00;					//stop timer
			TCCR1B = 0x00;
			TCCR1A |= (1<<WGM10);			//set timer to fast pwm mode				
			TCCR1A |= (1<<WGM11);
			TCCR1B |= (1<<WGM12);
			TCCR1B |= (1<<WGM13);
			break;
		}
		break;
		case TIMER_2:
		TCNT2 = 0x00;						//initial value of timer 0
		switch (timerMode){
			case NORMAL_MODE:				 //normal mode
			TCCR2 = 0x00;
			break;
			case PWM_PHASE_CORRECT_MODE:	//pwm phase correct mode
			TCCR2 = 0x00;					//stop timer
			TCCR2 |= (1<<WGM20);			//set timer to pwm phase correct mode 
			break;
			case CTC_MODE:					//ctc mode
			TCCR2 = 0x00;					//stop timer
			TCCR2 |= (1<<WGM21);			//set timer to ctc mode
			break;
			case FAST_PWM:					//fast pwm mode
			TCCR2 = 0x00;					//stop timer
			TCCR2 |= (1<<WGM20);			//set timer to fast pwm mode
			TCCR2 |= (1<<WGM21);				
			break;
		}
		break;
	}
}

void TIMER_stop(uint8_t timerNumber){
	switch (timerNumber)
	{
		case TIMER_0:
			TCCR0 = 0x00;			//Timer Stop
		break;
		case TIMER_1:
			TCCR1A = 0x00;			//Timer Stop
			TCCR1B = 0x00;			//Timer Stop
		break;
		case TIMER_2:
			TCCR2 = 0x00;			//Timer Stop
		break;
	}
}

void TIMER_start(uint8_t timerNumber, uint32_t prescalar){
	switch (timerNumber)
	{
		case TIMER_0:
		switch (prescalar){
			case NO_PRESCALAR:   //start with no prescalar
			TCCR0 |= (1<<CS00);
			break;
			case PRESCALAR_8:	//start with prescalar clk/8
			TCCR0 |= (1<<CS01);
			break;
			case PRESCALAR_64:	//start with prescalar clk/64
			TCCR0 |= (1<<CS00);
			TCCR0 |= (1<<CS01);
			break;
			case PRESCALAR_256:	//start with prescalar clk/256
			TCCR0 |= (1<<CS02);
			break;
			case PRESCALAR_1024: //start with prescalar clk/1024
			TCCR0 |= (1<<CS00);
			TCCR0 |= (1<<CS02);
			break;
		}
		break;
		case TIMER_1:
		switch (prescalar){
			case NO_PRESCALAR:   //start with no prescalar
			TCCR1B |= (1<<CS10);
			break;
			case PRESCALAR_8:	//start with prescalar clk/8
			TCCR1B |= (1<<CS11);
			break;
			case PRESCALAR_64:	//start with prescalar clk/64
			TCCR1B |= (1<<CS10);
			TCCR1B |= (1<<CS11);
			break;
			case PRESCALAR_256:	//start with prescalar clk/256
			TCCR1B |= (1<<CS12);
			break;
			case PRESCALAR_1024: //start with prescalar clk/1024
			TCCR1B |= (1<<CS10);
			TCCR1B |= (1<<CS12);
			break;
		}
		break;
		case TIMER_2:
		switch (prescalar){
			case NO_PRESCALAR:   //start with no prescalar
			TCCR2 |= (1<<CS20);
			break;
			case PRESCALAR_8:	//start with prescalar clk/8
			TCCR2 |= (1<<CS21);
			break;
			case PRESCALAR_64:	//start with prescalar clk/64
			TCCR2 |= (1<<CS20);
			TCCR2 |= (1<<CS21);
			break;
			case PRESCALAR_256:	//start with prescalar clk/256
			TCCR2 |= (1<<CS22);
			break;
			case PRESCALAR_1024: //start with prescalar clk/1024
			TCCR2 |= (1<<CS20);
			TCCR2 |= (1<<CS21);
			TCCR2 |= (1<<CS22);
			break;
		}
		break;
	}
}

void TIMER_set_value( uint8_t timerNumber, uint8_t initValue) {
	switch (timerNumber){
		case TIMER_0:
		TCNT0 = initValue;
		break;
		case TIMER_1:
		TCNT1H = 0x00;
		TCNT1L = initValue;
		break;
		case TIMER_2:
		TCNT2 = initValue;
		break;
	}
}


void TIMER_delay( uint8_t timerNumber, uint8_t overFlows){
	uint8_t overflowCounter = 0;
	switch (timerNumber){
		case TIMER_0:
		while (overflowCounter < overFlows)
		{
			while ((TIFR & (1<<TOV0)) == 0);			//delay
			TIFR |= (1<<TOV0);							//clear overflow flag
			overflowCounter ++;							//increment no of overflows
		}
		break;
		case TIMER_1:
		while (overflowCounter < overFlows)
		{
			while ((TIFR & (1<<TOV1)) == 0);			//delay
			TIFR |= (1<<TOV1);							//clear overflow flag
			overflowCounter ++;							//increment no of overflows
		}
		break;
		case TIMER_2:
		while (overflowCounter < overFlows)
		{
			while ((TIFR & (1<<TOV2)) == 0);			//delay
			TIFR |= (1<<TOV2);							//clear overflow flag
			overflowCounter ++;							//increment no of overflows
		}
		break;
	}
}