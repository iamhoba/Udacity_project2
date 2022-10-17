/*
 * led.h
 *
 * Created: 9/10/2022 10:10:58 PM
 *  Author: Ahmed Ehab
 */ 


#ifndef LED_H_
#define LED_H_

/*All driver includes*/
#include "../../MCAL/DIO_Driver/dio.h"
#include "../../MCAL/TIMER_Driver/timer.h"
#include "../../MCAL/Interrupt_Library/interrupt.h"

/*All driver macros*/
#define LED_1_PORT PORT_A
#define LED_1_PIN PIN_0

#define LED_2_PORT PORT_A
#define LED_2_PIN PIN_1

#define LED_3_PORT PORT_A
#define LED_3_PIN PIN_2

#define LED_4_PORT PORT_B
#define LED_4_PIN PIN_0

#define LED_5_PORT PORT_B
#define LED_5_PIN PIN_1

#define LED_6_PORT PORT_B
#define LED_6_PIN PIN_2


/*All driver function prototypes*/
void LED_init(uint8_t ledPort, uint8_t ledPin);				//initialize LED
void LED_on(uint8_t ledPort, uint8_t ledPin);				//Turn LED on
void LED_off(uint8_t ledPort, uint8_t ledPin);				//Turn LED off
void LED_toggle(uint8_t ledPort, uint8_t ledPin);			//Toggle LED
void LED_blink(uint8_t ledPort, uint8_t ledPin);			//Blink LED
void LED_TIMER_init(void);									//initialize LED timer
void LED_TIMER_start(void);									//Start LED timer
void LED_TIMER_INT_init(void);								//initialize LED interrupt
void LED_TIMER_stop(void);									//Stop LED timer
void LED_TIMER_delay(void);									//Busy delay function


#endif /* LED_H_ */