/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 12 Aug 2023              */
/* Version : V01                     */
/*************************************/
#ifndef S2P_INTERFACE_H
#define S2P_INTERFACE_H

#define	   DS 	GPIOA,PIN0			//Data Serial
#define	 STCP 	GPIOA,PIN1			//Storge Clock
#define	 SHCP 	GPIOA,PIN2			//Shift Clock
		

void S2P_voidInit(void);
void S2P_voidByteOutput( u8 Copy_u8Data );
void S2P_voidHalfWordOutput( u16 Copy_u16Data );

#endif

