/************************************************/
/* Author  : Abdelsattar Muhammad    		   */
/* Date    : 7 Aug 2023              	      */
/* Version : V01                    	   	 */
/********************************************/

#ifndef OS_INTERFACE_H
#define OS_INTERFACE_H


void OS_voidCreateTask( u8  Copy_u8Priority,   //Priority must be different
					    u16 Copy_u16Priodicity, // every mSec
					   void (*Copy_FPtr)(void),// function of Task
					   u16 Copy_u8FirstDelay   //First Delay by mSec	
					   );

void OS_voidTaskDelete(u8 Copy_u8Priority);
void OS_voidStart(void);







#endif
