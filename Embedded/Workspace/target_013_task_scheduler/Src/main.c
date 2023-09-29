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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void enableProcessorFaults();

__attribute__((naked)) void initSchedulerStack(
		uint32_t const sched_top_of_stack);
void initSystickTimer(uint32_t tick_hz);
void initTaskStacks();
__attribute__((naked)) void switchToPSP();
uint32_t getPSPValue();

void task1_handler();
void task2_handler();
void task3_handler();
void task4_handler();

uint32_t psp_of_tasks[MAX_TASKS] =
{ T1_STACK_START, T2_STACK_START, T3_STACK_START, T4_STACK_START };

uint32_t task_handlers[MAX_TASKS];

uint8_t current_task = 0; // task 1 is running

int main(void)
{
	printf("Hello\n");

	enableProcessorFaults();

	initSchedulerStack(SCHED_STACK_START);

	task_handlers[0] = (uint32_t) task1_handler;
	task_handlers[1] = (uint32_t) task2_handler;
	task_handlers[2] = (uint32_t) task3_handler;
	task_handlers[3] = (uint32_t) task4_handler;

	initTaskStacks();

	initSystickTimer(TICK_HZ);

	switchToPSP();

	task1_handler();

	/* Loop forever */
	for (;;)
		;
}

void task1_handler()
{
	while (1)
	{
		printf("This is task 1\n");
	}
}

void task2_handler()
{
	while (1)
	{
		printf("This is task 2\n");
	}
}

void task3_handler()
{
	while (1)
	{
		printf("This is task 3\n");
	}
}

void task4_handler()
{
	while (1)
	{
		printf("This is task 4\n");
	}
}

void enableProcessorFaults()
{
	uint32_t *pSHCSR = (uint32_t*) 0xE000ED24;

	*pSHCSR |= (1 << 16); // mem manage
	*pSHCSR |= (1 << 17); // bus fault
	*pSHCSR |= (1 << 18); // usage fault
}

void initSystickTimer(uint32_t tick_hz)
{
	// SysTick Reload Value Register
	uint32_t volatile *const pSRVR = (uint32_t*) 0xE000E014;

	// SysTick Control and Status Register
	uint32_t volatile *const pSCSR = (uint32_t*) 0xE000E010;

	uint32_t count_value = (SYSTICK_TIM_CLK / tick_hz) - 1;

	// Clear the value of pSRVR
	*pSRVR &= ~(0x00FFFFFF);

	// Load the reload value into pSRVR
	*pSRVR |= count_value;

	// Do some configuration
	*pSCSR |= (1 << 1);
	*pSCSR |= (1 << 2);

	// Enable the systick
	*pSCSR |= (1 << 0);
}

__attribute__((naked)) void initSchedulerStack(
		uint32_t const sched_top_of_stack)
{
	__asm volatile ("MSR MSP,%0"::"r"(sched_top_of_stack):);

	// Return from function call ( main() )
	__asm volatile ("BX LR");
}

void initTaskStacks()
{
	uint32_t *pPSP;

	for (int i = 0; i < MAX_TASKS; i++)
	{
		pPSP = (uint32_t*) psp_of_tasks[i];

		// XPSR
		pPSP--;
		*pPSP = DUMMY_XPSR; // 0x01000000 - just turn on T bit

		// PC
		pPSP--;
		*pPSP = task_handlers[i];

		// LR
		pPSP--;
		*pPSP = 0xFFFFFFFD;

		for (int j = 0; j < 13; j++)
		{
			pPSP--;
			*pPSP = 0;
		}
	}
}

__attribute__((naked)) void switchToPSP()
{
	// 1. Initialize the PSP with task 1 stack start

	// Get the value of PSP of current stack

	// Preserve LR which connects back to main()
	__asm volatile ("PUSH {LR}");
	__asm volatile ("BL getPSPValue");

	// Initialize PSP
	__asm volatile ("MSR PSP,R0");

	// Pops back LR value
	__asm volatile ("POP {LR}");

	// 2. Change SP to PSP using CONTROL register
	__asm volatile ("MOV R0,#0x02");
	__asm volatile ("MSR CONTROL,R0");

	// Return from function call ( main() )
	__asm volatile ("BX LR");
}

uint32_t getPSPValue()
{
	return psp_of_tasks[current_task];
}

void SysTick_Handler()
{

}
