#include "onboard_leds.h"

uint32_t static volatile *const p_clock_control_reg = (uint32_t*) 0x40023830;
uint32_t static volatile *const p_port_d_mode_reg = (uint32_t*) 0x40020C00;
uint32_t static volatile *const p_port_d_output_reg = (uint32_t*) 0x40020C14;

static void Basic_Init()
{
	*p_clock_control_reg |= (1 << 3);
}

void Init_Onboard_LEDs()
{
	Green_LED_Init();
	Orange_LED_Init();
	Red_LED_Init();
	Blue_LED_Init();
}

void Green_LED_Init()
{
	Basic_Init();
	// Configure the mode of the IO pin as output
	// a. Clear the 24th and 25th bit position (CLEAR)
	*p_port_d_mode_reg &= ~(3 << 24);
	// b. Make 24th bit as 1 (SET)
	*p_port_d_mode_reg |= (1 << 24);
}

void Orange_LED_Init()
{
	Basic_Init();
	// Configure the mode of the IO pin as output
	// a. Clear the 26th and 27th bit position (CLEAR)
	*p_port_d_mode_reg &= ~(3 << 26);
	// b. Make 26th bit as 1 (SET)
	*p_port_d_mode_reg |= (1 << 26);
}

void Red_LED_Init()
{
	Basic_Init();
	// Configure the mode of the IO pin as output
	// a. Clear the 28th and 29th bit position (CLEAR)
	*p_port_d_mode_reg &= ~(3 << 28);
	// b. Make 28th bit as 1 (SET)
	*p_port_d_mode_reg |= (1 << 28);
}

void Blue_LED_Init()
{
	Basic_Init();
	// Configure the mode of the IO pin as output
	// a. Clear the 30th and 31st bit position (CLEAR)
	*p_port_d_mode_reg &= ~(3 << 30);
	// b. Make 30th bit as 1 (SET)
	*p_port_d_mode_reg |= (1 << 30);
}

void All_LEDs_On()
{
	Green_LED_On();
	Red_LED_On();
	Orange_LED_On();
	Blue_LED_On();
}

void All_LEDs_Off()
{
	Green_LED_Off();
	Red_LED_Off();
	Orange_LED_Off();
	Blue_LED_Off();
}

void All_LEDs_Toggle()
{
	Green_LED_Toggle();
	Red_LED_Toggle();
	Orange_LED_Toggle();
	Blue_LED_Toggle();
}

void Green_LED_On()
{
	// Set 12th bit of the output data register to make I/O pin-12 as HIGH
	*p_port_d_output_reg |= (1 << 12);
}

void Green_LED_Off()
{
	// Clear 12th bit of the output data register to make I/O pin-12 as LOW
	*p_port_d_output_reg &= ~(1 << 12);
}

void Green_LED_Toggle()
{
	// XOR 12th bit of the output data register to make I/O pin-12 with 1
	*p_port_d_output_reg ^= (1 << 12);
}

void Orange_LED_On()
{
	// Set 13th bit of the output data register to make I/O pin-13 as HIGH
	*p_port_d_output_reg |= (1 << 13);
}

void Orange_LED_Off()
{
	// Clear 13th bit of the output data register to make I/O pin-13 as LOW
	*p_port_d_output_reg &= ~(1 << 13);
}

void Orange_LED_Toggle()
{
	// XOR 13th bit of the output data register to make I/O pin-13 with 1
	*p_port_d_output_reg ^= (1 << 13);
}

void Red_LED_On()
{
	// Set 14th bit of the output data register to make I/O pin-14 as HIGH
	*p_port_d_output_reg |= (1 << 14);
}

void Red_LED_Off()
{
	// Clear 14th bit of the output data register to make I/O pin-14 as LOW
	*p_port_d_output_reg &= ~(1 << 14);
}

void Red_LED_Toggle()
{
	// XOR 14th bit of the output data register to make I/O pin-14 with 1
	*p_port_d_output_reg ^= (1 << 14);
}

void Blue_LED_On()
{
	// Set 15th bit of the output data register to make I/O pin-15 as HIGH
	*p_port_d_output_reg |= (1 << 15);
}

void Blue_LED_Off()
{
	// Clear 15th bit of the output data register to make I/O pin-15 as LOW
	*p_port_d_output_reg &= ~(1 << 15);
}

void Blue_LED_Toggle()
{
	// XOR 15th bit of the output data register to make I/O pin-15 with 1
	*p_port_d_output_reg ^= (1 << 15);
}

