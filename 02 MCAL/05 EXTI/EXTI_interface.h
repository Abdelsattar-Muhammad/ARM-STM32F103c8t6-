/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 14 June 2023             */
/* Version : V01                     */
/*************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


typedef enum
{
	EXTI_LINE0 =0,
	EXTI_LINE1   ,
	EXTI_LINE2   ,
	EXTI_LINE3   ,
	EXTI_LINE4   ,
	EXTI_LINE5   ,
	EXTI_LINE6   ,
	EXTI_LINE7   ,
	EXTI_LINE8   ,
	EXTI_LINE9   ,
	EXTI_LINE10  ,
	EXTI_LINE11  ,
	EXTI_LINE12  ,
	EXTI_LINE13  ,
	EXTI_LINE14  ,
	EXTI_LINE15
}EXTI_LINE_t;

typedef enum
{
	EXTI_FALLING =0  ,
	EXTI_RISING     ,
	EXTI_ON_CHANGE   

}EXTI_TRIG_t;

typedef enum
{
	EXTI_PORTA =0   ,
	EXTI_PORTB      ,
	EXTI_PORTC      ,



}EXTI_PORT_t;

void MEXTI_voidEnableEXTI(EXTI_LINE_t Copy_u8EXTILine);

void MEXTI_voidEventTrigger(EXTI_LINE_t Copy_u8EXTILine, EXTI_TRIG_t Copy_u8EventTrig);

void MEXTI_voidDisableEXTI(EXTI_LINE_t Copy_u8EXTILine);

void MEXTI_voidSoftWareTrigger(EXTI_LINE_t Copy_u8EXTILine);

void  MEXTI_voidSetCallBack(EXTI_LINE_t Copy_u8EXTILine,void (*Copy_Ptr)(void));


#endif
