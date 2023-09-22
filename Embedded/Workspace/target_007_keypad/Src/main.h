#ifndef MAIN_H_
#define MAIN_H_

/* Typedef */
typedef struct
{
	uint32_t gpio_a_en :1;
	uint32_t gpio_b_en :1;
	uint32_t gpio_c_en :1;
	uint32_t gpio_d_en :1;
	uint32_t gpio_e_en :1;
	uint32_t reserve_1 :2;
	uint32_t gpio_h_en :1;
	uint32_t reserve_2 :4;
	uint32_t crc_en :1;
	uint32_t reserve_3 :8;
	uint32_t dma_1_en :1;
	uint32_t dma_2_en :1;
	uint32_t reserve_4 :9;
} RCC_AHB1_ENR_t;

typedef struct
{
	uint32_t pin_0 :2;
	uint32_t pin_1 :2;
	uint32_t pin_2 :2;
	uint32_t pin_3 :2;
	uint32_t pin_4 :2;
	uint32_t pin_5 :2;
	uint32_t pin_6 :2;
	uint32_t pin_7 :2;
	uint32_t pin_8 :2;
	uint32_t pin_9 :2;
	uint32_t pin_10 :2;
	uint32_t pin_11 :2;
	uint32_t pin_12 :2;
	uint32_t pin_13 :2;
	uint32_t pin_14 :2;
	uint32_t pin_15 :2;
} GPIOx_MODE_REG_t;

typedef struct
{
	uint32_t pin_0 :1;
	uint32_t pin_1 :1;
	uint32_t pin_2 :1;
	uint32_t pin_3 :1;
	uint32_t pin_4 :1;
	uint32_t pin_5 :1;
	uint32_t pin_6 :1;
	uint32_t pin_7 :1;
	uint32_t pin_8 :1;
	uint32_t pin_9 :1;
	uint32_t pin_10 :1;
	uint32_t pin_11 :1;
	uint32_t pin_12 :1;
	uint32_t pin_13 :1;
	uint32_t pin_14 :1;
	uint32_t pin_15 :1;
	uint32_t reserve :16;
} GPIOx_IDR_t;

typedef struct
{
	uint32_t pin_0 :1;
	uint32_t pin_1 :1;
	uint32_t pin_2 :1;
	uint32_t pin_3 :1;
	uint32_t pin_4 :1;
	uint32_t pin_5 :1;
	uint32_t pin_6 :1;
	uint32_t pin_7 :1;
	uint32_t pin_8 :1;
	uint32_t pin_9 :1;
	uint32_t pin_10 :1;
	uint32_t pin_11 :1;
	uint32_t pin_12 :1;
	uint32_t pin_13 :1;
	uint32_t pin_14 :1;
	uint32_t pin_15 :1;
	uint32_t reserve :16;
} GPIOx_ODR_t;

typedef struct
{
	uint32_t pin_0 :2;
	uint32_t pin_1 :2;
	uint32_t pin_2 :2;
	uint32_t pin_3 :2;
	uint32_t pin_4 :2;
	uint32_t pin_5 :2;
	uint32_t pin_6 :2;
	uint32_t pin_7 :2;
	uint32_t pin_8 :2;
	uint32_t pin_9 :2;
	uint32_t pin_10 :2;
	uint32_t pin_11 :2;
	uint32_t pin_12 :2;
	uint32_t pin_13 :2;
	uint32_t pin_14 :2;
	uint32_t pin_15 :2;
} GPIOx_PUPDR_t;

/* Enum */
enum
{
	DMA_2 = (uint32_t) 0x40026400,					// 0x4002 6400 - 0x4002 67FF
	DMA_1 = (uint32_t) 0x40026000,					// 0x4002 6000 - 0x4002 63FF
	FLASH_INTERFACE_REG = (uint32_t) 0x40023C00,	// 0x4002 3C00 - 0x4002 3FFF
	RCC = (uint32_t) 0x40023800,					// 0x4002 3800 - 0x4002 3BFF
	CRC = (uint32_t) 0x40023000,					// 0x4002 3000 - 0x4002 33FF
	GPIO_H = (uint32_t) 0x40021C00,					// 0x4002 1C00 - 0x4002 1FFF
	GPIO_E = (uint32_t) 0x40021000,					// 0x4002 1000 - 0x4002 13FF
	GPIO_D = (uint32_t) 0x40020C00,					// 0x4002 0C00 - 0x4002 0FFF
	GPIO_C = (uint32_t) 0x40020800,					// 0x4002 0800 - 0x4002 0BFF
	GPIO_B = (uint32_t) 0x40020400,					// 0x4002 0400 - 0x4002 07FF
	GPIO_A = (uint32_t) 0x40020000,				// 0x4002 0000 - 0x4002 03FF
} AHB1_PERIPHERAL_ADDR_e;

enum
{
	INPUT_MODE = 0x00,
	OUTPUT_MODE = 0x01,
	ALT_FUNC_MODE = 0x02,
	ANALOG_MODE = 0x03,
} GPIOx_MODE_REG_e;

enum
{
	NO_PULL = 0x00, PULL_UP = 0x01, PULL_DOWN = 0x02, RESERVE = 0x03,
} GPIOx_PUPDR_e;

#endif /* MAIN_H_ */
