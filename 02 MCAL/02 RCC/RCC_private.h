/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 17 JUNE 2023            */
/* Version : V02                  	 */
/*************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/************************** Register Definitions *****************************/
typedef enum {
	
		volatile u32  CR  ;    
		volatile u32  CFGR;    
		volatile u32  CIR  ;  	
		volatile u32  APB2RSTR;
		volatile u32  APB1RSTR;
		volatile u32  AHBENR ; 
		volatile u32  APB2ENR ;
		volatile u32  APB1ENR; 
		volatile u32  BDCR;    
		volatile u32  CSR;
	
	
}RCC_t;

/************************** BASE ADDRESS *****************************/

#define RCC_BASE_ADDRESS 0x40021000

#define RCC ((volatile RCC_t*) RCC_BASE_ADDRESS)

/************************** Clock Types *****************************/

typedef enum
{
            RCC_HSE_CRYSTAL=0,	 	 //if user want to work at HSE_CRYSTAL
            RCC_HSE_RC,			     //if user want to work at HSE_RC
            RCC_HSI,    			 //if user want to work at HSI
            RCC_PLL,	 			 //if user want to work at PLL
}RCC_Mode_t;


/************************** PLL Options *****************************/

typedef enum
{
	
	RCC_PLL_IN_HSI_DIV_2=0,
	RCC_PLL_IN_HSE_DIV_2,
	RCC_PLL_IN_HSE, 	
	
	
}PLL_Options;


#endif  