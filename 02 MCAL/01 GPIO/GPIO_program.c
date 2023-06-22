/***************************************************/
/* Author  : Abdelsattar Muhammad    		  */
/* Date    : 17 June 2023            	     */
/* Version : V03                        		 */
/*************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"
 
void MGPIO_voidSetPinDirection(PORT_t Copy_u8Port,PINS_t Copy_u8Pin,PIN_Mode_t Copy_u8Mode)
{
	
	switch(Copy_u8Port)
	{
		
	case GPIOA :
			if(Copy_u8Pin <= 7 )	
			{	
				GPIO_A->CRL &= ~( (0xF) << ( Copy_u8Pin * 4 ) );
				GPIO_A->CRL |= ( (Copy_u8Mode) << (Copy_u8Pin * 4) );
				
			}
			else if (Copy_u8Pin <=15 )
			{
				
				Copy_u8Pin -= 8;
				GPIO_A->CRH &= ~( (0xF) << (Copy_u8Pin * 4 ));
				GPIO_A->CRH |= ((Copy_u8Mode) << (Copy_u8Pin * 4 ));
			}
	break;
	case GPIOB :
			if(Copy_u8Pin <= 7)	
			{	
				GPIO_B->CRL &= ~((0xF) << ( Copy_u8Pin * 4 ));
				GPIO_B->CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4 ));
			}
			else if (Copy_u8Pin <=15)
			{
				Copy_u8Pin -= 8;
				GPIO_B->CRH &= ~((0xF) << ( Copy_u8Pin * 4 ));
				GPIO_B->CRH |= ((Copy_u8Mode) << ( Copy_u8Pin * 4 ));
			}
	break;

	case GPIOC :

			if(Copy_u8Pin <= 7)	
			{	
				GPIO_C->CRL &= ~((0xF) << (Copy_u8Pin * 4 ));
				GPIO_C->CRL |= ((Copy_u8Mode) << (Copy_u8Pin * 4 ));	
			}
			else if (Copy_u8Pin <=15)
			{
				Copy_u8Pin -= 8;
				GPIO_C->CRH &= ~((0xF) << (Copy_u8Pin * 4 ) );
				GPIO_C->CRH |= (( Copy_u8Mode )<< (Copy_u8Pin * 4 ));
			}
	break;

	
	default : 
	/* #error */
	break;
	}



}

void MGPIO_voidSetPinValue(PORT_t Copy_u8Port,PINS_t Copy_u8Pin,Value_t Copy_u8Value )
{
	switch(Copy_u8Port)
	{
	
		case GPIOA :
			if(Copy_u8Value == HIGH )
			{
			GPIO_A->BSRR=(1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == LOW )
			{
			GPIO_A->BRR=(1 << Copy_u8Pin);
			}
			/************   if Mode Is Input PULL Down or Up  *********/
			else if(Copy_u8Value == PULL_UP)
			{ 
			SET_BIT(GPIO_A->ODR,Copy_u8Pin);	
			}
			
			else if(Copy_u8Value == PULL_DOWN)
			{
			CLR_BIT(GPIO_A->ODR,Copy_u8Pin);
			}
			
		break;
		case GPIOB :
			if(Copy_u8Value == HIGH )
			{
			GPIO_B->BSRR=(1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == LOW )
			{
			GPIO_B->BRR=(1 << Copy_u8Pin);
			}
			/************   if Mode Is Input PULL Down or Up  *********/
			else if(Copy_u8Value == PULL_UP)
			{ 
			SET_BIT(GPIO_B->ODR,Copy_u8Pin);	
			}
			
			else if(Copy_u8Value == PULL_DOWN)
			{
			CLR_BIT(GPIO_B->ODR,Copy_u8Pin);
			}
		break;
		case GPIOC :
			if(Copy_u8Value == HIGH )
			{
			GPIO_C->BSRR=(1 << Copy_u8Pin);
			}
			else if(Copy_u8Value == LOW )
			{
			GPIO_C->BRR=(1 << Copy_u8Pin);
			}
			/************   if Mode Is Input PULL Down or Up  *********/
			else if(Copy_u8Value == PULL_UP)
			{ 
			SET_BIT(GPIO_C->ODR,Copy_u8Pin);	
			}
			
			else if(Copy_u8Value == PULL_DOWN)
			{
			CLR_BIT(GPIO_C->ODR,Copy_u8Pin);
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
			if(GET_BIT(GPIO_A->ODR,Copy_u8Pin) == LOW )
			{
			GPIO_A->BSRR=(1 << Copy_u8Pin);
			}
			else if(GET_BIT(GPIO_A->ODR,Copy_u8Pin) == HIGH )
			{
			GPIO_A->BRR=(1 << Copy_u8Pin);
			}
		break;
		case GPIOB :
			if(GET_BIT(GPIO_B->ODR,Copy_u8Pin) == LOW )
			{
			GPIO_B->BSRR=(1 << Copy_u8Pin);
			}
			else if(GET_BIT(GPIO_B->ODR,Copy_u8Pin) == HIGH)
			{
			GPIO_B->BRR=(1 << Copy_u8Pin);
			}
		break;
		case GPIOC :
			if(GET_BIT(GPIO_C->ODR,Copy_u8Pin) == LOW )
			{
			GPIO_C->BSRR=(1 << Copy_u8Pin);
			}
			else if(GET_BIT(GPIO_C->ODR,Copy_u8Pin) == HIGH )
			{
			GPIO_C->BRR=(1 << Copy_u8Pin);
			}
		break;	
			 
		default :
		break ;
		
	}

}

void MGPIO_voidSetLowNibbleValue(PORT_t Copy_u8Port,u8 Copy_u8Value)
{
	
	switch(Copy_u8Port)
	{
		case GPIOA :
		GPIO_A->ODR = (GPIO_A->ODR & 0xFF00) | ( 0x00FF & Copy_u8Value);
		break;
		case GPIOB :
		GPIO_B->ODR = (GPIO_B->ODR & 0xFF00) | ( 0x00FF & Copy_u8Value);
		break;
		case GPIOC :
		GPIO_C->ODR = (GPIO_C->ODR & 0xFF00) | ( 0x00FF & Copy_u8Value);
		break;
		
		default:
		/*Error*/
		break;
	}
	
	
}

u8 MGPIO_u8GetPinValue(PORT_t Copy_u8Port,PINS_t Copy_u8Pin )
{
	u8 return_Val=0; 
	
	switch(Copy_u8Port)
	{
		case GPIOA :
		return_Val=GET_BIT(GPIO_A->IDR,Copy_u8Pin);
		break;
		case GPIOB :
		return_Val=GET_BIT(GPIO_B->IDR,Copy_u8Pin);
		break;
		case GPIOC :
		return_Val=GET_BIT(GPIO_C->IDR,Copy_u8Pin);
		break;
		
		default:
		/*Error*/
		break;
	}
	return return_Val;


}


void MGPIO_voidLockPin(PORT_t Copy_u8Port,PINS_t Copy_u8Pin)
{
	switch(Copy_u8Port)
	{
		case GPIOA :
		GPIO_A->LCKR = (1 << Copy_u8Pin);
		break;
		case GPIOB :
		GPIO_B->LCKR = (1 << Copy_u8Pin);
		break;
		case GPIOC :
		GPIO_C->LCKR = (1 << Copy_u8Pin);
		break;
		
		default:
		/*Error*/
		break;
	}
	
}
