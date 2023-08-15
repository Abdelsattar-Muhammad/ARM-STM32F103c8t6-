/*************************************/
/* Author  : Abdelsattar Muhammad 	 */
/* Date    : 27 July 2023       	 */
/* Version : V02                	 */
/*************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H 

/************************** Clock Types *****************************/
typedef enum
{
            RCC_HSE_CRYSTAL=0,	 	 //if user want to work at HSE_CRYSTAL
            RCC_HSE_RC,			     //if user want to work at HSE_RC
            RCC_HSI,    			 //if user want to work at HSI
            RCC_PLL,	 			 //if user want to work at PLL
}RCC_Mode_t;


#define RCC_ClOCK_TYPE RCC_HSE_CRYSTAL


/************************** PLL Options *****************************/

typedef enum
{
	
	RCC_PLL_IN_HSI_DIV_2=0,
	RCC_PLL_IN_HSE_DIV_2,
	RCC_PLL_IN_HSE, 	
		
}PLL_Options;
	
/*********************************************************************/ 
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
