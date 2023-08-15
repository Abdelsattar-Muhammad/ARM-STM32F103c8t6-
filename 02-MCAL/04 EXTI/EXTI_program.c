/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 2 Aug 2023             */
/* Version : V01                     */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


static void (*MEXTI_CallBack[16])(void);

/*********** Function Of Enable EXTI *************/
void MEXTI_voidEnableEXTI(EXTI_LINE_t Copy_tEXTILine)
{
	SET_BIT(EXTI->IMR,Copy_tEXTILine);
	
}
/*********** Function Of Disable EXTI *************/
void MEXTI_voidDisableEXTI(EXTI_LINE_t Copy_tEXTILine)
{
	CLR_BIT(EXTI->IMR,Copy_tEXTILine);
	
}
/*********** Function Of Software Trigger *************/
void MEXTI_voidSoftWareTrigger(EXTI_LINE_t Copy_tEXTILine)
{
	SET_BIT(EXTI->PR,Copy_tEXTILine); //Clear Pending Flag
	SET_BIT(EXTI->SWIER,Copy_tEXTILine);
	
}

void MEXTI_voidEventTrigger(EXTI_LINE_t Copy_tEXTILine,EXTI_TRIG_t Copy_tEventTrig)
{
	switch(Copy_tEventTrig)
	{
		case EXTI_FALLING:
		SET_BIT(EXTI->FTSR,Copy_tEXTILine);
		CLR_BIT(EXTI->RTSR,Copy_tEXTILine);
		break;
		case EXTI_RISING:
		SET_BIT(EXTI->RTSR,Copy_tEXTILine);
		CLR_BIT(EXTI->FTSR,Copy_tEXTILine);
		break;
		case EXTI_ON_CHANGE:
		SET_BIT(EXTI->RTSR,Copy_tEXTILine);
		SET_BIT(EXTI->FTSR,Copy_tEXTILine);
		break;
		default :
		//error
		break;
	}
	
	
}
/*********** Function Of Set CallBack *************/
void  MEXTI_voidSetCallBack(EXTI_LINE_t Copy_tEXTILine,void (*Copy_FPtr)(void))
{
	MEXTI_CallBack[Copy_tEXTILine]=Copy_FPtr;
	 
}

/************* Function of EXTIx_IRQHandler Interrupt *********************/
// This is Function Call a MEXTI_CallBack() Funtion To Do when Interrupt is Fired 
void EXTI0_IRQHandler(void)
{
	MEXTI_CallBack[0]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI->PR , EXTI_LINE0);

}
void EXTI1_IRQHandler(void)
{
	MEXTI_CallBack[1]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI->PR , EXTI_LINE1);

	
}
void EXTI2_IRQHandler(void)
{
	MEXTI_CallBack[2]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI->PR , EXTI_LINE2);

	
}
void EXTI3_IRQHandler(void)
{
	MEXTI_CallBack[3]();
	/*	Clear pending Bit		*/
	SET_BIT(EXTI->PR , EXTI_LINE3);

	
}

void EXTI4_IRQHandler(void)
{
	MEXTI_CallBack[4]();	
	/*	Clear pending Bit		*/
	SET_BIT(EXTI->PR , EXTI_LINE4);
}
void EXTI9_5_IRQHandler (void)
{
	u8 Local_EXTI_Detect=0;
	for(u8 counter=EXTI_LINE5; counter<=EXTI_LINE9; counter++)
	{
		Local_EXTI_Detect = GET_BIT(EXTI->PR,counter);
		if(Local_EXTI_Detect == 1)
		{
			MEXTI_CallBack[counter]();
		}
		Local_EXTI_Detect=0;
	}
	EXTI->PR |= 0x03E0; /* clear interrupt pending flag 5~9 */

}
void EXTI15_10_IRQHandler (void)
{
	u8 Local_EXTI_Detect=0;
	for(u8 counter=EXTI_LINE10; counter<=EXTI_LINE15; counter++)
	{
		Local_EXTI_Detect = GET_BIT(EXTI->PR,counter);
		if(Local_EXTI_Detect == 1)
		{
			MEXTI_CallBack[counter]();
		}
		Local_EXTI_Detect=0;
	}
	EXTI->PR |= 0xFC00; /* clear interrupt pending flag 10~15 */

}