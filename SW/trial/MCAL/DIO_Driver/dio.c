/*
 * dio.c
 *
 * Created: 9/10/2022 8:50:58 PM
 *  Author: Ahmed Ehab
 */ 

#include "dio.h"

void DIO_init(uint8_t portNumber, uint8_t pinNumber,uint8_t direction){
	switch(portNumber)
	{
		case PORT_A:
			if (direction == IN)
			{
				DDRA &= ~(1<<pinNumber); //input
			}
			else if (direction == OUT)
			{
				DDRA |= (1<<pinNumber); //output
			}
			else {
				//error handling
			}
		break;
		case PORT_B:
		if (direction == IN)
		{
			DDRB &= ~(1<<pinNumber); //input
		}
		else if (direction == OUT)
		{
			DDRB |= (1<<pinNumber); //output
		}
		else {
			//error handling
		}
		break;
		case PORT_C:
		if (direction == IN)
		{
			DDRC &= ~(1<<pinNumber); //input
		}
		else if (direction == OUT)
		{
			DDRC |= (1<<pinNumber); //output
		}
		else {
			//error handling
		}
		break;
		case PORT_D:
		if (direction == IN)
		{
			DDRD &= ~(1<<pinNumber); //input
		}
		else if (direction == OUT)
		{
			DDRD |= (1<<pinNumber); //output
		}
		else {
			//error handling
		}
		break;
		
	}
}

void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value){
	switch(portNumber)
	{
		case PORT_A:
		if (value == LOW)
		{
			PORTA &= ~(1<<pinNumber); //write 0
		}
		else if (value == HIGH)
		{
			PORTA |= (1<<pinNumber); //write 1
		}
		else {
			//error handling
		}
		break;
		case PORT_B:
		if (value == LOW)
		{
			PORTB &= ~(1<<pinNumber); //write 0
		}
		else if (value == HIGH)
		{
			PORTB |= (1<<pinNumber); //write 1
		}
		else {
			//error handling
		}
		break;
		case PORT_C:
		if (value == LOW)
		{
			PORTC &= ~(1<<pinNumber); //write 0
		}
		else if (value == HIGH)
		{
			PORTC |= (1<<pinNumber); //write 1
		}
		else {
			//error handling
		}
		break;
		case PORT_D:
		if (value == LOW)
		{
			PORTD &= ~(1<<pinNumber); //write 0
		}
		else if (value == HIGH)
		{
			PORTD |= (1<<pinNumber); //write 1
		}
		else {
			//error handling
		}
		break;
		
	}
}


void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value){
	switch(portNumber)
	{
		case PORT_A:
		*value = (PINA & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_B:
		*value = (PINB & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_C:
		*value = (PINC & (1<<pinNumber))>>pinNumber;
		break;
		case PORT_D:
		*value = (PIND & (1<<pinNumber))>>pinNumber;
		break;
		
	}
}