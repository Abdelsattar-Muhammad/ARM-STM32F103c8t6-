/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 14 Aug 2023              */
/* Version : V01                     */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"


void MUSART1_voidInit(void)
{
		/*	Set baud rate */
		
		#if BAUD_RATE == 9600
		USART1 -> BRR = 0x341;
		#elif BAUD_RATE == 112500
		USART1 -> BRR = 0x047;
		#endif
		
		
	SET_BIT((USART1-> CR[0]), 3);			/* Enabling Transmitter */
	SET_BIT((USART1-> CR[0]), 2);			/* Enabling Receiver */
	SET_BIT((USART1-> CR[0]), 13);			/* Enabling USART */
	
	USART1 -> SR = 0;						/* Clearing status register */
	
	
}

void MUSART1_voidTransmit(u8 Data_Trans[])
{
	u8 i=0;
	while(Data_Trans[i] != '\0')
	{
		UART-DR=Data_Trans[i];
		while(GET_BIT(UART->SR,6)==0);
		i++;
	}
	

}

void MUSART1_u8Receive(u8 *Data_Received)
{
	while(GET_BIT(UART->SR,5)==0);
	*Data_Received=UART-DR;
	
	
}
