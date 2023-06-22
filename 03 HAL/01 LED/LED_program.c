/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 30 MAY 2023             */
/* Version : V01                     */
/*************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LED_interface.h"

/* Initialition LED */
void LED_Init(PORT_t Copy_u8Port,PINS_t Copy_u8Pin)
{
	
	MGPIO_voidSetPinDirection(Copy_u8Port,Copy_u8Pin,OUTPUT_SPEED_2MHZ_PP);
	
}

/* Turn On LED */
void LED_TurnOn(PORT_t Copy_u8Port,PINS_t Copy_u8Pin)
{
	
	MGPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,HIGH);
	
}	

/* Turn Off LED */
void LED_TurnOff(PORT_t Copy_u8Port,PINS_t Copy_u8Pin)
{
	
	MGPIO_voidSetPinValue(Copy_u8Port,Copy_u8Pin,LOW);
	
}	

/* Toggle  LED */
void LED_Toggle(PORT_t Copy_u8Port,PINS_t Copy_u8Pin)
{
	 MGPIO_voidToggleValue(Copy_u8Port,Copy_u8Pin);	
}
