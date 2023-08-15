/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 30 July 2023            */
/* Version : V01                     */
/*************************************/ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "LED_interface.h"

/* Initialition LED */
void LED_Init(PORT_t Copy_tPort,PINS_t Copy_tPin)
{
	
	MGPIO_voidSetPinDirection(Copy_tPort,Copy_tPin,OUTPUT_SPEED_2MHZ_PP);
	
}

/* Turn On LED */
void LED_TurnOn(PORT_t Copy_tPort,PINS_t Copy_tPin)
{
	
	MGPIO_voidSetPinValue(Copy_tPort,Copy_tPin,HIGH);
	
}	

/* Turn Off LED */
void LED_TurnOff(PORT_t Copy_tPort,PINS_t Copy_tPin)
{
	
	MGPIO_voidSetPinValue(Copy_tPort,Copy_tPin,LOW);
	
}	

/* Toggle  LED */
void LED_Toggle(PORT_t Copy_tPort,PINS_t Copy_tPin)
{
	 MGPIO_voidToggleValue(Copy_tPort,Copy_tPin);	
}
