/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 17 June 2023             */
/* Version : V01                     */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidEnableInterrupt(IRQ_t Copy_tIRQ)
{
	//NVIC->ISER[Copy_tIRQ/32] = 1 << ( Copy_tIRQ % 32 );
	
	if(Copy_tIRQ <=31)
	{ 
	NVIC->ISER[0] = 1 << Copy_tIRQ;
	}
	else if (Copy_tIRQ <=59)
	{
		Copy_tIRQ-= 32;
	NVIC->ISER[1] 	= 1 << Copy_tIRQ ;
	}
	else
	{
		/* Error */
	}
	 
}

void MNVIC_voidDisableInterrupt(IRQ_t Copy_tIRQ)
{
	if(Copy_tIRQ <=31)
	{ 
	NVIC->ICER[0] = 1 << Copy_tIRQ;
	}
	else if (Copy_tIRQ <=59)
	{
	Copy_tIRQ-= 32;
	NVIC->ICER[1] 	= 1 << Copy_tIRQ ;
	}
	else
	{
		/* Error */
	}
	 
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber <= 31)
	{ 
	NVIC->ISPR[0] = 1 << Copy_u8InterruptNumber;
	}
	else if (Copy_u8InterruptNumber <= 59)
	{
		Copy_u8InterruptNumber-= 32;
	NVIC->ISPR[1] 	= 1 << Copy_u8InterruptNumber ;
	}
	else
	{
		/* Error */
	}
	
	
	
}


void MNVIC_voidClearPendingFlag(IRQ_t Copy_tIRQ)
{
	if(Copy_tIRQ <= 31)
	{ 
	NVIC->ICPR[0] = 1 << Copy_tIRQ;
	}
	else if (Copy_tIRQ <=59)
	{
		Copy_tIRQ-= 32;
	NVIC->ICPR[1] 	= 1 << Copy_tIRQ ;
	}
	else
	{
		/* Error */
	}
	
	
	
}
u8 	 MNVIC_u8ReadActiveBit(IRQ_t Copy_tIRQ)
{
		u8 Return_Value=0;
		if(Copy_tIRQ <=31)
	{ 
		Return_Value=GET_BIT(NVIC->IABR[0],Copy_tIRQ);
	}
	else if (Copy_tIRQ <=59)
	{
		Copy_tIRQ-=32;
		Return_Value=GET_BIT(NVIC->IABR[1],Copy_tIRQ);
	}
	else
	{
		/* Error */
	}
	
	return Return_Value;
		
}

void MNVIC_voidInitPriorityMode(void)
{

	SCB_AIRCR = NVIC_PRIORITY_MODE;
}


void MNVIC_voidSetInterruptPriority(IRQ_t Copy_tIRQ,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority)
{		
	u8 Local_u8Priority=0;

	if(Copy_tIRQ<60)
	{
	#if NVIC_PRIORITY_MODE == NVIC_GROUP_4_SUB_0	
	Local_u8Priority=  Copy_u8GroupPriority ;
	#elif NVIC_PRIORITY_MODE == NVIC_GROUP_3_SUB_1
	 Local_u8Priority= (Copy_u8SubGroupPriority) | (Copy_u8GroupPriority<< 1 );
	#elif NVIC_PRIORITY_MODE == NVIC_GROUP_2_SUB_2
	 Local_u8Priority= (Copy_u8SubGroupPriority) | (Copy_u8GroupPriority<< 2 );
	#elif NVIC_PRIORITY_MODE == NVIC_GROUP_1_SUB_3
	 Local_u8Priority= (Copy_u8SubGroupPriority) | (Copy_u8GroupPriority<< 3 );
	#elif NVIC_PRIORITY_MODE == NVIC_GROUP_0_SUB_4
	 Local_u8Priority= (Copy_u8SubGroupPriority) ;
	#endif
	
	}
	else
	{
		//error
	}
	
	NVIC->IPR[Copy_tIRQ]= (Local_u8Priority << 4 );

	
	
}
