/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 14 Aug 2023              */
/* Version : V01                     */
/*************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

/***************   Function definition    ******************/

void MUSART1_voidInit(void);

void MUSART1_voidTransmit(u8 Data_Trans[]);

void MUSART1_u8Receive(u8 *Data_Received);

#endif
