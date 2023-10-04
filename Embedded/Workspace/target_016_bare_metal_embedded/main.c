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
#include "onboard_leds.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

// Semihosting function prototype
extern void initialise_monitor_handles(void);

void Enable_Processor_Faults();

void Init_Systick_Timer(uint32_t tick_hz);
__attribute__((naked)) void Init_Scheduler_Stack(
	uint32_t const sched_top_of_stack);
void Init_Task_Stacks();
__attribute__((naked)) void Switch_To_PSP();
void Save_PSP_Value(uint32_t const stack_addr);
uint32_t Get_PSP_Value();
void Update_Next_Task();
void Update_Global_Tick_Count();
void Unblock_Task();

void SysTick_Handler();
__attribute__((naked)) void PendSV_Handler();
void MemManage_Handler();
void BusFault_Handler();
void UsageFault_Handler();
void HardFault_Handler();

void Idle_Task();
void Task1_Handler();
void Task2_Handler();
void Task3_Handler();
void Task4_Handler();

void Schedule();
void Task_Delay(uint32_t tick_count);

uint32_t volatile g_tick_count = 0;
uint8_t volatile current_task = 1; // task 1 is running (should always start with main task)

// Task Control Block
typedef struct
{
	uint32_t psp_value;
	uint32_t block_count;
	uint8_t current_state;
	void (*task_handler)(void);
} TCB_t;

TCB_t user_tasks[MAX_TASKS];

int main(void)
{
	Enable_Processor_Faults();

	initialise_monitor_handles();

	printf("Hello\n");

	Init_Onboard_LEDs();

	Init_Scheduler_Stack(SCHED_STACK_START);

	Init_Task_Stacks();

	Init_Systick_Timer(TICK_HZ);

	Switch_To_PSP();

	Task1_Handler();

	/* Loop forever */
	for (;;)
		;
}

void Idle_Task()
{
	while (1)
		;
}

void Task1_Handler()
{
	uint32_t volatile timer = 0;
	while (1)
	{
		if (g_tick_count - timer >= 1000)
		{
			printf("Task_1\n");
			Green_LED_Toggle();
			timer = g_tick_count;
		}
	}
}

void Task2_Handler()
{
	uint32_t volatile timer = 0;
	while (1)
	{
		if (g_tick_count - timer >= 500)
		{
			printf("Task_2\n");
			Red_LED_Toggle();
			timer = g_tick_count;
		}
	}
}

void Task3_Handler()
{
	uint32_t volatile timer = 0;
	while (1)
	{
		if (g_tick_count - timer >= 250)
		{
			printf("Task_3\n");
			Orange_LED_Toggle();
			timer = g_tick_count;
		}
	}
}

void Task4_Handler()
{
	uint32_t volatile timer = 0;
	while (1)
	{
		if (g_tick_count - timer >= 125)
		{
			printf("Task_4\n");
			Blue_LED_Toggle();
			timer = g_tick_count;
		}
	}
}

void Enable_Processor_Faults()
{
	uint32_t *pSHCSR = (uint32_t *)0xE000ED24;

	*pSHCSR |= (1 << 16); // mem manage
	*pSHCSR |= (1 << 17); // bus fault
	*pSHCSR |= (1 << 18); // usage fault
}

void Init_Systick_Timer(uint32_t tick_hz)
{
	// SysTick Reload Value Register
	uint32_t volatile *const pSRVR = (uint32_t *)0xE000E014;

	// SysTick Control and Status Register
	uint32_t volatile *const pSCSR = (uint32_t *)0xE000E010;

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

__attribute__((naked)) void Init_Scheduler_Stack(
	uint32_t const sched_top_of_stack)
{
	__asm volatile("MSR MSP,%0" ::"r"(sched_top_of_stack)
				   :);

	// Return from function call ( main() )
	__asm volatile("BX LR");
}

void Init_Task_Stacks()
{

	uint32_t *pPSP;

	user_tasks[0].psp_value = IDLE_STACK_START;
	user_tasks[1].psp_value = T1_STACK_START;
	user_tasks[2].psp_value = T2_STACK_START;
	user_tasks[3].psp_value = T3_STACK_START;
	user_tasks[4].psp_value = T4_STACK_START;

	user_tasks[0].task_handler = Idle_Task;
	user_tasks[1].task_handler = Task1_Handler;
	user_tasks[2].task_handler = Task2_Handler;
	user_tasks[3].task_handler = Task3_Handler;
	user_tasks[4].task_handler = Task4_Handler;

	for (int i = 0; i < MAX_TASKS; i++)
	{
		user_tasks[i].current_state = TASK_READY_STATE;

		pPSP = (uint32_t *)user_tasks[i].psp_value;

		// XPSR
		pPSP--;
		*pPSP = DUMMY_XPSR; // 0x01000000 - just turn on T bit

		// PC
		pPSP--;
		*pPSP = (uint32_t)user_tasks[i].task_handler;

		// LR
		pPSP--;
		*pPSP = 0xFFFFFFFD;

		for (int j = 0; j < 13; j++)
		{
			pPSP--;
			*pPSP = 0;
		}

		user_tasks[i].psp_value = (uint32_t)pPSP;
	}
}

__attribute__((naked)) void Switch_To_PSP()
{
	// 1. Initialize the PSP with task 1 stack start

	// Get the value of PSP of current stack

	// Preserve LR which connects back to main()
	__asm volatile("PUSH {LR}");
	__asm volatile("BL Get_PSP_Value");

	// Initialize PSP
	__asm volatile("MSR PSP,R0");

	// Pops back LR value
	__asm volatile("POP {LR}");

	// 2. Change SP to PSP using CONTROL register
	__asm volatile("MOV R0,#0x02");
	__asm volatile("MSR CONTROL,R0");

	// Return from function call ( main() )
	__asm volatile("BX LR");
}

void Save_PSP_Value(uint32_t const stack_addr)
{
	user_tasks[current_task].psp_value = stack_addr;
}

uint32_t Get_PSP_Value()
{
	return user_tasks[current_task].psp_value;
}

void Update_Next_Task()
{
	do
	{
		current_task++;
		current_task %= MAX_TASKS;
	} while (user_tasks[current_task].current_state == TASK_BLOCKED_STATE || !current_task);
}

void Task_Delay(uint32_t tick_count)
{
	// To get rid of race condition, should disable interrupt before execute this function
	// since thread mode and handler mode both access global variable "user_tasks"

	// Disable all interrupts
	INTERRUPT_DISABLE();

	if (current_task)
	{
		user_tasks[current_task].block_count = g_tick_count + tick_count;
		user_tasks[current_task].current_state = TASK_BLOCKED_STATE;
		Schedule();
	}

	// Enable all interrupts
	INTERRUPT_ENABLE();
}

void Schedule()
{
	// Pend PendSV
	uint32_t volatile *const pICSR = (uint32_t *)0xE000ED04;

	*pICSR |= (1 << 28);
}

void Update_Global_Tick_Count()
{
	g_tick_count++;
}

void Unblock_Task()
{
	for (int i = 0; i < MAX_TASKS; i++)
	{
		if (user_tasks[i].current_state != TASK_READY_STATE)
		{
			if (user_tasks[i].block_count == g_tick_count)
			{
				user_tasks[i].current_state = TASK_READY_STATE;
			}
		}
	}
}

void SysTick_Handler()
{
	uint32_t volatile *const pICSR = (uint32_t *)0xE000ED04;

	// 1. Update global tick count
	Update_Global_Tick_Count();

	// 2. Unblock tasks
	Unblock_Task();

	// 3. Pend PendSV
	*pICSR |= (1 << 28);
}

__attribute__((naked)) void PendSV_Handler()
{
	/* Save the context of current task */

	// 1. Get current running task's PSP value
	__asm volatile("MRS R0,PSP");

	// 2. Using that PSP value to store SF2 (R4 to R11)
	// Just like PUSH instruction but CANNOT use PUSH instruction
	// since this is handler, MSP will be affected.
	// => Use STORE operation
	// Use STMDB instruction (Example syntax: "STMDB R1!,{R3-R6,R11,R12}")
	// "Rn!" symbol is use to load final address to Rn register
	__asm volatile("STMDB R0!,{R4-R11}");

	// 3. PUSH LR
	__asm volatile("PUSH {LR}");

	// 4. Save the current value of PSP
	__asm volatile("BL Save_PSP_Value");

	/* Retrieve the context of next task */

	// 1. Decide the next task to run
	__asm volatile("BL Update_Next_Task");

	// 2. Get its past PSP value
	__asm volatile("BL Get_PSP_Value");
	// at this moment, PSP value is in R0 register

	// 3. Using that PSP value retrieve SF2 (R4 to R11)
	__asm volatile("LDMIA R0!,{R4-R11}");

	// 4. Update PSP and exit
	__asm volatile("MSR PSP,R0");

	// 5. POP LR
	__asm volatile("POP {LR}");

	// 6. Return from function call
	__asm volatile("BX LR");
}

void MemManage_Handler()
{
	printf("MemManage_Handler\n");
	while (1)
		;
}

void BusFault_Handler()
{
	printf("BusFault_Handler\n");
	while (1)
		;
}

void UsageFault_Handler()
{
	printf("UsageFault_Handler\n");
	while (1)
		;
}

void HardFault_Handler()
{
	printf("HardFault_Handler\n");
	while (1)
		;
}
