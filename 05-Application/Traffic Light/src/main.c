/*
 * main.c
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٣
 *      Author: Abdelsattar
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "OS_interface.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LED_interface.h"
#include "SS_interface.h"
volatile u8 Counter,Seconds,Check;

// Function To Multiplex 2 Seven Segment At The Same Pins
void Multiplex_SS(void)
{
	MGPIO_voidSetPinValue(GPIOA,PIN8,HIGH);
	MGPIO_voidSetPinValue(GPIOA,PIN7,HIGH);
	Check++;
	if(Check==1)
	{
		SS_voidWriteNumber(Seconds%10);
		MGPIO_voidSetPinValue(GPIOA,PIN7,LOW);

	}
	else if(Check==2)
	{
		SS_voidWriteNumber(Seconds/10);
		MGPIO_voidSetPinValue(GPIOA,PIN8,LOW);
		Check=0;
	}

}

void Traffic_Light(void)
{
	switch(Counter)
	{
		case 0 :
		Seconds=0;
		// Turn On Red LEd
		LED_TurnOn(GPIOA,PIN11);
		break;

		case 30:
		Seconds=0;
		// Turn Off Red LEd
		LED_TurnOff(GPIOA,PIN11);
		// Turn On Yellow LEd
		LED_TurnOn(GPIOA,PIN10);
		break;

		case 50 :
		Seconds=0;
		// Turn Off Yellow LEd
		LED_TurnOff(GPIOA,PIN10);
		// Turn On Green LEd
		LED_TurnOn(GPIOA,PIN9);
		break;

		case 80:
		Seconds=0;
		Counter=0;
		// Turn Off Green LEd
		LED_TurnOff(GPIOA,PIN9);
		// Turn On Red LEd
		LED_TurnOn(GPIOA,PIN11);
		break;
	}
	Counter++;
	Seconds++;

}
void main(void)
{
	// initialize Clock System as HSE
	MRCC_voidInitSysClock();

	// Enable GPIOA & GPIOB from Rcc
	MRCC_voidEnableClock(RCC_APB2,APB2_GPIOA_EN);

	//Initialize Seven Segment
	SS_voidInit();

	//initialize Traffic LEDs
	LED_Init(GPIOA,PIN9);  //Green LED
	LED_Init(GPIOA,PIN10); //Yellow LED
	LED_Init(GPIOA,PIN11); //Red LED

	//initialize Control Pins OF Seven Segment As Output
	MGPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN8,OUTPUT_SPEED_2MHZ_PP);

	// Selected Tasks by Scheduler
	OS_voidCreateTask(0,10,Multiplex_SS,0);
	OS_voidCreateTask(1,1000,Traffic_Light,1);
	OS_voidStart();

	while(1)
	{


	}


}


