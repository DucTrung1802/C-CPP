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
	SPI_Reg
};

#endif /* INC_STM32F411XX_SPI_DRIVER_H_ */
