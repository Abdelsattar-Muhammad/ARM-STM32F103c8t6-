/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 27 July 2023            */
/* Version : V02                  	 */
/*************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/************************** Register Definitions *****************************/
typedef struct {
	
		volatile u32  CR  ;    
		volatile u32  CFGR;    
		volatile u32  CIR  ;  	
		volatile u32  APB2RSTR;
		volatile u32  APB1RSTR;
		volatile u32  AHBENR ; 	//  for AHB  Bus 
		volatile u32  APB2ENR ; //  for APB2 Bus 
		volatile u32  APB1ENR;  //   for APB1  Bus 
		volatile u32  BDCR;    
		volatile u32  CSR;
		
}RCC_t;

/************************** BASE ADDRESS *****************************/

#define RCC_BASE_ADDRESS 0x40021000

#define RCC ((volatile RCC_t*) RCC_BASE_ADDRESS)



#endif  