#ifndef MAIN_H_
#define MAIN_H_

// Setting
#define MAX_TASKS 4U

// Stack memory calculation
#define SIZE_TASK_STACK			(1024U)
#define	SIZE_SCHED_STACK 		(1024U)

#define SRAM_START				(0x20000000U)
#define SIZE_RAM				((128) * (1024))
#define SRAM_END				((SRAM_START) + (SIZE_RAM))

#define T1_STACK_START			SRAM_END
#define T2_STACK_START			((SRAM_END) - (SIZE_TASK_STACK) * (1))
#define T3_STACK_START			((SRAM_END) - (SIZE_TASK_STACK) * (2))
#define T4_STACK_START			((SRAM_END) - (SIZE_TASK_STACK) * (3))
#define SCHED_STACK_START		((SRAM_END) - (SIZE_TASK_STACK) * (4))

#define TICK_HZ 			1000U

#define HSI_CLOCK			16000000U
#define SYSTICK_TIM_CLK 	HSI_CLOCK

#define DUMMY_XPSR 0x01000000U

#define TASK_RUNNING_STATE 0x00
#define TASK_BLOCKED_STATE 0xFF

#endif /* MAIN_H_ */
