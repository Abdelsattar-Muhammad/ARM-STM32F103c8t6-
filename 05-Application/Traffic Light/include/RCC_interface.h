/*************************************/
/* Author  : Abdelsattar Muhammad	 */
/* Date    : 27 July 2023        	 */
/* Version : V02                 	 */
/*************************************/ 
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*******************   BUS Definition    *********************/
typedef enum
{
	RCC_AHB=0,
	RCC_APB1,
	RCC_APB2,
	
}BusName_t;


/***************   AHB BITS definition    ******************/
typedef enum 
{
		AHB_DMA1_EN =0,
		AHB_DMA2_EN =1,
		AHB_SRAM_EN =2,
		AHB_FLITF_EN=4,
		AHB_CRC_EN  =6,
		AHB_FSMC_EN =8,
		AHB_SDIO_EN =10,
	
		}AHB_Peripherals_t;

/***************   APB2 BITS definition    ******************/

typedef enum 
{
		APB2_AFIO_EN  =0,
		APB2_GPIOA_EN =2,
		APB2_GPIOB_EN =3,
		APB2_GPIOC_EN =4,
		APB2_GPIOD_EN =5,
		APB2_ADC1_EN  =9,
		APB2_ADC2_EN  =10,
		APB2_TIM1_EN  =11,
		APB2_SPI1_EN  =12,
		APB2_USART1_EN=14,
		APB2_ADC3_EN  =15,

		}APB2_Peripherals_t;
		
/***************   APB1 BITS definition    ******************/

typedef enum 
{
		APB1_TIM2_EN=0,
		APB1_TIM3_EN=1,
		APB1_TIM4_EN=2,
		APB1_SPI2_EN=14,
		APB1_USART2_EN=17,
		APB1_USART3_EN=18,
		APB1_I2C1_EN=21,
		APB1_I2C2_EN=22,
		APB1_USB_EN	=23,
		APB1_CAN_EN	=25,
		
		}APB1_Peripherals_t;

/*******************  Function Definition    *********************/

void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(BusName_t Copy_tBusName,u8 Copy_u8PerNum);
void MRCC_voidDisableClock(BusName_t Copy_tBusName,u8 Copy_u8PerNum);
void MRCC_voidEnableClockSysSecurity(void);
void MRCC_voidDisableClockSysSecurity(void);

#endif