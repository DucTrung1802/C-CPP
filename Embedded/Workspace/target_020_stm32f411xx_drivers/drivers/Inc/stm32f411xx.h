#ifndef INC_STM32F411XX_H_
#define INC_STM32F411XX_H_

#include <stdint.h>

#define __vo volatile

/*
 * ARM Cortex M4 Programmable Bits of Priority Register Address
 */
#define PROGRAMMABLE_PR_BITS		4

/*
 * **************************** START: Processor Specific Details ***************************
 *
 * AMR Cortex Mx Processor NVIC ISERx register addresses
 */
#define NVIC_ISER0			((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1			((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2			((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3			((__vo uint32_t*)0xE000E10C)

#define NVIC_ICER0			((__vo uint32_t*)0XE000E180)
#define NVIC_ICER1			((__vo uint32_t*)0XE000E184)
#define NVIC_ICER2			((__vo uint32_t*)0XE000E188)
#define NVIC_ICER3			((__vo uint32_t*)0XE000E18C)

#define NVIC_ISPR0			((__vo uint32_t*)0XE000E200)
#define NVIC_ISPR1			((__vo uint32_t*)0XE000E204)
#define NVIC_ISPR2			((__vo uint32_t*)0XE000E208)
#define NVIC_ISPR3			((__vo uint32_t*)0XE000E20C)

#define NVIC_ICPR0			((__vo uint32_t*)0XE000E280)
#define NVIC_ICPR1			((__vo uint32_t*)0XE000E284)
#define NVIC_ICPR2			((__vo uint32_t*)0XE000E288)
#define NVIC_ICPR3			((__vo uint32_t*)0XE000E28C)

#define NVIC_IABR0			((__vo uint32_t*)0XE000E300)
#define NVIC_IABR1			((__vo uint32_t*)0XE000E304)
#define NVIC_IABR2			((__vo uint32_t*)0XE000E308)
#define NVIC_IABR3			((__vo uint32_t*)0XE000E30C)

#define NVIC_PR_BASE_ADDR	((__vo uint32_t*)0XE000E400)

#define NVIC_STIR			((__vo uint32_t*)0xE000EF00)

/*
 * Base addresses of FLASH and SAM memories
 * */
#define FLASH_BASE_ADDR					(0x08000000UL)
#define SRAM_BASE_ADDR					(0x20000000UL)
#define ROM_BASE_ADDR					(0x1FFF0000UL)

/*
 * Base addresses of AHBx and APBx bus peripherals
 */
#define APB1_BASE_ADDR					(0x40000000UL)
#define APB2_BASE_ADDR					(0x40010000UL)
#define AHB1_BASE_ADDR					(0x40020000UL)
#define AHB2_BASE_ADDR					(0X50000000UL)

/*
 *Base addresses of APB1 bus peripherals
 */
#define TIM2_BASE_ADDR					((APB1_BASE_ADDR)+(0x0000UL))
#define TIM3_BASE_ADDR					((APB1_BASE_ADDR)+(0x0400UL))
#define TIM4_BASE_ADDR					((APB1_BASE_ADDR)+(0x0800UL))
#define TIM5_BASE_ADDR					((APB1_BASE_ADDR)+(0x0C00UL))
#define RTC_BKP_REG_BASE_ADDR			((APB1_BASE_ADDR)+(0x2800UL))
#define WWDG_BASE_ADDR					((APB1_BASE_ADDR)+(0x2C00UL))
#define IWDG_BASE_ADDR					((APB1_BASE_ADDR)+(0x3000UL))
#define I2S2EXT_BASE_ADDR				((APB1_BASE_ADDR)+(0x3400UL))
#define SPI2_I2S2_BASE_ADDR				((APB1_BASE_ADDR)+(0x3800UL))
#define SPI3_I2S3_BASE_ADDR				((APB1_BASE_ADDR)+(0x3C00UL))
#define I2S3EXT_BASE_ADDR				((APB1_BASE_ADDR)+(0x4000UL))
#define USART2_BASE_ADDR				((APB1_BASE_ADDR)+(0x4400UL))
#define I2C1_BASE_ADDR					((APB1_BASE_ADDR)+(0x5400UL))
#define I2C2_BASE_ADDR					((APB1_BASE_ADDR)+(0x5800UL))
#define I2C3_BASE_ADDR					((APB1_BASE_ADDR)+(0x5C00UL))
#define PWR_BASE_ADDR					((APB1_BASE_ADDR)+(0x7000UL))

/*
 * Base addresses of APB2 bus peripherals
 */
#define TIM1_BASE_ADDR					((APB2_BASE_ADDR)+(0x0000UL))
#define USART1_BASE_ADDR				((APB2_BASE_ADDR)+(0x1000UL))
#define USART6_BASE_ADDR				((APB2_BASE_ADDR)+(0x1400UL))
#define ADC1_BASE_ADDR					((APB2_BASE_ADDR)+(0x2000UL))
#define SDIO_BASE_ADDR					((APB2_BASE_ADDR)+(0x2C00UL))
#define SPI1_I2S1_BASE_ADDR				((APB2_BASE_ADDR)+(0x3000UL))
#define SPI4_I2S4_BASE_ADDR				((APB2_BASE_ADDR)+(0x3400UL))
#define SYSCFG_BASE_ADDR				((APB2_BASE_ADDR)+(0x3800UL))
#define EXTI_BASE_ADDR					((APB2_BASE_ADDR)+(0x3C00UL))
#define TIM9_BASE_ADDR					((APB2_BASE_ADDR)+(0x4000UL))
#define TIM10_BASE_ADDR					((APB2_BASE_ADDR)+(0x4400UL))
#define TIM11_BASE_ADDR					((APB2_BASE_ADDR)+(0x4800UL))
#define SPI5_I2S5_BASE_ADDR				((APB2_BASE_ADDR)+(0x5000UL))

/*
 *Base addresses of AHB1 bus peripherals
 */
#define GPIOA_BASE_ADDR					((AHB1_BASE_ADDR) + (0x0000UL))
#define GPIOB_BASE_ADDR					((AHB1_BASE_ADDR) + (0x0400UL))
#define GPIOC_BASE_ADDR					((AHB1_BASE_ADDR) + (0x0800UL))
#define GPIOD_BASE_ADDR					((AHB1_BASE_ADDR) + (0x0C00UL))
#define GPIOE_BASE_ADDR					((AHB1_BASE_ADDR) + (0x1000UL))
#define GPIOH_BASE_ADDR					((AHB1_BASE_ADDR) + (0x1C00UL))
#define CRC_BASE_ADDR					((AHB1_BASE_ADDR) + (0x3000UL))
#define RCC_BASE_ADDR					((AHB1_BASE_ADDR) + (0x3800UL))
#define FLASH_INTERFACE_REG_BASE_ADDR	((AHB1_BASE_ADDR) + (0x3C00UL))
#define DMA1_BASE_ADDR					((AHB1_BASE_ADDR) + (0x6000UL))
#define DMA2_BASE_ADDR					((AHB1_BASE_ADDR) + (0x6400UL))

/*
 *Base addresses of AHB1 bus peripherals
 */
#define USB_OTG_FS_BASE_ADDR			((AHB2_BASE_ADDR)+(0x0000UL))

/*
 * Register definition structures for RCC
 */
typedef struct
{
	__vo uint32_t CR; /* 		RCC clock control register									Offset: 0x00 */
	__vo uint32_t PLLCFGR; /* 	RCC PLL configuration register								Offset: 0x04 */
	__vo uint32_t CFGR; /* 		RCC clock configuration register							Offset: 0x08 */
	__vo uint32_t CIR; /* 		RCC clock interrupt register								Offset: 0x0C */
	__vo uint32_t AHB1RSTR; /* 	RCC AHB1 peripheral reset register							Offset: 0x10 */
	__vo uint32_t AHB2RSTR; /* 	RCC AHB2 peripheral reset register							Offset: 0x14 */
	__vo uint32_t RESERVE1; /* 	Reserve 1													Offset: 0x18 */
	__vo uint32_t RESERVE2; /* 	Reserve 2													Offset: 0x1C */
	__vo uint32_t APB1RSTR; /* 	RCC APB1 peripheral reset register							Offset: 0x20 */
	__vo uint32_t APB2RSTR; /* 	RCC APB2 peripheral reset register 							Offset: 0x24 */
	__vo uint32_t RESERVE3; /* 	Reserve 3													Offset: 0x28 */
	__vo uint32_t RESERVE4; /* 	Reserve 4													Offset: 0x2C */
	__vo uint32_t AHB1ENR;/* 	RCC AHB1 peripheral clock enable register					Offset: 0x30 */
	__vo uint32_t AHB2ENR;/* 	RCC AHB2 peripheral clock enable register					Offset: 0x34 */
	__vo uint32_t RESERVE5; /* 	Reserve 5													Offset: 0x38 */
	__vo uint32_t RESERVE6; /* 	Reserve 6													Offset: 0x3C */
	__vo uint32_t APB1ENR;/* 	RCC APB1 peripheral clock enable register					Offset: 0x40 */
	__vo uint32_t APB2ENR;/* 	RCC APB2 peripheral clock enable register					Offset: 0x44 */
	__vo uint32_t RESERVE7; /* 	Reserve 7													Offset: 0x48 */
	__vo uint32_t RESERVE8; /* 	Reserve 8													Offset: 0x4C */
	__vo uint32_t AHB1LPENR;/* 	RCC AHB1 peripheral clock enable in low power mode register	Offset: 0x50  */
	__vo uint32_t AHB2LPENR;/* 	RCC AHB2 peripheral clock enable in low power mode register	Offset: 0x54  */
	__vo uint32_t RESERVE9; /* 	Reserve 9													Offset: 0x58 */
	__vo uint32_t RESERVE10;/* 	Reserve 10													Offset: 0x5C */
	__vo uint32_t APB1LPENR;/* 	RCC APB1 peripheral clock enable in low power mode register	Offset: 0x60  */
	__vo uint32_t APB2LPENR;/* 	RCC APB2 peripheral clock enable in low power mode register	Offset: 0x64  */
	__vo uint32_t RESERVE11;/* 	Reserve 11													Offset: 0x68 */
	__vo uint32_t RESERVE12;/* 	Reserve 12													Offset: 0x6C */
	__vo uint32_t BDCR; /* 		RCC Backup domain control register							Offset: 0x70 */
	__vo uint32_t CSR;/* 		RCC clock control & status register							Offset: 0x74 */
	__vo uint32_t RESERVE13;/* 	Reserve 13													Offset: 0x78 */
	__vo uint32_t RESERVE14;/* 	Reserve 14													Offset: 0x7C */
	__vo uint32_t SSCGR;/* 		RCC spread spectrum clock generation register				Offset: 0x80 */
	__vo uint32_t PLLI2SCFGR;/* RCC PLLI2S configuration register							Offset: 0x84 */
	__vo uint32_t RESERVE15;/* 	Reserve 15													Offset: 0x88 */
	__vo uint32_t DCKCFGR;/* 	RCC Dedicated Clocks Configuration Register					Offset: 0x8C */
} RCC_RegDef_t;

/*
 * Register definition structures for EXTI
 */
typedef struct
{
	__vo uint32_t IMR;/* Interrupt mask register				Offset: 0x00 */
	__vo uint32_t EMR;/* Event mask register                    Offset: 0x04 */
	__vo uint32_t RTSR;/* Rising trigger selection register     Offset: 0x08 */
	__vo uint32_t FTSR;/* Falling trigger selection register    Offset: 0x0C */
	__vo uint32_t SWIER;/* Software interrupt event register    Offset: 0x10 */
	__vo uint32_t PR;/* Pending register                        Offset: 0x14 */

} EXTI_RegDef_t;

/*
 * Register definition structures for SYSCFG
 */
typedef struct
{
	__vo uint32_t MEMRMP; /* 		SYSCFG memory remap register								Offset: 0x00 */
	__vo uint32_t PMC; /* 			SYSCFG peripheral mode configuration register 				Offset: 0x04 */
	__vo uint32_t EXTICR[4]; /* 	SYSCFG external interrupt configuration register (1 - 4)	Offset: 0x08 - 0x14 */
	__vo uint32_t RESERVED[2];/*	Reserved 													Offset: 0x18 - 0x1C */
	__vo uint32_t CMPCR; /* 		Compensation cell control register 							Offset: 0x20 */
} SYSCFG_RegDef_t;

/*
 * Register definition structures for GPIO
 */
typedef struct
{
	__vo uint32_t MODER; /* 	GPIO port mode register									Offset: 0x00 */
	__vo uint32_t OTYPER; /* 	GPIO port output type register							Offset: 0x04 */
	__vo uint32_t OSPEEDR; /*	GPIO port output speed register							Offset: 0x08 */
	__vo uint32_t PUPDR; /* 	GPIO port pull-up/pull-down register					Offset: 0x0C */
	__vo uint32_t IDR; /* 		GPIO port input data register							Offset: 0x10 */
	__vo uint32_t ODR; /* 		GPIO port output data register							Offset: 0x14 */
	__vo uint32_t BSRR; /* 		GPIO port bit set/reset register						Offset: 0x18 */
	__vo uint32_t LCKR; /* 		GPIO port configuration lock register					Offset: 0x1C */
	__vo uint32_t AFR[2]; /* 	GPIO alternate function registers, [0]: low, [1]: high	Offset: AFRL 0x20, AFRH 0x24 */
} GPIO_RegDef_t;

/*
 * Register definition structures for SPI
 */
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;
} SPI_RegDef_t;

/*
 * Peripheral definitions (Peripheral base addresses typecasted to xxx_RegDef_t)
 */
#define RCC						((RCC_RegDef_t*)RCC_BASE_ADDR)

#define EXTI					((EXTI_RegDef_t*)EXTI_BASE_ADDR)

#define SYSCFG					((SYSCFG_RegDef_t*)SYSCFG_BASE_ADDR)

#define GPIOA					((GPIO_RegDef_t*)GPIOA_BASE_ADDR)
#define GPIOB					((GPIO_RegDef_t*)GPIOB_BASE_ADDR)
#define GPIOC					((GPIO_RegDef_t*)GPIOC_BASE_ADDR)
#define GPIOD					((GPIO_RegDef_t*)GPIOD_BASE_ADDR)
#define GPIOE					((GPIO_RegDef_t*)GPIOE_BASE_ADDR)
#define GPIOH					((GPIO_RegDef_t*)GPIOH_BASE_ADDR)

#define SPI1					((SPI_RegDef_t*)SPI1_I2S1_BASE_ADDR)
#define SPI2					((SPI_RegDef_t*)SPI2_I2S2_BASE_ADDR)
#define SPI3					((SPI_RegDef_t*)SPI3_I2S3_BASE_ADDR)
#define SPI4					((SPI_RegDef_t*)SPI4_I2S4_BASE_ADDR)
#define SPI5					((SPI_RegDef_t*)SPI5_I2S5_BASE_ADDR)

/*
 * ENABLE
 */
/*
 * Clock Enable Macros for GPIOx peripherals
 */
#define GPIOA_PCLOCK_EN()    	(RCC->AHB1ENR |= (1 << 0))
#define	GPIOB_PCLOCK_EN()		(RCC->AHB1ENR |= (1 << 1))
#define	GPIOC_PCLOCK_EN()		(RCC->AHB1ENR |= (1 << 2))
#define	GPIOD_PCLOCK_EN()		(RCC->AHB1ENR |= (1 << 3))
#define	GPIOE_PCLOCK_EN()		(RCC->AHB1ENR |= (1 << 4))
#define	GPIOH_PCLOCK_EN()		(RCC->AHB1ENR |= (1 << 7))

/*
 * Clock Enable Macros for I2Cx peripherals
 */
#define	I2C1_PCLOCK_EN()		(RCC->APB1ENR |= (1 << 21))
#define	I2C2_PCLOCK_EN()		(RCC->APB1ENR |= (1 << 22))
#define	I2C3_PCLOCK_EN()		(RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable Macros for SPIx peripherals
 */
#define	SPI1_I2S1_PCLOCK_EN()		(RCC->APB2ENR |= (1 << 12))
#define	SPI2_I2S2_PCLOCK_EN()		(RCC->APB1ENR |= (1 << 14))
#define	SPI3_I2S3_PCLOCK_EN()		(RCC->APB1ENR |= (1 << 15))
#define	SPI4_I2S4_PCLOCK_EN()		(RCC->APB2ENR |= (1 << 13))
#define	SPI5_I2S5_PCLOCK_EN()		(RCC->APB2ENR |= (1 << 20))

/*
 * Clock Enable Macros for USARTx peripherals
 */
#define	USART1_PCLOCK_EN()		(RCC->APB2ENR |= (1 << 4))
#define	USART2_PCLOCK_EN()		(RCC->APB1ENR |= (1 << 17))
#define	USART6_PCLOCK_EN()		(RCC->APB2ENR |= (1 << 5))

/*
 * Clock Enable Macros for SYSCFG peripherals
 */
#define	SYSCFG_PCLOCK_EN()		(RCC->APB2ENR |= (1 << 14))

/*
 * DISABLE
 */
/*
 * Clock Disable Macros for GPIOx peripherals
 */
#define	GPIOA_PCLOCK_DI()		(RCC->AHB1ENR &= ~(1 << 0))
#define	GPIOB_PCLOCK_DI()		(RCC->AHB1ENR &= ~(1 << 1))
#define	GPIOC_PCLOCK_DI()		(RCC->AHB1ENR &= ~(1 << 2))
#define	GPIOD_PCLOCK_DI()		(RCC->AHB1ENR &= ~(1 << 3))
#define	GPIOE_PCLOCK_DI()		(RCC->AHB1ENR &= ~(1 << 4))
#define	GPIOH_PCLOCK_DI()		(RCC->AHB1ENR &= ~(1 << 7))

/*
 * Clock Disable Macros for I2Cx peripherals
 */
#define	I2C1_PCLOCK_DI()		(RCC->APB1ENR &= ~(1 << 21))
#define	I2C2_PCLOCK_DI()		(RCC->APB1ENR &= ~(1 << 22))
#define	I2C3_PCLOCK_DI()		(RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock Disable Macros for SPIx peripherals
 */
#define	SPI1_I2S1_PCLOCK_DI()		(RCC->APB2ENR &= ~(1 << 12))
#define	SPI2_I2S2_PCLOCK_DI()		(RCC->APB1ENR &= ~(1 << 14))
#define	SPI3_I2S3_PCLOCK_DI()		(RCC->APB1ENR &= ~(1 << 15))
#define	SPI4_I2S4_PCLOCK_DI()		(RCC->APB2ENR &= ~(1 << 13))
#define	SPI5_I2S5_PCLOCK_DI()		(RCC->APB2ENR &= ~(1 << 20))

/*
 * Clock Disable Macros for USARTx peripherals
 */
#define	USART1_PCLOCK_DI()		(RCC->APB2ENR &= ~(1 << 4))
#define	USART2_PCLOCK_DI()		(RCC->APB1ENR &= ~(1 << 17))
#define	USART6_PCLOCK_DI()		(RCC->APB2ENR &= ~(1 << 5))

/*
 * Clock Disable Macros for SYSCFG peripherals
 */
#define	SYSCFG_PCLOCK_DI()		(RCC->APB2ENR &= ~(1 << 14))

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));} while (0)
#define GPIOB_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));} while (0)
#define GPIOC_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));} while (0)
#define GPIOD_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));} while (0)
#define GPIOE_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));} while (0)
#define GPIOH_REG_RESET()		do{(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));} while (0)

/*
 * IRQ (interrupt request) Number of STM32F411xx MCU
 * NOTE: update these macros with valid values according to your MCU
 * TODO: You may complete this list for other peripherals
 */
#define IRQ_WWDG					0
#define IRQ_EXTI16_PVD				1
#define IRQ_EXTI21_TAMP_STAMP		2
#define IRQ_EXTI22_RTC_WKUP			3
#define IRQ_FLASH					4
#define IRQ_RCC						5
#define IRQ_EXTI0					6
#define IRQ_EXTI1					7
#define IRQ_EXTI2					8
#define IRQ_EXTI3					9
#define IRQ_EXTI4					10
#define IRQ_DMA1_STREAM0 			11
#define IRQ_DMA1_STREAM1 			12
#define IRQ_DMA1_STREAM2 			13
#define IRQ_DMA1_STREAM3 			14
#define IRQ_DMA1_STREAM4 			15
#define IRQ_DMA1_STREAM5 			16
#define IRQ_DMA1_STREAM6 			17
#define IRQ_ADC						18
#define IRQ_EXTI9_5					23
#define IRQ_TIM1_BRK_TIM9			24
#define IRQ_TIM1_UP_TIM10			25
#define IRQ_TIM1_TRG_COM_TIM11		26
#define IRQ_TIM1_CC					27
#define IRQ_TIM2					28
#define IRQ_TIM3					29
#define IRQ_TIM4					30
#define IRQ_I2C1_EV					31
#define IRQ_I2C1_ER					32
#define IRQ_I2C2_EV					33
#define IRQ_I2C2_ER					34
#define IRQ_SPI1					35
#define IRQ_SPI2					36
#define IRQ_USART1					37
#define IRQ_USART2					38
#define IRQ_EXTI15_10				40
#define IRQ_EXTI17_RTC_Alarm		41
#define IRQ_EXTI18_OTG_FS_WKUP		42
#define IRQ_DMA1_STREAM7			47
#define IRQ_SDIO					49
#define IRQ_TIM5					50
#define IRQ_SPI3					51
#define IRQ_DMA2_STREAM0			56
#define IRQ_DMA2_STREAM1			57
#define IRQ_DMA2_STREAM2			58
#define IRQ_DMA2_STREAM3			59
#define IRQ_DMA2_STREAM4			60
#define IRQ_OTG_FS					67
#define IRQ_DMA2_STREAM5			68
#define IRQ_DMA2_STREAM6			69
#define IRQ_DMA2_STREAM7			70
#define IRQ_USART6					71
#define IRQ_I2C3_EV					72
#define IRQ_I2C3_ER					73
#define IRQ_FPU						81
#define IRQ_SPI4					84
#define IRQ_SPI5					85

/*
 * Generic macros
 */
#define ENABLE 			1
#define DISABLE 		0
#define SET				ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET

/*
 * GPIO macros
 */
#define GPIO_PIN_NO_0   0
#define GPIO_PIN_NO_1   1
#define GPIO_PIN_NO_2   2
#define GPIO_PIN_NO_3   3
#define GPIO_PIN_NO_4   4
#define GPIO_PIN_NO_5   5
#define GPIO_PIN_NO_6   6
#define GPIO_PIN_NO_7   7
#define GPIO_PIN_NO_8   8
#define GPIO_PIN_NO_9   9
#define GPIO_PIN_NO_10  10
#define GPIO_PIN_NO_11  11
#define GPIO_PIN_NO_12  12
#define GPIO_PIN_NO_13  13
#define GPIO_PIN_NO_14  14
#define GPIO_PIN_NO_15  15

/*
 * SPI macros
 */

// Bit position definitions SPI_CR1
#define SPI_CR1_CPHA			0
#define SPI_CR1_CPOL			1
#define SPI_CR1_MSTR			2
#define SPI_CR1_BR				3
#define SPI_CR1_SPE				6
#define SPI_CR1_LSB_FIRST		7
#define SPI_CR1_SSI				8
#define SPI_CR1_SSM				9
#define SPI_CR1_RX_ONLY			10
#define SPI_CR1_DFF				11
#define SPI_CR1_CRC_NEXT		12
#define SPI_CR1_CRC_EN			13
#define SPI_CR1_BIDIOE			14
#define SPI_CR1_BIDIMODE		15

// Bit position definitions SPI_CR2
#define SPI_CR2_RXDMAEN			0
#define SPI_CR2_TXDMAEN			1
#define SPI_CR2_SSOE			2
#define SPI_CR2_FRF				4
#define SPI_CR2_ERRIE			5
#define SPI_CR2_RXNEIE			6
#define SPI_CR2_TXEIE			7

// Bit position definitions SPI_SR
#define SPI_SR_RXNE				0
#define SPI_SR_TXE				1
#define SPI_SR_CHSIDE			2
#define SPI_SR_UDR				3
#define SPI_SR_CRC_ERR			4
#define SPI_SR_MODF				5
#define SPI_SR_OVR				6
#define SPI_SR_BSY				7
#define SPI_SR_FRE				8

/*
 * Interrupt priorities
 */
#define NVIC_IRQ_PRIO0        0
#define NVIC_IRQ_PRIO1        1
#define NVIC_IRQ_PRIO2        2
#define NVIC_IRQ_PRIO3        3
#define NVIC_IRQ_PRIO4        4
#define NVIC_IRQ_PRIO5        5
#define NVIC_IRQ_PRIO6        6
#define NVIC_IRQ_PRIO7        7
#define NVIC_IRQ_PRIO8        8
#define NVIC_IRQ_PRIO9        9
#define NVIC_IRQ_PRIO10       10
#define NVIC_IRQ_PRIO11       11
#define NVIC_IRQ_PRIO12       12
#define NVIC_IRQ_PRIO13       13
#define NVIC_IRQ_PRIO14       14
#define NVIC_IRQ_PRIO15       15

/*
 * Return port code of given GPIOx base address (GPIOA = 0, GPIOB = 1, ...)
 */
#define GPIO_BASE_ADDR_TO_CODE(x)	(	(x == GPIOA) ? 0: \
										(x == GPIOB) ? 1: \
										(x == GPIOC) ? 2: \
										(x == GPIOD) ? 3: \
										(x == GPIOE) ? 4: \
										(x == GPIOH) ? 7: 0	)

#ifndef INC_STM32F411XX_GPIO_DRIVER_H_
#include "stm32f411xx_gpio_driver.h"
#endif

#ifndef INC_STM32F411XX_SPI_DRIVER_H_
#include "stm32f411xx_spi_driver.h"
#endif

#endif /* INC_STM32F411XX_H_ */
