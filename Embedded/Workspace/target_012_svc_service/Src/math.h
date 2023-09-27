#ifndef MATH_H_
#define MATH_H_

#include <stdio.h>
#include <stdint.h>

/**
 * IMPORTANT: to extract the argument of SVC in handler function,
 * we have to write it in __attribute__ ((naked)) as follow
 * "__attribute__ ((naked)) void SVC_Handler(void)"
 * since "In assembly language programming, the function prologue
 * is a few lines of ASM code at the beginning of a function,
 * which prepare the stack! and registers for use within the function".
 * Therefore, we will lose the value of SVC argument.
 *
 * With __attribute__ ((naked)), there is no prologue, so we can get the exact
 * value of MSP in stack, then we can extract the value of SVC argument!
 *
 */
__attribute__ ((naked)) void SVC_Handler();

void SVC_Handler_C(uint32_t volatile *const p_base_of_stack_frame,
		float const operand_1, float const operand_2);

float add(float const operand_1, float const operand_2);
float subtract(float const operand_1, float const operand_2);
float multiply(float const operand_1, float const operand_2);
float divide(float const operand_1, float const operand_2);

#endif /* MATH_H_ */
