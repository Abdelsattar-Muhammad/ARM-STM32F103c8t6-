/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 12 Aug 2023             */
/* Version : V01                     */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "S2P_interface.h"

void S2P_voidInit(void)
{
		MGPIO_voidSetPinDirection(DS,OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(STCP,OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(SHCP,OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinValue( SHCP,LOW ) ;
		MGPIO_voidSetPinValue( STCP,LOW ) ;
}

void S2P_voidByteOutput( u8 Copy_u8Data )
{
	u8 i=8;
	for(s8 count=7;count>=0;count--)
	{
		MGPIO_voidSetPinValue( DS,GET_BIT(Copy_u8Data,count) ) ;
		MGPIO_voidSetPinValue( SHCP,HIGH ) ;
		while(i--);
		MGPIO_voidSetPinValue( SHCP,LOW ) ;
	}
	i=8;
	MGPIO_voidSetPinValue( STCP,HIGH ) ;
	while(i--);
	MGPIO_voidSetPinValue( STCP,LOW ) ;
}
void S2P_voidHalfWordOutput( u16 Copy_u16Data )
{
	u8 i=8;
	for(s8 count=15;count>=0;count--)
	{
		MGPIO_voidSetPinValue( DS,GET_BIT(Copy_u16Data,count) ) ;
		MGPIO_voidSetPinValue( SHCP,HIGH ) ;
		while(i--);
		MGPIO_voidSetPinValue( SHCP,LOW ) ;
	}
	i=8;
	MGPIO_voidSetPinValue( STCP,HIGH ) ;
	while(i--);
	MGPIO_voidSetPinValue( STCP,LOW ) ;
}
