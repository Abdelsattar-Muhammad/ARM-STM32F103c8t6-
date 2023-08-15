/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 14 Aug 2023              */
/* Version : V01                     */
/*************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H



/***************   Functions definition    ******************/

void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveData_Synch(u8 Send_Data,u8* Receive_Data);
void MSPI1_voidSendReceiveData_Aynch(u8 Send_Data,u8* Receive_Data);

#endif
