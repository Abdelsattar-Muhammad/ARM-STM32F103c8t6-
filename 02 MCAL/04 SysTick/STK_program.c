/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 7 JUNE 2023             */
/* Version : V01                     */
/*************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Callback Function Global variable (pointer to function)*/ 
 
 #define NULL 0
 
 static void (*STK_CallBack)(void)=NULL;

/* define variable for interval mode 		*/

 static u8 STK_u8ModeOfInterval=0;

/* Define Clock Source of SysTick */

void MSTK_voidInit(void)
{
	#if	  STK_SRC == STK_SRC_AHB_8
	STK->CTRL=0x00000000 ; //Disable STK & Disable STK interrupt & choice AHB/8
	#elif STK_SRC == STK_SRC_AHB 
	STK->CTRL=0x00000004 ;//Disable STK & Disable STK interrupt & choice AHB
	#endif

}

/*
	This is function Like delay function, That's Maked Processor Busy until SysTick Finish Count Given Ticks (Synch.) 
*/
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	STK->LOAD = Copy_u32Ticks;     	// Load Number Of Ticks
	SET_BIT(STK->CTRL,0);  			// Start Timer
	while(GET_BIT(STK->CTRL,16)==0);// wait till Count Flag ==1
	
	/*********** Stop Timer **********/
	CLR_BIT(STK->CTRL,0);  			
	STK->LOAD =0; 
	STK->VAL  =0;			
}

/*
	Enable SysTick To Count Given Ticks Single Time and Enable SysTick Interrupt Then Disabled After Finished (Asynch.)
*/

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks,void (*Copy_Ptr)(void))
{
	STK->LOAD = Copy_u32Ticks; 	    			// Load Number Of Ticks
	SET_BIT(STK->CTRL,0);			    	        // Start Timer
	STK_CallBack=Copy_Ptr;			     	    // Save Callback
	STK_u8ModeOfInterval=STK_SINGLE_INTERVAL;   // Set Mode as Single
	SET_BIT(STK->CTRL,1);  				       // Enable SysTick Interrupt	
}
/*
	Enable SysTick To Count Given Ticks every Periodic Time and Enable SysTick Interrupt Then Clear Flag To interrupt again(Asynch.)
*/
void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks,void (*Copy_Ptr)(void))
{
	
	STK->LOAD = Copy_u32Ticks; 						// Load Number Of Ticks
	SET_BIT(STK->CTRL,0);					  			// Start Timer
	STK_CallBack=Copy_Ptr;							// Save Callback
	STK_u8ModeOfInterval=STK_PERIOD_INTERVAL;		// Set Mode of Single 
	SET_BIT(STK->CTRL,1);  							// Enable SysTick Interrupt	
}

/*
	Stop Interval 
*/
void MSTK_voidStopTimer(void)
{
	/* Disable STk Interrupt */
	CLR_BIT(STK->CTRL, 1);
	/*********** Stop STK Interval **********/
	CLR_BIT(STK->CTRL,0);  			
	STK->LOAD =0; 
	STK->VAL  =0;	
}
/* 
Function OF Get Elaped Time
*/
/* Return the number of thicks that done (load - val) */
u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime=(STK->LOAD) - (STK->VAL);
	return Local_u32ElapsedTime;
	
}
/*
Function OF Get Remaining Time 
*/

/* Return the number of thicks that will count (val) */
u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32ElapsedTime=(STK->VAL);
	return Local_u32ElapsedTime;
	
}
/*
Function OF STK Interrupt
*/


void SysTick_Handler(void)
{
	

	if(STK_u8ModeOfInterval == STK_SINGLE_INTERVAL )
	{
		STK_CallBack();
		MSTK_voidStopTimer();
		
	}
	else
	{
		STK_CallBack();
		/* Read Flag Bit To Clear Flag */
		u32 Local_u32Flag = GET_BIT(STK->CTRL,16);
	}
	
}
