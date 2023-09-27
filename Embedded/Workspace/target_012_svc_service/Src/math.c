#include "math.h"

static float internalAdd(float const operand_1, float const operand_2)
{
	return (float) (operand_1 + operand_2);
}
static float internalSubtract(float const operand_1, float const operand_2)
{
	return (float) (operand_1 - operand_2);
}
static float internalMultiply(float const operand_1, float const operand_2)
{
	return (float) (operand_1 * operand_2);
}
static float internalDivide(float const operand_1, float const operand_2)
{
	return (float) (operand_1 / operand_2);
}

__attribute__ ((naked)) void SVC_Handler(void)
{
	// 1. Get the value of MSP
	__asm volatile ("MRS R0,MSP");
	__asm volatile ("MOV R1,R3");
	__asm volatile ("B SVC_Handler_C");
}

void SVC_Handler_C(uint32_t volatile *const p_base_of_stack_frame,
		float const operand_1, float const operand_2)
{
	printf("In SVC handler\n");
	// 2. Increment the pointer to the base of the stack frame by 6 to get the return address
	// of the program counter (check slide "How to extract the SVC number")
	uint8_t volatile *p_return_addr = (uint8_t*) p_base_of_stack_frame[6];

	// 3. Decrement the return address by 2 to point to
	// opcode of the SVC instruction in the program memory (check Show view Disassembly)
	p_return_addr -= 2;

	// 4. Extract the SVC number
	uint8_t const svc_number = *p_return_addr;
	printf("SVC service number is %u\n", svc_number);

	float result = 0;
	switch (svc_number)
	{
	case 36:
		result = internalAdd(operand_1, operand_2);
		break;
	case 37:
		result = internalSubtract(operand_1, operand_2);
		break;
	case 38:
		result = internalMultiply(operand_1, operand_2);
		break;
	case 39:
		result = internalDivide(operand_1, operand_2);
		break;
	default:
		// NOP
	}

	// Type punning to store the float result as a binary representation
	uint32_t result_binary;
	memcpy(&result_binary, &result, sizeof(result));

	// Assign the binary representation to p_base_of_stack_frame[0]
	p_base_of_stack_frame[0] = result_binary;
}

float add(float const operand_1, float const operand_2)
{
	float result;
	__asm volatile ("SVC #36"::"r"(operand_1),"r"(operand_2):);
	__asm volatile ("MOV %0,r0":"=r"(result)::);
	return result;
}

float subtract(float const operand_1, float const operand_2)
{
	float result;
	__asm volatile ("SVC #37"::"r"(operand_1),"r"(operand_2):);
	__asm volatile ("MOV %0,r0":"=r"(result)::);
	return result;
}

float multiply(float const operand_1, float const operand_2)
{
	float result;
	__asm volatile ("SVC #38"::"r"(operand_1),"r"(operand_2):);
	__asm volatile ("MOV %0,r0":"=r"(result)::);
	return result;
}

float divide(float const operand_1, float const operand_2)
{
	float result;
	__asm volatile ("SVC #39"::"r"(operand_1),"r"(operand_2):);
	__asm volatile ("MOV %0,r0":"=r"(result)::);
	return result;
}
