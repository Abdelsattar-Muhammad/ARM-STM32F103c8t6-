/************************************************/
/* Author  : Abdelsattar Muhammad    		   */
/* Date    : 30 July 2023              	      */
/* Version : V03                    	   	 */
/********************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
/***************   Pins State  *******************/
typedef enum{
		LOW=0,
		HIGH,
		PULL_UP,
		PULL_DOWN,
			
		}Value_t;

/***************   GPIO(PORT) definition  *******************/
typedef enum {
		GPIOA=0,
		GPIOB,
		GPIOC,
			 }PORT_t;
		
/***************   	PIN definition  	 *******************/
typedef enum{
		PIN0=0, 
		PIN1,
		PIN2, 
		PIN3,
		PIN4, 
		PIN5, 
		PIN6, 
		PIN7, 
		PIN8, 
		PIN9, 
		PIN10,
		PIN11,
		PIN12,
		PIN13,
		PIN14,
		PIN15,
			}PINS_t;



/***************   	Modes definition  	 *******************/
typedef enum{
/*
	//	PP == Push Pull
    //	OD == Open Drain
    //	AF == Alternate Function
*/

	/***************   INPUT Mode definition   ******************/
		
		INPUT_ANALOG=0, 	//0b0000	 	
	    
		INPUT_FLOATING=4,	//0b0010
	    
		INPUT_PULL_UP=8,	//0b1000 	

        INPUT_PULL_DOWN=8,	//0b1000
	
	/***************   OUTPUT Mode definition   ******************/
		//FOR 2 MHZ
		OUTPUT_SPEED_2MHZ_PP=2,  		//0b0010 
    	OUTPUT_SPEED_2MHZ_OD=3, 		//0b0110 
		OUTPUT_SPEED_2MHZ_AF_PP=10, 	//0b1010 
		OUTPUT_SPEED_2MHZ_AF_OD=14, 	//0b1110 
		//FOR 10 MHZ
		OUTPUT_SPEED_10MHZ_PP=1,	 	//0b0001
		OUTPUT_SPEED_10MHZ_OD=5, 		//0b0101
		OUTPUT_SPEED_10MHZ_AF_PP=9, 	//0b1001
		OUTPUT_SPEED_10MHZ_AF_OD=13, 	//0b1101
		//FOR 50 MHZ
		OUTPUT_SPEED_50MHZ_PP=3, 		//0b0011 
		OUTPUT_SPEED_50MHZ_OD=7, 		//0b0111
		OUTPUT_SPEED_50MHZ_AF_PP=11,	//0b1011	
		OUTPUT_SPEED_50MHZ_AF_OD=15, 	//0b1111
	
			}PIN_Mode_t;
		
		
		

/***************   Function definition   ******************/

void MGPIO_voidSetPinDirection(PORT_t Copy_tPort,PINS_t Copy_tPin,PIN_Mode_t Copy_tMode);

void MGPIO_voidSetPinValue(PORT_t Copy_tPort,PINS_t Copy_tPin,Value_t Copy_tValue);

void MGPIO_voidSetLowNibbleValue(PORT_t Copy_tPort,u8 Copy_u8Value);

u8 	 MGPIO_u8GetPinValue(PORT_t Copy_tPort,PINS_t Copy_tPin);

void MGPIO_voidToggleValue(PORT_t Copy_tPort,PINS_t Copy_tPin);

/* This Function Locked Pin Direction Mode */

void MGPIO_voidLockPin(PORT_t Copy_tPort,PINS_t Copy_tPinn);


#endif
