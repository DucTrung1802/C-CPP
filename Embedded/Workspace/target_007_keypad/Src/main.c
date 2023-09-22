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

#include <stdio.h>
#include <stdint.h>
#include "main.h"

#define DELAY_AMOUNT 300000

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* Used pins
 *
 * PC1 - C4 (input)
 * PC3 - C3 (input)
 * PA1 - C2 (input)
 * PA3 - C1 (input)
 * PA5 - R4 (output)
 * PA7 - R3 (output)
 * PC5 - R2 (output)
 * PB1 - R1 (output)
 *
 */

void delayms(uint32_t const time_value);

int main(void)
{
	/* Reset and clock control reg */
	RCC_AHB1_ENR_t
	volatile *const p_clock_control_reg = (RCC_AHB1_ENR_t*) (RCC + 0x30);

	/* GPIO A Configuration */
	p_clock_control_reg->gpio_a_en = 1;
	GPIOx_MODE_REG_t volatile *const p_port_a_mode_reg =
			(GPIOx_MODE_REG_t*) GPIO_A;
	GPIOx_PUPDR_t volatile *const p_port_a_pull_reg = (GPIOx_PUPDR_t*) (GPIO_A
			+ 0x0C);
	GPIOx_IDR_t volatile const *const p_port_a_input_reg =
			(GPIOx_IDR_t*) (GPIO_A + 0x10);
	GPIOx_ODR_t volatile *const p_port_a_output_reg = (GPIOx_ODR_t*) (GPIO_A
			+ 0x14);

	/* GPIO B Configuration */
	p_clock_control_reg->gpio_b_en = 1;
	GPIOx_MODE_REG_t volatile *const p_port_b_mode_reg =
			(GPIOx_MODE_REG_t*) GPIO_B;
	GPIOx_PUPDR_t volatile *const p_port_b_pull_reg = (GPIOx_PUPDR_t*) (GPIO_B
			+ 0x0C);
	GPIOx_IDR_t volatile const *const p_port_b_input_reg =
			(GPIOx_IDR_t*) (GPIO_B + 0x10);
	GPIOx_ODR_t volatile *const p_port_b_output_reg = (GPIOx_ODR_t*) (GPIO_B
			+ 0x14);

	/* GPIO C Configuration */
	p_clock_control_reg->gpio_c_en = 1;
	GPIOx_MODE_REG_t volatile *const p_port_c_mode_reg =
			(GPIOx_MODE_REG_t*) GPIO_C;
	GPIOx_PUPDR_t volatile *const p_port_c_pull_reg = (GPIOx_PUPDR_t*) (GPIO_C
			+ 0x0C);
	GPIOx_IDR_t volatile const *const p_port_c_input_reg =
			(GPIOx_IDR_t*) (GPIO_C + 0x10);
	GPIOx_ODR_t volatile *const p_port_c_output_reg = (GPIOx_ODR_t*) (GPIO_C
			+ 0x14);

	/* Input pins */
	/* PC1 - C4 (input) */
	p_port_c_mode_reg->pin_1 = INPUT_MODE;
	p_port_c_pull_reg->pin_1 = PULL_UP;

	/* PC3 - C3 (input) */
	p_port_c_mode_reg->pin_3 = INPUT_MODE;
	p_port_c_pull_reg->pin_3 = PULL_UP;

	/* PA1 - C2 (input) */
	p_port_a_mode_reg->pin_1 = INPUT_MODE;
	p_port_a_pull_reg->pin_1 = PULL_UP;

	/* PA3 - C1 (input) */
	p_port_a_mode_reg->pin_3 = INPUT_MODE;
	p_port_a_pull_reg->pin_3 = PULL_UP;

	/* Output pins */
	/* PA5 - R4 (output) */
	p_port_a_mode_reg->pin_5 = OUTPUT_MODE;

	/* PA7 - R3 (output) */
	p_port_a_mode_reg->pin_7 = OUTPUT_MODE;

	/* PC5 - R2 (output) */
	p_port_c_mode_reg->pin_5 = OUTPUT_MODE;

	/* PB1 - R1 (output) */
	p_port_b_mode_reg->pin_1 = OUTPUT_MODE;

	printf("Hello world!\n");

	/* Set output high */
	p_port_b_output_reg->pin_1 = 1;
	p_port_c_output_reg->pin_5 = 1;
	p_port_a_output_reg->pin_7 = 1;
	p_port_a_output_reg->pin_5 = 1;

	/* Loop forever */
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			switch (i)
			{
			case 0:
				p_port_b_output_reg->pin_1 = 0;

				for (int j = 0; j < 4; j++)
				{
					switch (j)
					{
					case 0:
						if (!(p_port_a_input_reg->pin_3))
						{
							delayms(DELAY_AMOUNT);
							printf("1\n");
						}
						break;

					case 1:
						if (!(p_port_a_input_reg->pin_1))
						{
							delayms(DELAY_AMOUNT);
							printf("2\n");
						}
						break;

					case 2:
						if (!(p_port_c_input_reg->pin_3))
						{
							delayms(DELAY_AMOUNT);
							printf("3\n");
						}
						break;

					case 3:
						if (!(p_port_c_input_reg->pin_1))
						{
							delayms(DELAY_AMOUNT);
							printf("A\n");
						}
						break;
					}
				}

				p_port_b_output_reg->pin_1 = 1;
				break;

			case 1:
				p_port_c_output_reg->pin_5 = 0;

				for (int j = 0; j < 4; j++)
				{
					switch (j)
					{
					case 0:
						if (!(p_port_a_input_reg->pin_3))
						{
							delayms(DELAY_AMOUNT);
							printf("4\n");
						}
						break;

					case 1:
						if (!(p_port_a_input_reg->pin_1))
						{
							delayms(DELAY_AMOUNT);
							printf("5\n");
						}
						break;

					case 2:
						if (!(p_port_c_input_reg->pin_3))
						{
							delayms(DELAY_AMOUNT);
							printf("6\n");
						}
						break;

					case 3:
						if (!(p_port_c_input_reg->pin_1))
						{
							delayms(DELAY_AMOUNT);
							printf("B\n");
						}
						break;
					}
				}

				p_port_c_output_reg->pin_5 = 1;
				break;

			case 2:
				p_port_a_output_reg->pin_7 = 0;

				for (int j = 0; j < 4; j++)
				{
					switch (j)
					{
					case 0:
						if (!(p_port_a_input_reg->pin_3))
						{
							delayms(DELAY_AMOUNT);
							printf("7\n");
						}
						break;

					case 1:
						if (!(p_port_a_input_reg->pin_1))
						{
							delayms(DELAY_AMOUNT);
							printf("8\n");
						}
						break;

					case 2:
						if (!(p_port_c_input_reg->pin_3))
						{
							delayms(DELAY_AMOUNT);
							printf("9\n");
						}
						break;

					case 3:
						if (!(p_port_c_input_reg->pin_1))
						{
							delayms(DELAY_AMOUNT);
							printf("C\n");
						}
						break;
					}
				}

				p_port_a_output_reg->pin_7 = 1;
				break;

			case 3:
				p_port_a_output_reg->pin_5 = 0;

				for (int j = 0; j < 4; j++)
				{
					switch (j)
					{
					case 0:
						if (!(p_port_a_input_reg->pin_3))
						{
							delayms(DELAY_AMOUNT);
							printf("*\n");
						}
						break;

					case 1:
						if (!(p_port_a_input_reg->pin_1))
						{
							delayms(DELAY_AMOUNT);
							printf("0\n");
						}
						break;

					case 2:
						if (!(p_port_c_input_reg->pin_3))
						{
							delayms(DELAY_AMOUNT);
							printf("#\n");
						}
						break;

					case 3:
						if (!(p_port_c_input_reg->pin_1))
						{
							delayms(DELAY_AMOUNT);
							printf("D\n");
						}
						break;
					}
				}

				p_port_a_output_reg->pin_5 = 1;
				break;
			}
		}

	}
}

void delayms(uint32_t const time_value)
{
	for (int i = time_value; i > 0; i--)
	{
		// NOP
	}
}
