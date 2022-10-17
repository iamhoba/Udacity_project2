/*
 * application.h
 *
 * Created: 9/17/2022 7:33:44 PM
 *  Author: Ahmed Ehab
 */ 



#ifndef APPLICATION_H_
#define APPLICATION_H_

//all driver includes
#include "../ECUCAL/LED_Driver/led.h"
#include "../ECUCAL/BUTTON_Driver/button.h"

//all driver macros
#define NUMBER_OF_LEDS 3
#define NORMAL_MODE 0
#define PEDESTRIAN_MODE 1
#define OVERFLOWS 305

//all driver functions prototypes
void App_start(void);
void App_init(void);


#endif /* APPLICATION_H_ */