#ifndef ONBOARD_LEDS_H_
#define ONBOARD_LEDS_H_

#include "stdint.h"

/*
 * This code handle onboard LEDs of STM32F411 DISCOVERY BOARD
 * There are 4 LEDs in total
 *
 * Left LED:	Green		PD 12
 * Upper LED: 	Orange		PD 13
 * Right LED: 	Red			PD 14
 * Lower LED: 	Blue		PD 15
 *
 */

void Init_Onboard_LEDs();
void Green_LED_Init();
void Orange_LED_Init();
void Red_LED_Init();
void Blue_LED_Init();

void All_LEDs_On();
void All_LEDs_Off();
void All_LEDs_Toggle();

void Green_LED_On();
void Green_LED_Off();
void Green_LED_Toggle();

void Orange_LED_On();
void Orange_LED_Off();
void Orange_LED_Toggle();

void Red_LED_On();
void Red_LED_Off();
void Red_LED_Toggle();

void Blue_LED_On();
void Blue_LED_Off();
void Blue_LED_Toggle();

#endif /* ONBOARD_LEDS_H_ */
