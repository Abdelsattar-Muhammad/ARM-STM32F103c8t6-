/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 30 Jul 2023             */
/* Version : V01                     */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SS_interface.h"
/*
	As Output if SS is Common Cathode
	or input  if  SS is Common Anode
*/ 
	
void SS_voidInit(void)
{
	for(u8 i=0;i<7;i++)
	{
		MGPIO_voidSetPinDirection(SS_PINS[i].Port,SS_PINS[i].Pin,OUTPUT_SPEED_2MHZ_PP);
	}

}

void SS_voidWriteNumber(u8 Copy_u8Number)
{
	#if defined COMMON_CATHODE
	u8 arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	for(u8 i=0;i<7;i++)
		{
		MGPIO_voidSetPinValue(SS_PINS[i].Port,SS_PINS[i].Pin,GET_BIT(arr[Copy_u8Number],i));
		}


	#elif defined COMMON_ANODE
	u8 arr[10]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x07,~0x7f,~0x6f};
	for(u8 i=0;i<7;i++)
		{
		MGPIO_voidSetPinValue(SS_PINS[i].Port,SS_PINS[i].Pin,GET_BIT(arr[Copy_u8Number],i));
		}
	#endif
}
