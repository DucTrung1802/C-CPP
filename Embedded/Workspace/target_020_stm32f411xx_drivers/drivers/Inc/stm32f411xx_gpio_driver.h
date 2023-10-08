#ifndef INC_STM32F411XX_GPIO_DRIVER_H_
#define INC_STM32F411XX_GPIO_DRIVER_H_

#include "stm32f411xx.h"

/*
 * Configuration structure for a GPIO pin
 */
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode; /* 			Possible values from @GPIO_MODES */
	uint8_t GPIO_PinSpeed; /* 			Possible values from @GPIO_SPEED */
	uint8_t GPIO_PinPuPdControl; /* 	Possible values from @GPIO_PULL */
	uint8_t GPIO_PinOPType; /* 			Possible values from @GPIO_OP_TYPE */
	uint8_t GPIO_PinAltFuncMode;
} GPIO_PinConfig_t;

/*
 * Handle structure for a GPIO pin
 */
typedef struct
{
	// Pointer to hold address of the GPIO peripheral
	GPIO_RegDef_t *pGPIOx; /* 			This holds the base address of the GPIO port to which the pin belongs */
	GPIO_PinConfig_t GPIO_PinConfig; /* This holds GPIO pin configuration settings */
} GPIO_Handler_t;

/*
 * @GPIO_MODES
 * GPIO pin possible modes
 */
#define GPIO_MODE_INPUT		0		/* Input */
#define GPIO_MODE_OUT		1		/* Output */
#define GPIO_MODE_ALT_FUNC 	2		/* Alternative function */
#define GPIO_MODE_ANALOG	3		/* Analog mode */
#define GPIO_MODE_IT_FE		4		/* Interrupt - falling edge */
#define GPIO_MODE_IT_RE		5		/* Interrupt - rising edge */
#define GPIO_MODE_IT_BE		6		/* Interrupt - both edges */

/*
 * @GPIO_OP_TYPE
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP		0		/* Output mode - push pull */
#define GPIO_OP_TYPE_OD		1		/* Output mode - open drain */

/*
 * @GPIO_SPEED
 * GPIO pin possible speeds
 */
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3

/*
 * @GPIO_PULL
 * GPIO pin possible pull-up / pull-down
 */
#define GPIO_NO_PULL		0
#define GPIO_PULL_UP		1
#define GPIO_PULL_DOWN		2

/*****************************************************************************************
 * 								APIs supported by this driver
 *			For more information about the APIs, please check the function definition
 *****************************************************************************************/

/*
 * Peripheral Clock Setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi);

/*
 * Init and DeInit
 */
void GPIO_Init(GPIO_Handler_t *pGPIOHandler);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,
		uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ Configuration and Handler
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandler(uint8_t PinNumber);

#endif /* INC_STM32F411XX_GPIO_DRIVER_H_ */
