/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 14 Aug 2023              */
/* Version : V01                     */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

static volatile void (*CallBack)(u8 Date);

void MSPI1_voidInit(void)
{
	
	SPI->SPI_CR1=(u16)((1<<9)|(BAUD_RATE<<3)|(MCU_STATE<<2)|(1<<0)|(1<<6));
	
}
void MSPI1_voidSendReceiveData_Synch(u8 Send_Data,u8* Receive_Data)
{
	SPI->DR=Send_Data;
	while(GET_BIT(SPI->SR,7)==1);
	*Receive_Data=SPI-DR;
}
void MSPI1_voidSendReceiveData_Aynch(u8 Send_Data,void (*Fptr)(u8 Date))
{
	//Enable interrupt for Receive Data
	SET_BIT(SPI_CR2,6);
	//set Call Back Function 
	CallBack=Fptr;
	//Send Data
	SPI->DR=Send_Data;
	
}	

SPI1_Handler(void)
{
	CallBack(SPI->DR);
	//Clear Flags
	SPI->SR=0;
}