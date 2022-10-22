/*
 * led.c
 *
 * Created: 9/10/2022 10:10:27 PM
 *  Author: Ahmed Ehab
 */ 

#include "led.h"

uint8_t LED_init(uint8_t ledPort, uint8_t ledPin){
	return DIO_init(ledPort,ledPin,OUT);
}

uint8_t LED_on(uint8_t ledPort, uint8_t ledPin){
	return DIO_write(ledPort,ledPin,HIGH);
}

uint8_t LED_off(uint8_t ledPort, uint8_t ledPin){
	return DIO_write(ledPort,ledPin,LOW);
}

uint8_t LED_toggle(uint8_t ledPort, uint8_t ledPin){
	uint8_t ledState = LOW;
	uint8_t check_read = ERROR;
	uint8_t check_on_off = ERROR;
	check_read = DIO_read(ledPort,ledPin,&ledState);
	if (check_read == ERROR){
		return ERROR;
	}
	if (ledState == LOW){
		check_on_off = LED_on(ledPort,ledPin);
		if (check_on_off == ERROR){
			return ERROR;
		}
	}
	else if (ledState == HIGH){
		check_on_off = LED_off(ledPort,ledPin);
		if (check_on_off == ERROR){
			return ERROR;
		}
	}
	return OK;
}

uint8_t LED_TIMER_init(){
	return TIMER_init(TIMER_0, NORMAL_MODE);
}

uint8_t LED_TIMER_start(){
	uint8_t check_set = ERROR;
	uint8_t check_start = ERROR;
	check_start = TIMER_set_value(TIMER_0,1);
	check_set = TIMER_start(TIMER_0, PRESCALAR_1024); 
	if ( check_start == ERROR || check_set == ERROR){
		return ERROR;
	}
	return OK;
}

uint8_t LED_TIMER_stop(){
	return TIMER_stop(TIMER_0);
}

uint8_t LED_TIMER_delay(){
	uint8_t check_set = ERROR;
	uint8_t check_start = ERROR;
	uint8_t check_stop = ERROR;
	uint8_t check_delay = ERROR;
	check_set = TIMER_set_value(TIMER_2,1);
	check_start = TIMER_start(TIMER_2, PRESCALAR_1024);
	check_delay = TIMER_delay(TIMER_2,30);
	check_stop = TIMER_stop(TIMER_2);
	if (check_set == ERROR || check_start == ERROR || check_stop == ERROR || check_delay ==ERROR){
		return ERROR;
	}
	return OK;
}

uint8_t LED_blink(uint8_t ledPort, uint8_t ledPin){
	uint8_t toggle = ERROR;
	uint8_t delay = ERROR;
	toggle = LED_toggle(ledPort,ledPin);
	delay = LED_TIMER_delay();
	if (toggle == ERROR || delay == ERROR){
		return ERROR;
	}
	return OK;
}

uint8_t LED_TIMER_INT_init(void){
	INT_init();						//Enable global interrupts
	return TIMER_INT_init(TIMER_0);	//Enable timer 0 interrupt
}