/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 14 June 2023             */
/* Version : V01                     */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


 static void (*MEXTI_CallBack[16])(void);

/*********** Function Of Enable EXTI *************/
void MEXTI_voidEnableEXTI(EXTI_LINE_t Copy_u8EXTILine)
{
	SET_BIT(EXTI->IMR,Copy_u8EXTILine);
	
}
/*********** Function Of Disable EXTI *************/
void MEXTI_voidDisableEXTI(EXTI_LINE_t Copy_u8EXTILine)
{
	CLR_BIT(EXTI->IMR,Copy_u8EXTILine);
	
}
/*********** Function Of Software Trigger *************/
void MEXTI_voidSoftWareTrigger(EXTI_LINE_t Copy_u8EXTILine)
{
	SET_BIT(EXTI->PR,Copy_u8EXTILine); //Clear Pending Flag
	SET_BIT(EXTI->SWIER,Copy_u8EXTILine);
	
}

void MEXTI_voidEventTrigger(EXTI_LINE_t Copy_u8EXTILine,EXTI_TRIG_t Copy_u8EventTrig)
{
	switch(Copy_u8EventTrig)
	{
		case EXTI_FALLING:
		SET_BIT(EXTI->FTSR,Copy_u8EXTILine);
		CLR_BIT(EXTI->RTSR,Copy_u8EXTILine);
		break;
		case EXTI_RISING:
		SET_BIT(EXTI->RTSR,Copy_u8EXTILine);
		CLR_BIT(EXTI->FTSR,Copy_u8EXTILine);
		break;
		case EXTI_ON_CHANGE:
		SET_BIT(EXTI->RTSR,Copy_u8EXTILine);
		SET_BIT(EXTI->FTSR,Copy_u8EXTILine);
		break;
		default :
		//error
		break;
	}
	
	
}
/*********** Function Of Set CallBack *************/
void  MEXTI_voidSetCallBack(EXTI_LINE_t Copy_u8EXTILine,void (*Copy_Ptr)(void))
{
	MEXTI_CallBack[Copy_u8EXTILine]=Copy_Ptr;
	 
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
	
	
}
