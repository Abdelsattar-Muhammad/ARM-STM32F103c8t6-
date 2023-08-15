/************************************************/
/* Author  : Abdelsattar Muhammad    		   */
/* Date    : 7 Aug 2023              	      */
/* Version : V01                    	   	 */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"

#include "OS_interface.h"
#include "OS_config.h"
#include "OS_private.h"




void OS_voidCreateTask( u8  Copy_u8Priority, //Priority must be different
					    u16 Copy_u16Priodicity,// every mSec
					    void (*Copy_FPtr)(void),// function of Task
					    u16 Copy_u8FirstDelay ) //First Delay by mSec
{	
	
	OS_Tasks[Copy_u8Priority].Priodicity = Copy_u16Priodicity;
	OS_Tasks[Copy_u8Priority].FPtr 		 = Copy_FPtr;
	OS_Tasks[Copy_u8Priority].FirstDelay =  Copy_u8FirstDelay ;
}

void OS_voidTaskDelete(u8 Copy_u8Priority)
{
	OS_Tasks[Copy_u8Priority].FPtr = NULL_PTR;
	
}

void OS_voidStart(void)
{
	/* Initialization SysTick*/ 
	MSTK_voidInit();
	/* Set Tick Time by mSec */ 
	MSTK_voidSetPeriodicInterval(TICK_TIME,&Schedular);
}
