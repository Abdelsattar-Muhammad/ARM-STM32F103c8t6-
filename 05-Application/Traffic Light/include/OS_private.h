/************************************************/
/* Author  : Abdelsattar Muhammad    		   */
/* Date    : 23 June 2023              	      */
/* Version : V01                    	   	 */
/********************************************/

#ifndef OS_PRIVATE_H
#define OS_PRIVATE_H


#ifndef NULL_PTR
#define NULL_PTR ((void *)0)
#endif
typedef struct{	

	u16  Priodicity		;
	void (*FPtr)(void) 	;
	u16   FirstDelay	;
			  
			  }TCB;

/* Array Of Structure */
static TCB OS_Tasks[NUMBER_OF_TASKS] ;


static void Schedular(void)
{
	for(u8 i=0; i < NUMBER_OF_TASKS; i++)
	{
		if(OS_Tasks[i].FPtr != NULL_PTR)
		{
		
		if( OS_Tasks[i].FirstDelay==0  )
			{
				OS_Tasks[i].FirstDelay=OS_Tasks[i].Priodicity-1;
				OS_Tasks[i].FPtr();  
				
			}
			else
			{
				OS_Tasks[i].FirstDelay--;
			}
		
		}
		else
		{

		}
	}//end for

}//end Function	
	
#endif
