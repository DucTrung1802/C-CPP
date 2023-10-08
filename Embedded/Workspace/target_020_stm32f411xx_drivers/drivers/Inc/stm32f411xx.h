#ifndef INC_STM32F411XX_H_
#define INC_STM32F411XX_H_

#define __vo volatile

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
 * RCC register definition structures
 */
typedef struct {
	__vo uint32_t CR; // RCC clock control register							Offset: 0x00
	__vo uint32_t PLLCFGR; // RCC PLL configuration register				Offset: 0x04
	__vo uint32_t CFGR;	// RCC clock configuration register					Offset: 0x08
	__vo uint32_t CIR; // RCC clock interrupt register						Offset: 0x0C
	__vo uint32_t AHB1RSTR; // RCC AHB1 peripheral reset register			Offset: 0x10
	__vo uint32_t AHB2RSTR; // RCC AHB2 peripheral reset register			Offset: 0x14
	__vo uint32_t RESERVE1; // Reserve 1									Offset: 0x18
	__vo uint32_t RESERVE2; // Reserve 2									Offset: 0x1C
	__vo uint32_t APB1RSTR;	// RCC APB1 peripheral reset register			Offset: 0x20
	__vo uint32_t APB2RSTR;	// RCC APB2 peripheral reset register 			Offset: 0x24
	__vo uint32_t RESERVE3;	// Reserve 3									Offset: 0x28
	__vo uint32_t RESERVE4;	// Reserve 4									Offset: 0x2C
	__vo uint32_t AHB1ENR;// RCC AHB1 peripheral clock enable register		Offset: 0x30
	__vo uint32_t AHB2ENR;// RCC AHB2 peripheral clock enable register		Offset: 0x34
	__vo uint32_t RESERVE5;	// Reserve 5									Offset: 0x38
	__vo uint32_t RESERVE6;	// Reserve 6									Offset: 0x3C
	__vo uint32_t APB1ENR;// RCC APB1 peripheral clock enable register		Offset: 0x40
	__vo uint32_t APB2ENR;// RCC APB2 peripheral clock enable register		Offset: 0x44
	__vo uint32_t RESERVE7;	// Reserve 7									Offset: 0x48
	__vo uint32_t RESERVE8;	// Reserve 8									Offset: 0x4C
	__vo uint32_t AHB1LPENR;// RCC AHB1 peripheral clock enable in low power mode register	Offset: 0x50
	__vo uint32_t AHB2LPENR;// RCC AHB2 peripheral clock enable in low power mode register	Offset: 0x54
	__vo uint32_t RESERVE9;	// Reserve 9									Offset: 0x58
	__vo uint32_t RESERVE10;// Reserve 10									Offset: 0x5C
	__vo uint32_t APB1LPENR;// RCC APB1 peripheral clock enable in low power mode register	Offset: 0x60
	__vo uint32_t APB2LPENR;// RCC APB2 peripheral clock enable in low power mode register	Offset: 0x64
	__vo uint32_t RESERVE11;// Reserve 11									Offset: 0x68
	__vo uint32_t RESERVE12;// Reserve 12									Offset: 0x6C
	__vo uint32_t BDCR;	// RCC Backup domain control register				Offset: 0x70
	__vo uint32_t CSR;// RCC clock control & status register				Offset: 0x74
	__vo uint32_t RESERVE13;// Reserve 13									Offset: 0x78
	__vo uint32_t RESERVE14;// Reserve 14									Offset: 0x7C
	__vo uint32_t SSCGR;// RCC spread spectrum clock generation register	Offset: 0x80
	__vo uint32_t PLLI2SCFGR;// RCC PLLI2S configuration register			Offset: 0x84
	__vo uint32_t DCKCFGR;// RCC Dedicated Clocks Configuration Register	Offset: 0x8C
} RCC_RegDef_t;

/*
 * Peripheral register definition structures
 */
typedef struct {
	__vo uint32_t MODER; // GPIO port mode register					Offset: 0x00
	__vo uint32_t OTYPER; // GPIO port output type register			Offset: 0x04
	__vo uint32_t OSPEEDR; // GPIO port output speed register		Offset: 0x08
	__vo uint32_t PUPDR; // GPIO port pull-up/pull-down register	Offset: 0x0C
	__vo uint32_t IDR;     // GPIO port input data register			Offset: 0x10
	__vo uint32_t ODR;   // GPIO port output data register			Offset: 0x14
	__vo uint32_t BSRR; // GPIO port bit set/reset register			Offset: 0x18
	__vo uint32_t LCKR;	// GPIO port configuration lock register	Offset: 0x1C
	__vo uint32_t AFR[2]; // GPIO alternate function registers, [0]: low, [1]: high		Offset: AFRL 0x20, AFRH 0x24
} GPIO_RegDef_t;

/*
 * Peripheral definitions (Peripheral base addresses typecasted to xxx_RegDef_t)
 */
#define GPIOA					((GPIO_RegDef_t*)GPIOA_BASE_ADDR)
#define GPIOB					((GPIO_RegDef_t*)GPIOB_BASE_ADDR)
#define GPIOC					((GPIO_RegDef_t*)GPIOC_BASE_ADDR)
#define GPIOD					((GPIO_RegDef_t*)GPIOD_BASE_ADDR)
#define GPIOE					((GPIO_RegDef_t*)GPIOE_BASE_ADDR)
#define GPIOH					((GPIO_RegDef_t*)GPIOH_BASE_ADDR)

#endif /* INC_STM32F411XX_H_ */
