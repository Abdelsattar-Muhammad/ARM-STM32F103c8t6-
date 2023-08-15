/*************************************************/
/* Author  : Abdelsattar Muhammad    		 */
/* Date    : 29 MAY 2023            		    */
/* Version : V01                     		*/
/************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
 
void MGPIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	
	switch(Copy_u8Port)
	{
		
			case GPIOA :
			if(Copy_u8Pin <= 7 )	
			{	
				GPIOA_CRL &= ~( (0xF) << ( Copy_u8Pin * 4 ) );
				GPIOA_CRL |= ( (Copy_u8Mode) << (Copy_u8Pin * 4) );
				
			/************   if Mode Is Input PULL Down or Up  *********/

				if(Copy_u8Mode == INPUT_PULL_UP)
				{ 
					SET_BIT(GPIOA_ODR,Copy_u8Pin);	}
				
				else if (Copy_u8Mode == INPUT_PULL_DOWN)
				{
					CLR_BIT(GPIOA_ODR,Copy_u8Pin);	}
			
			}
			else if (Copy_u8Pin <=15 )
			{
				
				Copy_u8Pin -= 8;
				GPIOA_CRH &= ~( (0xF) << (Copy_u8Pin * 4 ));
				GPIOA_CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4 ));
			
			/************   if Mode Is Input PULL Down or Up  *********/
				
				if(Copy_u8Mode == INPUT_PULL_UP)
				{ 
					SET_BIT(GPIOA_ODR,Copy_u8Pin);	}
				else if (Copy_u8Mode == INPUT_PULL_DOWN)
				{
					CLR_BIT(GPIOA_ODR,Copy_u8Pin);	}
				
			}
	break;
	case GPIOB :
			if(Copy_u8Pin <= 7)	
			{	
				GPIOB_CRL &= ~((0xF) << ( Copy_u8Pin * 4 ));
				GPIOB_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4 ));
			
			/************   if Mode Is Input PULL Down or Up  *********/
			
				if(Copy_u8Mode == INPUT_PULL_UP)
				{ 
					SET_BIT(GPIOB_ODR,Copy_u8Pin);	}
				else if (Copy_u8Mode == INPUT_PULL_DOWN)
				{
					CLR_BIT(GPIOB_ODR,Copy_u8Pin);	}
			}
			else if (Copy_u8Pin <=15)
			{
				Copy_u8Pin -= 8;
				GPIOB_CRH &= ~((0xF) << ( Copy_u8Pin * 4 ));
				GPIOB_CRH |= ((Copy_u8Mode) << ( Copy_u8Pin * 4 ));

			/************   if Mode Is Input PULL Down or Up  *********/
			
				if(Copy_u8Mode == INPUT_PULL_UP)
				{ 
					SET_BIT(GPIOB_ODR,Copy_u8Pin);}
				else if (Copy_u8Mode == INPUT_PULL_DOWN)
				{
					CLR_BIT(GPIOB_ODR,Copy_u8Pin);}
			}
	break;

	case GPIOC :

			if(Copy_u8Pin <= 7)	
			{	
				GPIOC_CRL &= ~((0xF) << (Copy_u8Pin * 4 ));
				GPIOC_CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4 ));

			/************   if Mode Is Input PULL Down or Up  *********/
			
				if(Copy_u8Mode == INPUT_PULL_UP)
				{ 
					SET_BIT(GPIOC_ODR,Copy_u8Pin);}
				else if (Copy_u8Mode == INPUT_PULL_DOWN)
				{
					CLR_BIT(GPIOC_ODR,Copy_u8Pin);}
			}
			else if (Copy_u8Pin <=15)
			{
				Copy_u8Pin -= 8;
				GPIOC_CRH &= ~((0xF) << (Copy_u8Pin * 4 ) );
				GPIOC_CRH |= (( Copy_u8Mode )<< (Copy_u8Pin * 4 ));

			/************   if Mode Is Input PULL Down or Up  *********/
			
				if(Copy_u8Mode == INPUT_PULL_UP)
				{ 
					SET_BIT(GPIOC_ODR,Copy_u8Pin);}
				else if (Copy_u8Mode == INPUT_PULL_DOWN)
				{
					CLR_BIT(GPIOC_ODR,Copy_u8Pin);}
			}
	break;

	
	default : /* #error */ break;
	}



}

void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value )
{
	switch(Copy_u8Port)
	{
	
		case GPIOA :
			if(Copy_u8Value == GPIO_HIGH )
			{
			GPIOA_BSRR=(1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_LOW )
			{
			GPIOA_BRR=(1 << Copy_u8Pin); 
			}
		break;
		case GPIOB :
			if(Copy_u8Value == GPIO_HIGH )
			{
			GPIOB_BSRR=(1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_LOW )
			{
			GPIOB_BRR=(1 << Copy_u8Pin); 
			}
		break;
		case GPIOC :
			if(Copy_u8Value == GPIO_HIGH )
			{
			GPIOC_BSRR=(1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_LOW )
			{
			GPIOC_BRR=(1 << Copy_u8Pin); 
			}
		break;	
			 
		default :
		break ;
		
	}

}

void MGPIO_voidToggleValue(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
			if(GET_BIT(GPIOA_ODR) == GPIO_LOW )
			{
			GPIOA_BSRR=(1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == GPIO_HIGH )
			{
			GPIOA_BRR=(1 << Copy_u8Pin); 
			}
		break;
		case GPIOB :
			if(GET_BIT(GPIOB_ODR) == GPIO_LOW )
			{
			GPIOB_BSRR=(1 << Copy_u8Pin);
			}
			else if(GET_BIT(GPIOB_ODR) == GPIO_HIGH)
			{
			GPIOB_BRR=(1 << Copy_u8Pin); 
			}
		break;
		case GPIOC :
			if(GET_BIT(GPIOC_ODR) == GPIO_LOW )
			{
			GPIOC_BSRR=(1 << Copy_u8Pin);
			}
			else if(GET_BIT(GPIOC_ODR) == GPIO_HIGH )
			{
			GPIOC_BRR=(1 << Copy_u8Pin); 
			}
		break;	
			 
		default :
		break ;
		
	}

}

void MGPIO_voidSetLowNibbleValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	
	switch(Copy_u8Port)
	{
		case GPIOA :
		GPIOA_ODR = (GPIOA_ODR & 0xFF00) | ( 0x00FF & Copy_u8Value);
		break;
		case GPIOB :
		GPIOB_ODR = (GPIOC_ODR & 0xFF00) | ( 0x00FF & Copy_u8Value);
		break;
		case GPIOC :
		GPIOC_ODR = (GPIOC_ODR & 0xFF00) | ( 0x00FF & Copy_u8Value);
		break;
		
		default:
		/*Error*/
		break;
	}
	
	
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin )
{
	u8 return_Val=0; 
	
	switch(Copy_u8Port)
	{
		case GPIOA :
		return_Val=GET_BIT(GPIOA_IDR,Copy_u8Pin);
		break;
		case GPIOB :
		return_Val=GET_BIT(GPIOB_IDR,Copy_u8Pin);
		break;
		case GPIOC :
		return_Val=GET_BIT(GPIOC_IDR,Copy_u8Pin);
		break;
		
		default:
		/*Error*/
		break;
	}
	return return_Val;


}


void MGPIO_voidLockPin(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
		GPIOA_LCKR = (1 << Copy_u8Pin);
		break;
		case GPIOB :
		GPIOB_LCKR = (1 << Copy_u8Pin);
		break;
		case GPIOC :
		GPIOC_LCKR = (1 << Copy_u8Pin);
		break;
		
		default:
		/*Error*/
		break;
	}
	
}