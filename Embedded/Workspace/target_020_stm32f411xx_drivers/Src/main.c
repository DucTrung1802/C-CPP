/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f411xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(void)
{
	for (int i = 0; i < 300000; i++)
		;
}

int main(void)
{
	GPIO_Handler_t GPIO_led_h;
	GPIO_led_h.pGPIOx = GPIOD;
	GPIO_led_h.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;
	GPIO_led_h.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	GPIO_led_h.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_led_h.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_led_h.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PULL;

	GPIO_Handler_t GPIO_button_h;
	GPIO_button_h.pGPIOx = GPIOA;
	GPIO_button_h.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;
	GPIO_button_h.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	GPIO_button_h.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GPIO_led_h);

	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIO_button_h);
	/* Loop forever */
	while (1)
	{
		if (GPIO_ReadFromInputPin(GPIOA, GPIO_PIN_NO_0) == GPIO_PIN_SET)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOD, GPIO_PIN_NO_12);
		}
	}
}
