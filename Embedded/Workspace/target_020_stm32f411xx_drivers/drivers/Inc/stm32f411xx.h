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
 * Peripheral register definition structures
 */
typedef struct {
	__vo uint32_t MODER;// GPIO port mode register					Offset: 0x00
	__vo uint32_t OTYPER; // GPIO port output type register			Offset: 0x04
	__vo uint32_t OSPEEDR; // GPIO port output speed register			Offset: 0x08
	__vo uint32_t PUPDR; // GPIO port pull-up/pull-down register		Offset: 0x0C
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
