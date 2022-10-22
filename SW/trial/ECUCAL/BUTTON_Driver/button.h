/*
 * button.h
 *
 * Created: 9/17/2022 9:21:50 PM
 *  Author: Ahmed Ehab
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


/*All driver includes*/
#include "../../MCAL/DIO_Driver/dio.h"
#include "../../MCAL/Interrupt_Library/interrupt.h"

/*All driver functions prototypes*/
uint8_t BUTTON_init(uint8_t buttonPort, uint8_t buttonPin);					//initialize button
uint8_t BUTTON_INT_init(uint8_t buttonPort, uint8_t buttonPin);				//initialize button interrupt
uint8_t BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);	//read button state

/*All button macros*/
#define BUTTON_1_PORT PORT_D
#define BUTTON_1_PIN PIN_2


#endif /* BUTTON_H_ */