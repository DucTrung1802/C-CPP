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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/* RCC */
#define RCC_BASE_ADDR 			0x40023800UL

#define RCC_CR_OFFSET 			0x00UL
#define RCC_CR_ADDR				((RCC_BASE_ADDR) + (RCC_CR_OFFSET))

#define RCC_CFGR_OFFSET			0x08UL
#define RCC_CFGR_ADDR			((RCC_BASE_ADDR) + (RCC_CFGR_OFFSET))

#define RCC_AHB1ENR_OFFSET		0x30UL
#define RCC_AHB1ENR_ADDR		((RCC_BASE_ADDR) + (RCC_AHB1ENR_OFFSET))

/* GPIOA */
#define GPIOA_BASE_ADDR			0x40020000UL

#define GPIOA_MODER_OFFSET		0x00UL
#define GPIOA_MODER_ADDR		((GPIOA_BASE_ADDR) + (GPIOA_MODER_OFFSET))

#define GPIOA_AFRH_OFFSET		0x24UL
#define GPIOA_AFRH_ADDR			((GPIOA_BASE_ADDR) + (GPIOA_AFRH_OFFSET))

int main(void) {
	uint32_t volatile *const p_rcc_cr_addr = (uint32_t*) RCC_CR_ADDR;
	uint32_t volatile *const p_rcc_cfgr_addr = (uint32_t*) RCC_CFGR_ADDR;
	uint32_t volatile *const p_rcc_ahb1enr_addr = (uint32_t*) RCC_AHB1ENR_ADDR;

	uint32_t volatile *const p_gpioa_moder_addr = (uint32_t*) GPIOA_MODER_ADDR;
	uint32_t volatile *const p_gpioa_afrh_addr = (uint32_t*) GPIOA_AFRH_ADDR;

	// 1. Turn on RCC (this is configured as default when the MCU is reset)
	*p_rcc_cr_addr |= (1 << 0);

	// 2. Set clock source MCO1 using HSI (Microcontroller clock output 1)
	*p_rcc_cfgr_addr &= ~(3 << 21);

	// 3. Enable AHB1 bus for GPIOA
	*p_rcc_ahb1enr_addr |= (1 << 0);

	// 4. Configure mode of GPIOA 8 is alternative function
	*p_gpioa_moder_addr &= ~(3 << 16);
	*p_gpioa_moder_addr |= (2 << 16);

	// 5. Configure PA8 as alternative function AF00
	*p_gpioa_afrh_addr &= ~(0x0f << 0);

	/* Loop forever */
	for (int i = 0; i < 300000; i++) {
		// NOP
	}
}
