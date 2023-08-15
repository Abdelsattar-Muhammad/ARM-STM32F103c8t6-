/************************************************/
/* Author  : Abdelsattar Muhammad    		   */
/* Date    : 30 July 2023              	      */
/* Version : V03                    	   	 */
/********************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

/******************  REGISTERS Definitions ******************/

typedef struct{
	
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR  ;
	volatile u32 LCKR  ;
}GPIO_t;
/******************  Base Address Definitions ******************/

#define 	GPIOA_BASE_ADDRESS 	 0x40010800
#define	 	GPIOB_BASE_ADDRESS	 0x40010C00
#define	 	GPIOC_BASE_ADDRESS	 0x40011000


/*********************	GPIOA (Port A)   ******************/

#define  GPIO_A ((volatile GPIO_t *) GPIOA_BASE_ADDRESS)

/********************  GPIOB (Port B)   ******************/

#define  GPIO_B ((volatile GPIO_t*) GPIOB_BASE_ADDRESS)

/********************  GPIOC (Port C)   ******************/

#define  GPIO_C ((volatile GPIO_t*) GPIOC_BASE_ADDRESS)



#endif  
