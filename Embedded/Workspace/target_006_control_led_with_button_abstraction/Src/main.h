#ifndef MAIN_H_
#define MAIN_H_

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

#endif /* MAIN_H_ */
