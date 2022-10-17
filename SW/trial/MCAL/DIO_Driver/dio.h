/*
 * dio.h
 *
 * Created: 9/10/2022 8:51:08 PM
 *  Author: Ahmed Ehab
 */ 


#ifndef DIO_H_
#define DIO_H_

/*All driver includes*/
#include "../../Utilities/registers.h"

/*All driver macros*/
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'


/*Pin macros*/
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_0 0

/*Direction defines*/
#define IN 0
#define OUT 1 

/*Values defines*/
#define LOW 0
#define HIGH 1


/*All driver function prototypes*/
void DIO_init(uint8_t portNumber, uint8_t pinNumber,uint8_t direction); //initialize dio direction
void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value); //write data to dio
void DIO_read(uint8_t portNumber, uint8_t pinNumber, uint8_t *value); //read dio




#endif /* DIO_H_ */