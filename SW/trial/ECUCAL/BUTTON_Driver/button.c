/*
 * button.c
 *
 * Created: 9/17/2022 9:22:00 PM
 *  Author: Ahmed Ehab
 */ 

#include "button.h"

/*Initialize button*/
void BUTTON_init(uint8_t buttonPort, uint8_t buttonPin){
	DIO_init(buttonPort,buttonPin,IN);
}

/*read button state*/
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value){
	DIO_read(buttonPort,buttonPin, value);
}

/*initialize button external interrupt*/
void BUTTON_INT_init(uint8_t buttonPort, uint8_t buttonPin){
		EXT_INT_init(INT0);			//enable external interrupt
		INT_init();					//enable global interrupts
}