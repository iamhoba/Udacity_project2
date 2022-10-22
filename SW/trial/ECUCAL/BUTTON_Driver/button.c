/*
 * button.c
 *
 * Created: 9/17/2022 9:22:00 PM
 *  Author: Ahmed Ehab
 */ 

#include "button.h"

/*Initialize button*/
uint8_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin){
	return DIO_init(buttonPort,buttonPin,IN);
}

/*read button state*/
uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value){
	return DIO_read(buttonPort,buttonPin, value);
}

/*initialize button external interrupt*/
uint8_t BUTTON_INT_init(uint8_t buttonPort, uint8_t buttonPin){
		INT_init();					//enable global interrupts
		return EXT_INT_init(INT0);	//enable external interrupt
}