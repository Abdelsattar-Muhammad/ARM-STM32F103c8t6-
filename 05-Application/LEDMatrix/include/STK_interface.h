/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 3 Aug 2023              */
/* Version : V01                     */
/*************************************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/*********************** Function Definitions *****************************/

/*Apply Clock Choice From Configuration File
  Disable SysTick Iterrupt
  Disable SysTick
*/
void MSTK_voidInit(void);

/*
	This is function Like delay function, That's Maked Processor Busy Until SysTick Finished from Counting (Synch.) 
*/
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

/*
	Enable SysTick To Counting Given Ticks Single Time and Fire Interrupt (Asynch.)
*/

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks,void (*Copy_FPtr)(void));

/*
	Enable SysTick To Count Given Ticks and Make Interrupt Periodic (Asynch.)
*/

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks,void (*Copy_FPtr)(void));
/*
	Function of Stop interval
*/
void MSTK_voidStopSysTick(void);

/*
 Function OF Get Elaped Time
*/

u32 MSTK_u32GetElapsedTime(void);

/*
 Function OF Get Remaining Time  
*/

u32 MSTK_u32GetRemainingTime(void);

#endif
