/*
 * application.c
 *
 * Created: 9/17/2022 7:33:32 PM
 *  Author: Ahmed Ehab
 */ 


#include "application.h"

uint8_t led_number = 1;
uint16_t overflowCounter = 0;
uint8_t mode = NORMAL_MODE;
uint8_t flag = LOW;

void App_init(void){
	LED_init(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	LED_init(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
	if (LED_init(LED_1_PORT,LED_1_PIN) == ERROR)
	{
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}				
	if (LED_init(LED_2_PORT,LED_2_PIN) == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
	if (LED_init(LED_3_PORT,LED_3_PIN) == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
	if (LED_init(LED_4_PORT,LED_4_PIN) == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
	if (LED_init(LED_5_PORT,LED_5_PIN) == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
	if (LED_init(LED_6_PORT,LED_6_PIN) == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
	if (LED_TIMER_init() == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
	if (BUTTON_init(BUTTON_1_PORT,BUTTON_1_PIN) == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
	if (BUTTON_INT_init(BUTTON_1_PORT,BUTTON_1_PIN) == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
	if (LED_TIMER_INT_init() == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
	if (LED_TIMER_start() == ERROR){
		LED_on(LED_INIT_ERROR_PORT, LED_INIT_ERROR_PIN);
	}
}

void App_start(void){
	switch (mode)
	{
		case NORMAL_MODE:
		switch (led_number)
		{
			case 1:
			if (LED_off(LED_2_PORT,LED_2_PIN) == ERROR)
			{
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_3_PORT,LED_3_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_4_PORT,LED_4_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_5_PORT,LED_5_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_on(LED_1_PORT,LED_1_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_on(LED_6_PORT,LED_6_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			flag = HIGH;
			break;
			case 2:
			if (LED_off(LED_1_PORT,LED_1_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_3_PORT,LED_3_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_4_PORT,LED_4_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_6_PORT,LED_6_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_toggle(LED_2_PORT,LED_2_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_toggle(LED_5_PORT,LED_5_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_TIMER_delay() == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			break;
			case 3:
			if (LED_off(LED_1_PORT,LED_1_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_2_PORT,LED_2_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_5_PORT,LED_5_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_6_PORT,LED_6_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_on(LED_3_PORT,LED_3_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_on(LED_4_PORT,LED_4_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			flag = LOW;
			break;
		}
		break;
		case PEDESTRIAN_MODE:
		switch (led_number)
		{
			case 1:
			mode = NORMAL_MODE;
			break;
			case 2:
			if (LED_off(LED_1_PORT,LED_1_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_3_PORT,LED_3_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_6_PORT,LED_6_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_toggle(LED_2_PORT,LED_2_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_toggle(LED_5_PORT,LED_5_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (flag == LOW){
				if (LED_on(LED_4_PORT,LED_4_PIN) == ERROR){
					LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
				}
			}
			else if (flag == HIGH){
				if (LED_off(LED_4_PORT,LED_4_PIN) == ERROR){
					LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
				}
			}
			if (LED_TIMER_delay() == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			break;
			case 3:
			if (LED_off(LED_1_PORT,LED_1_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_2_PORT,LED_2_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_5_PORT,LED_5_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_off(LED_6_PORT,LED_6_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_on(LED_3_PORT,LED_3_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			if (LED_on(LED_4_PORT,LED_4_PIN) == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			flag = LOW;
			break;
		}
		break;
		
	}
}




ISR(EXT_INT_0){
	if (mode == NORMAL_MODE){
		mode = PEDESTRIAN_MODE;
		if (led_number == 3 || led_number == 2)
		{
			if (LED_TIMER_stop() == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			overflowCounter = 0;
			if (LED_TIMER_start() == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
		}
		else if (led_number == 1)
		{
			led_number = 2;
			if (LED_TIMER_stop() == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
			overflowCounter = 0;
			if (LED_TIMER_start() == ERROR){
				LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
			}
		}
	}
}

ISR(TIMER_0_INT){
	if (overflowCounter >= OVERFLOWS){
		if (led_number == 1){
			led_number++;
		}
		else if (led_number == 3){
			led_number--;
		}
		else if (led_number == 2){
			if (flag == 0){
				led_number--;
			}
			else if (flag == 1){
				led_number++;
			}
		}
		overflowCounter = 0;
	}
	else{
		overflowCounter++;
	}
	if (LED_TIMER_start() == ERROR){
		LED_on(LED_RUN_ERROR_PORT, LED_RUN_ERROR_PIN);
	}
}