/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 7 June 2023             */
/* Version : V01                     */
/*************************************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/******************   STK Clock Source Definition   ******************/

#define STK_SRC_AHB_8				0
#define STK_SRC_AHB					1

/******************   STK interval mode Definition   ******************/

#define STK_SINGLE_INTERVAL			0
#define STK_PERIOD_INTERVAL			1


/*********************** Function Definitions *****************************/

/*Apply Clock Choice From Configuration File
  Disable SysTick Iterrupt
  Disable SysTick
*/
void MSTK_voidInit(void);

/*
	This is function Like delay function, That's Maked Processor Busy Until SysTick Finish Count (Synch.) 
*/
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

/*
	Enable SysTick To Count Given Ticks Single Time and Make Interrupt Then Disabled (Asynch.)
*/

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks,void (*Copy_Ptr)(void));

/*
	Enable SysTick To Count Given Ticks and Make Interrupt Periodic (Asynch.)
*/

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks,void (*Copy_Ptr)(void));
/*
	Function of Stop interval
*/
void MSTK_voidStopTimer(void);

/*
 Function OF Get Elaped Time
*/

u32 MSTK_u32GetElapsedTime(void);

/*
 Function OF Get Remaining Time  
*/

u32 MSTK_u32GetRemainingTime(void);

#endif
