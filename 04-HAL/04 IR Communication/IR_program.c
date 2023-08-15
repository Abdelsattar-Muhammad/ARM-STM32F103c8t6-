/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 6 Aug 2023              */
/* Version : V01                     */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"

#include "IR_interface.h"


static volatile u8  StartFlag=0;
static volatile u16  FrameData[50];
static volatile u8  u8Counter=0;
static volatile u8  IR_Data=0;

static  void ( *IR_CallBack )(void);

/** Set CallBack Funtion To Excuted when interrupt is Fired */
void IR_voidSetCallBack( void(*Copy_FPtr)(void))
{
	IR_CallBack = Copy_FPtr ;
}


/* To Get Frame From IR Receiver */
void IR_voidGetFrame(void)
{
	if(StartFlag == 0)
	{
		MSTK_voidStopSysTick();
		MSTK_voidSetSingleInterval(500000,IR_voidDataReceived);
		StartFlag=1;
		
	}
	else
	{
		FrameData[ u8Counter++ ]=MSTK_u32GetElapsedTime();
		MSTK_voidStopSysTick();
		MSTK_voidSetSingleInterval(500000,IR_voidDataReceived);
	}
	
}
 void IR_voidDataReceived(void)
{
	if(FrameData[0]>=10000 && FrameData[0]<=14000)
	{
	for(u8 i=0;i<8;i++)
	{
		if(FrameData[17+i]>=1000 && FrameData[17+i]<=1350)
		{
			CLR_BIT(IR_Data,i);
		}
		else if (FrameData[17+i]>=2000 && FrameData[17+i]<=2350)
		{
			SET_BIT(IR_Data,i);
		}
	
	}
	
		StartFlag=0;
		FrameData[0]=0;
		u8Counter=0;
		IR_CallBack();
	
	}
	else
	{
		/*Error*/
	}
}



u8   IR_u8ReadReceivedData(void)
{
	return IR_Data;
}