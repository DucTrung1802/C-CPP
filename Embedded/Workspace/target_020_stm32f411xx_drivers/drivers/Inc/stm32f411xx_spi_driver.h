#ifndef INC_STM32F411XX_SPI_DRIVER_H_
#define INC_STM32F411XX_SPI_DRIVER_H_

#include "stm32f411xx.h"

/*
 * Configuration structure for a SPI peripheral
 */
typedef struct
{
	uint8_t SPI_DeviceMode;/* 	@SPI_DeviceMode */
	uint8_t SPI_BusConfig; /* 	@SPI_BusConfig 	*/
	uint8_t SPI_SclkSpeed; /* 	@SPI_SclkSpeed	*/
	uint8_t SPI_DFF; /* 		@SPI_DFF 		*/
	uint8_t SPI_CPOL; /* 		@SPI_CPOL 		*/
	uint8_t SPI_CPHA; /* 		@SPI_CPHA		*/
	uint8_t SPI_SSM; /* 		@SPI_SSM 		*/
} SPI_Config_t;

/*
 * Handle structure for SPIx peripheral
 */
typedef struct
{
	SPI_RegDef_t *pSPIx; /* This holds the base address of SPIx (x:0,1,2,3,4) peripheral */
	SPI_Config_t SPIConfig;
} SPI_Handler_t;

/*
 * @SPI_DeviceMode
 */
#define SPI_DEVICE_MODE_MASTER		1
#define SPI_DEVICE_MODE_SLAVE		0

/*
 * @SPI_BusConfig
 */
#define SPI_BUS_CONFIG_FULL_DUPLEX 			1
#define SPI_BUS_CONFIG_HALF_DUPLEX 			2
#define SPI_BUS_CONFIG_SIMPLEX_RX_ONLY		3

/*
 * @SPI_SclkSpeed
 */
#define SPI_SCLK_SPEED_DIV2			0
#define SPI_SCLK_SPEED_DIV4			1
#define SPI_SCLK_SPEED_DIV8			2
#define SPI_SCLK_SPEED_DIV16		3
#define SPI_SCLK_SPEED_DIV32		4
#define SPI_SCLK_SPEED_DIV64		5
#define SPI_SCLK_SPEED_DIV128		6
#define SPI_SCLK_SPEED_DIV256		7

/*
 * @SPI_DFF
 */
#define SPI_DFF_8BITS		0
#define SPI_DFF_16BITS		1

/*
 * @SPI_CPOL
 * Select Clock Polarity: (0) IDLE STATE is LOW | (1) IDLE STATE is HIGH
 */
#define SPI_CPOL_LOW		0
#define SPI_CPOL_HIGH		1

/*
 * @SPI_CPHA
 * Select Clock Phase: (0) Data sampled on rising edge | (1) Data sampled on the falling edge
 */
#define SPI_CPHA_LOW		0
#define SPI_CPHA_HIGH		1

/*
 * @SPI_SSM
 * Software slave management
 */
#define SPI_SSM_HWM			0
#define SPI_SSM_SWM			1

/*
 * SPI related status flags definitions
 */
#define SPI_RXNE_FLAG		(1 << SPI_SR_RXNE)
#define SPI_TXE_FLAG		(1 << SPI_SR_TXE)
#define SPI_CHSIDE_FLAG		(1 << SPI_SR_CHSIDE)
#define SPI_CRC_ERR_FLAG	(1 << SPI_SR_CRC_ERR)
#define SPI_MODF_FLAG		(1 << SPI_SR_MODF)
#define SPI_OVR_FLAG		(1 << SPI_SR_OVR)
#define SPI_BUSY_FLAG		(1 << SPI_SR_BSY)
#define SPI_FRE_FLAG		(1 << SPI_SR_FRE)

/*
 * Peripheral Clock Setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * SPI Control APIs
 */

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
