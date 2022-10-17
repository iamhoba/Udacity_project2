/*
 * led.c
 *
 * Created: 9/10/2022 10:10:27 PM
 *  Author: Ahmed Ehab
 */ 

#include "led.h"

void LED_init(uint8_t ledPort, uint8_t ledPin){
	DIO_init(ledPort,ledPin,OUT);
}
void LED_on(uint8_t ledPort, uint8_t ledPin){
	DIO_write(ledPort,ledPin,HIGH);
}
void LED_off(uint8_t ledPort, uint8_t ledPin){
	DIO_write(ledPort,ledPin,LOW);
}
void LED_toggle(uint8_t ledPort, uint8_t ledPin){
	uint8_t ledState;
	DIO_read(ledPort,ledPin,&ledState);
	if (ledState == LOW){
		LED_on(ledPort,ledPin);
	}
	else if (ledState == HIGH){
		LED_off(ledPort,ledPin);
	}
	else {
		//error handling
	}
}

void LED_TIMER_init(){
	TIMER_init(TIMER_0, NORMAL_MODE);
}

void LED_TIMER_start(){
	TIMER_set_value(TIMER_0,1);
	TIMER_start(TIMER_0, PRESCALAR_1024);
}

void LED_TIMER_stop(){
	TIMER_stop(TIMER_0);
}

void LED_TIMER_delay(){
	TIMER_set_value(TIMER_2,1);
	TIMER_start(TIMER_2, PRESCALAR_1024);
	TIMER_delay(TIMER_2,30);
	TIMER_stop(TIMER_2);
}

void LED_blink(uint8_t ledPort, uint8_t ledPin){
	LED_toggle(ledPort,ledPin);
	LED_TIMER_delay();
}

void LED_TIMER_INT_init(void){
	TIMER_INT_init(TIMER_0);			//Enable timer 0 interrupt
	INT_init();						//Enable global interrupts
}