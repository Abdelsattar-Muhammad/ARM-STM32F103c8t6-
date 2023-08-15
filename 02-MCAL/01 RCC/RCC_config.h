/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 26 MAY 2023             */
/* Version : V01                     */
/*************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H 
/*		    
	Options :
			RCC_HSI    	     //if user want to work at HSI
			RCC_HSE_RC     	 //if user want to work at HSE_RC
			RCC_HSE_CRYSTAL  //if user want to work at HSE_CRYSTAL
			RCC_PLL   					
*********************************************************************/ 
#define RCC_ClOCK_TYPE RCC_HSE_CRYSTAL

/* 	
	Options :
			RCC_PLL_IN_HSI_DIV_2
			RCC_PLL_IN_HSE_DIV_2
			RCC_PLL_IN_HSE		
*********************************************************************/ 
/*   Note: Select Value only if you have PLL input clock source 	*/
/********************************************************************/
#if  RCC_ClOCK_TYPE==RCC_PLL
#define RCC_PLL_INPUT RCC_PLL_IN_HSI_DIV_2 
#endif

/*
	options of multiplication value from 2 to 16 
*****************************************************************	
	Note: Select Value only if you have PLL input clock source 
*****************************************************************/ 

#if  RCC_ClOCK_TYPE==RCC_PLL
#define RCC_PLL_MUL_VAL 4
#endif	


#endif
