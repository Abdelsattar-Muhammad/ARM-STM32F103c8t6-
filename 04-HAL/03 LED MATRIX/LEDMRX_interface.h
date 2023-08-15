/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 5 Aug 2023              */
/* Version : V01                     */
/*************************************/
#ifndef LEDMRX_INTERFACE_H
#define LEDMRX_INTERFACE_H

void HLEDMRX_voidInit(void);
void HLEDMRX_voidSetCallBack(u8 *Copy_u8Data,u8 SizeOfArray);
void HLEDMRX_voidEnable_Synch(void);
// it's Asynchronous function should excute each 2000 uSec by SysTick
void HLEDMRX_voidEnable_Asynch(void);
void Rotate_Statment(void);
 
#endif
