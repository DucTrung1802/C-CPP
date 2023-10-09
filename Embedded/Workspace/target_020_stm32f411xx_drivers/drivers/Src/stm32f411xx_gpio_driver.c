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
	uint32_t temp = 0; /* Temp register */

	if (pGPIOHandler->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		// Non-interrupt mode
		temp = (pGPIOHandler->GPIO_PinConfig.GPIO_PinMode
				<< (2 * pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandler->pGPIOx->MODER &= ~(0x03
				<< (2 * pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandler->pGPIOx->MODER |= temp;
	}
	else
	{
		// Interrupt mode
	}
	// 2. Configure the speed
	temp = (pGPIOHandler->GPIO_PinConfig.GPIO_PinSpeed
			<< (2 * pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandler->pGPIOx->OSPEEDR &= ~(0x03
			<< (2 * pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandler->pGPIOx->OSPEEDR |= temp;

	// 3. Configure the PU/PD setting
	temp = (pGPIOHandler->GPIO_PinConfig.GPIO_PinPuPdControl
			<< (2 * pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandler->pGPIOx->PUPDR &= ~(0x03
			<< (2 * pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandler->pGPIOx->PUPDR |= temp;

	// 4. Configure the output type
	temp = (pGPIOHandler->GPIO_PinConfig.GPIO_PinOPType
			<< (2 * pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandler->pGPIOx->OTYPER &= ~(0x03
			<< (2 * pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandler->pGPIOx->OTYPER |= temp;

	// 5. Configure the alternative functionw
	if (pGPIOHandler->GPIO_PinConfig.GPIO_PinAltFuncMode == GPIO_MODE_ALT_FUNC)
	{
		uint8_t temp1, temp2;
		temp1 = pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandler->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandler->pGPIOx->AFR[temp1] &= ~(0x0F << (4 * temp2));
		pGPIOHandler->pGPIOx->AFR[temp1] |=
				pGPIOHandler->GPIO_PinConfig.GPIO_PinAltFuncMode << (4 * temp2);
	}

}

/**
 * @fn void GPIO_DeInit(GPIO_RegDef_t*)
 * @brief	De-Initialize/Reset the given GPIO port
 *
 * @param pGPIOx	Desired GPIO port to be reset
 */
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if (pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	else if (pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	else if (pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	else if (pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	else if (pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	else if (pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}
}

/*
 * Data read and write
 */
/**
 * @fn uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t*, uint8_t)
 * @brief	Read data from the given GPIO pin
 *
 * @param pGPIOx		The given GPIO port	(A/B/C/D/E/H)
 * @param PinNumber		The given GPIO pin 	(0 - 15)
 * @return
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t) ((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}

/**
 * @fn uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t*)
 * @brief	Read data from the given GPIO port
 *
 * @param pGPIOx	The given GPIO port	(A/B/C/D/E/H)
 * @return
 */
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{
	return (uint16_t) pGPIOx->IDR;
}

/**
 * @fn void GPIO_WriteToOutputPin(GPIO_RegDef_t*, uint8_t, uint8_t)
 * @brief	Write data from the given GPIO pin
 *
 * @param pGPIOx		The given GPIO port	(A/B/C/D/E/H)
 * @param PinNumber		The given GPIO pin
 * @param Value			LOW/HIGH
 */
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,
		uint8_t Value)
{
	if (Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}

/**
 * @fn void GPIO_WriteToOutputPort(GPIO_RegDef_t*, uint16_t)
 * @brief	Write data from the given GPIO port
 *
 * @param pGPIOx	The given GPIO port	(A/B/C/D/E/H)
 * @param Value		The desired value to be written
 */
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}

/*
 * IRQ Configuration and Handler
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandler(uint8_t PinNumber);
