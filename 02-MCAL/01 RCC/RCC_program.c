/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 MAY 2023             */
/* Version : V01                     */
/*************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"
 
 /********** Initionlizie clock of micro-controller  ************/
 
void MRCC_voidInitSysClock(void)
{
		/************ HSE CRYSTAL  ************/

	#if RCC_ClOCK_TYPES == RCC_HSE_CRYSTAL 
	RCC_CFGR=0x00000001;//HSE (Crystal) selected as system clock
	RCC_CR = 0x00010000;//Enable HSE with no bypass
	
		/************ HSE RC *********/

	#elif 	RCC_ClOCK_TYPES == RCC_HSE_RC 
	RCC_CFGR=0x00000001;//HSE(RC) selected as system clock
	RCC_CR = 0x00050000;//Enable External high-speed clock bypass
	
		/************ HSI ************/

	#elif 	RCC_ClOCK_TYPES == RCC_HSI
	RCC_CFGR=0x00000000; // HSI selected as system clock
	RCC_CR=0x00000081;  // Enable HSI
	
		/************  PLL  *************/
	#elif  RCC_ClOCK_TYPES == RCC_PLL
		
		#if RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2

		//Enable HSI
		RCC_CR = 0x00000000;
		//PLL selected as system clock		
		RCC_CFGR &= ~((0b1111) << 18 ) ; //clear bits 18~21
		RCC_CFGR = (0x00000002)|((RCC_PLL_MUL_VAL-2)<<18);
		//Enable PLL 
		RCC_CR = 0x01000000;

		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2
		//Enable HSE 
		RCC_CR = 0x00010000;
		//HSE clock divided by 2 & Sellect PLL
		RCC_CFGR &= ~((0b1111) << 18 ) ; //clear bits 18~21
		RCC_CFGR = (0x00020002)|((RCC_PLL_MUL_VAL-2)<<18);
		RCC_CR = 0x01010000;
		
		#elif RCC_PLL_INPUT == RCC_PLL_IN_HSE
		//Enable HSE 
		RCC_CR = 0x00010000;
		RCC_CFGR = (0x00000002)|((RCC_PLL_MUL_VAL-2)<<18);
		//Enable PLL 
		RCC_CR = 0x01010000;
	/**********************************************************/
		#else
		/*#error("You Chosed Wrong Clock Type")*/
		#endif
		
		#endif
}

void MRCC_voidEnableClock(u8 Copy_u8BusName,u8 Copy_u8PerNum)
{
	if(Copy_u8PerNum<=31)
	{
		switch(Copy_u8BusName)
		{
			case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PerNum);
			break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerNum);
			break;
			case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerNum);
			break;
			
			default :
			/*return error*/
			 break;
		}
	}
	else
	{
		/*return ERROR*/
	}
	
	
}

void MRCC_voidDisableClock(u8 Copy_u8BusName,u8 Copy_u8PerNum)
{
	if(Copy_u8PerNum<=31)
	{
		switch(Copy_u8BusName)
		{
			case RCC_AHB  :	CLR_BIT(RCC_AHBENR,Copy_u8PerNum);
			break;
			case RCC_APB1 :	CLR_BIT(RCC_APB1ENR,Copy_u8PerNum);
			break;
			case RCC_APB2 :	CLR_BIT(RCC_APB2ENR,Copy_u8PerNum);
			break;
			
			default :
			/*return error*/
			 break;
	
		}
	}
	else
	{
		/*return ERROR*/
	}
	
	
}

/*********************** Clock security system enable**************************/

void MRCC_voidEnableClockSysSecurity(void)
{
	SET_BIT(RCC_CR,19U);
	
}
/********************** Clock security system disable**************************/

void MRCC_voidDisableableClockSysSecurity(void)
{
	CLR_BIT(RCC_CR,19U);
	
}
