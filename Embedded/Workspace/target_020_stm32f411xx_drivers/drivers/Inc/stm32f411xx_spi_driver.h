#ifndef INC_STM32F411XX_SPI_DRIVER_H_
#define INC_STM32F411XX_SPI_DRIVER_H_

#include "stm32f411xx.h"

/*
 * Configuration structure for a SPI peripheral
 */
typedef struct
{
	uint8_t SPI_DeviceMode;/* 	MASTER | SLAVE */
	uint8_t SPI_BusConfig; /* 	FULL DUPLEX | HALF DUPLEX | SIMPLEX */
	uint8_t SPI_SclkSpeed; /* 	Clock speed of SCLK pin		 */
	uint8_t SPI_DFF; /* 		Data format: 8 bit | 16 bit */
	uint8_t SPI_CPOL; /* 		Select Clock Polarity: (0) IDLE STATE is LOW | (1) IDLE STATE is HIGH */
	uint8_t SPI_CPHA; /* 		Select Clock Phase: (0) Data sampled on rising edge | (1) Data sampled on the falling edge */
	uint8_t SPI_SSM; /* 		Software slave management */
} SPI_Config_t;

/*
 * Handle structure for SPIx peripheral
 */
typedef struct
{
	SPI_RegDef_t *SPIx; /* This holds the base address of SPIx (x:0,1,2,3,4) peripheral */
	SPI_Config_t SPIConfig;
} SPI_Handler_t;

/*
 * Peripheral Clock Setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * Init and DeInit
 */
void SPI_Init(SPI_Handler_t *pSPIHandler);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Data Send and Receive
 */
void SPI_SendData(SPI_RegDef_t *pSPIx, uint8_t *pTxBuffer, uint32_t len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx);

/*
 * IRQ Configuration and ISR handler
 */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandler(SPI_Handler_t *pHandler);

#endif /* INC_STM32F411XX_SPI_DRIVER_H_ */
