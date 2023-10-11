#include "stm32f411xx_spi_driver.h"

/*
 * Peripheral Clock Setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi)
{
	if (EnorDi == ENABLE)
	{
		if (pSPIx == SPI1)
		{
			SPI1_I2S1_PCLOCK_EN();
		}
		else if (pSPIx == SPI2)
		{
			SPI2_I2S2_PCLOCK_EN();
		}
		else if (pSPIx == SPI3)
		{
			SPI3_I2S3_PCLOCK_EN();
		}
		else if (pSPIx == SPI4)
		{
			SPI4_I2S4_PCLOCK_EN();
		}
		else if (pSPIx == SPI5)
		{
			SPI5_I2S5_PCLOCK_EN();
		}
	}
	else
	{
		if (pSPIx == SPI1)
		{
			SPI1_I2S1_PCLOCK_DI();
		}
		else if (pSPIx == SPI2)
		{
			SPI2_I2S2_PCLOCK_DI();
		}
		else if (pSPIx == SPI3)
		{
			SPI3_I2S3_PCLOCK_DI();
		}
		else if (pSPIx == SPI4)
		{
			SPI4_I2S4_PCLOCK_DI();
		}
		else if (pSPIx == SPI5)
		{
			SPI5_I2S5_PCLOCK_DI();
		}
	}
}

/*
 * Init and DeInit
 */
void SPI_Init(SPI_Handler_t *pSPIHandler)
{
	// 1. Configure the SPI_CR1 register
	uint32_t temp_reg = 0;

	// 1.1 Configure the device mode
	temp_reg |= pSPIHandler->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;

	// 1.2 Configure the device mode
	if (pSPIHandler->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FULL_DUPLEX)
	{
		// Full duplex mode
		// BIDIMODE should be cleared
		temp_reg &= ~(1 << SPI_CR1_BIDIMODE);
	}
	else if (pSPIHandler->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HALF_DUPLEX)
	{
		// Half duplex mode
		// BIDIMODE should be set
		temp_reg |= (1 << SPI_CR1_BIDIMODE);
	}
	else if (pSPIHandler->SPIConfig.SPI_BusConfig
			== SPI_BUS_CONFIG_SIMPLEX_RX_ONLY)
	{
		// Simplex RX only duplex mode
		// BIDIMODE should be cleared
		temp_reg &= ~(1 << SPI_CR1_BIDIMODE);
		// RXONLY bit must be set
		temp_reg |= (1 << SPI_CR1_RX_ONLY);
	}

	// 2. Configure the SPI serial clock speed (baud rate)
	temp_reg |= pSPIHandler->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;

	// 3. Configure the DFF
	temp_reg |= pSPIHandler->SPIConfig.SPI_DFF << SPI_CR1_DFF;

	// 4.Configure the CPOL
	temp_reg |= pSPIHandler->SPIConfig.SPI_CPOL << SPI_CR1_CPOL;

	// 5.Configure the CPHA
	temp_reg |= pSPIHandler->SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

	pSPIHandler->pSPIx->CR1 = temp_reg;
}

void SPI_DeInit(SPI_RegDef_t *pSPIx)
{

}

/*
 * Data Send and Receive
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t len)
{

}

void SPI_ReceiveData(SPI_RegDef_t *pSPIx)
{

}

/*
 * IRQ Configuration and ISR handler
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

}

void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}

void SPI_IRQHandler(SPI_Handler_t *pHandler)
{

}

