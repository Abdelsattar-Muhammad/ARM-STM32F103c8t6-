/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 13 Aug 2023              */
/* Version : V02                     */
/*************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"

void AFIO_voidSetEXTIConfiguration(EXTI_LINE_t Copy_tEXTILine,PORT_t Copy_tPortMap)
{
	u8 Local_u8Line=Copy_tEXTILine / 4 ;
	u8 Local_u8Port=Copy_tPortMap % 4  ;
	
	
	AFIO->EXTICR[Local_u8Line] &=  ~((0b1111) << (Local_u8Line * 4 )) ;//Clear

	AFIO->EXTICR[Local_u8Line] |= ( (Local_u8Port) <<(Local_u8Line *4) );//Set
	
	
	
}

void AFIO_voidSPI1_REMAP(PORT_t Copy_tPortMap)
{
	switch(Copy_tPortMap)
	{
		case GPIOA : CLR_BIT(AFIO->MAPR,0); break;
		case GPIOB : SET_BIT(AFIO->MAPR,0); break;
	}
	
}