  
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*******************   BUS Definition    *********************/
#define RCC_AHB    0
#define RCC_APB1   1
#define RCC_APB2   2
/***************   AHB BITS definition    ******************/
#define AHB_DMA1_EN         0
#define AHB_DMA2_EN         1
#define AHB_SRAM_EN         2
#define AHB_FLITF_EN        4
#define AHB_CRC_EN         	6
#define AHB_FSMC_EN         8
#define AHB_SDIO_EN         10
/***************   APB2 BITS definition    ******************/
#define APB2_AFIO_EN        0
#define APB2_GPIOA_EN       2
#define APB2_GPIOB_EN       3
#define APB2_GPIOC_EN       4
#define APB2_GPIOD_EN       5
#define APB2_ADC1_EN        9
#define APB2_ADC2_EN        10
#define APB2_TIM1_EN        11
#define APB2_SPI1_EN        12
#define APB2_USART1_EN      14
#define APB2_ADC3_EN        15
/***************   APB1 BITS definition    ******************/
#define APB1_TIM2_EN		0
#define APB1_TIM3_EN		1
#define APB1_TIM4_EN		2
#define APB1_SPI2_EN		14
#define APB1_USART2_EN 		17
#define APB1_USART3_EN 		18
#define APB1_I2C1_EN		21
#define APB1_I2C2_EN		22
#define APB1_USB_EN			23
#define APB1_CAN_EN			25

/*******************  Function Definition    *********************/

void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusName,u8 Copy_u8PerNum);
void MRCC_voidDisableClock(u8 Copy_u8BusName,u8 Copy_u8PerNum);

void MRCC_voidEnableClockSysSecurity(void);

void MRCC_voidDisableClockSysSecurity(void);

#endif