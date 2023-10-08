#include "stm32f411xx_gpio_driver.h"

/*
 * Peripheral Clock Setup
 */

/**
 * @fn void GPIO_PeriClockControl(GPIO_RegDef_t*, uint8_t)
 * @brief 	This function enable of disable the clock of the given GPIO port
 *
 * @param pGPIOx	Base address of the GPIO peripheral
 * @param EnorDi	Macro 'ENABLE' or 'DISABLE'
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{
	if (EnorDi)
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLOCK_EN();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLOCK_EN();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLOCK_EN();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLOCK_EN();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLOCK_EN();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLOCK_EN();
		}
	}
	else
	{
		if (pGPIOx == GPIOA)
		{
			GPIOA_PCLOCK_DI();
		}
		else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLOCK_DI();
		}
		else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLOCK_DI();
		}
		else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLOCK_DI();
		}
		else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLOCK_DI();
		}
		else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLOCK_DI();
		}
	}
}

/*
 * Init and DeInit
 */

/**
 * @fn void GPIO_Init(GPIO_Handler_t*)
 * @brief	Initialize the GPIO Handler
 *
 * @param pGPIOHandler	Address of GPIO Handler
 */
void GPIO_Init(GPIO_Handler_t *pGPIOHandler)
{
	// 1. Configure the mode of GPIO pin

	// 2. Configure the speed

	// 3. Configure the PU/PD setting

	// 4. Configure the output type

	// 5. Configure the alternative function
}

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
