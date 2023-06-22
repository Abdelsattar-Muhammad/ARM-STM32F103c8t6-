/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 7 June 2023             */
/* Version : V01                     */
/*************************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/********************** REGISTER Definitions *****************************/

typedef struct{
	
		volatile u32 CTRL;
		volatile u32 LOAD;
		volatile u32 VAL;
		volatile u32 CALIB;
		
	}STK_t;
	
/********************** BASE ADDRESS REGISTER  *****************************/

#define STK_BASE_ADDRESS  0xE000E010 


#define STK ((volatile STK_t *)STK_BASE_ADDRESS)



#endif
