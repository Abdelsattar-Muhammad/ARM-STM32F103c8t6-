/*************************************/
/* Author  : Abdelsattar Muhammad  	*/
/* Date    : 5 Aug 2023         	 */
/* Version : V01               		  */
/*************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "STK_interface.h"


#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

static u8 (*Ptr_Data)=0;
static volatile u8 size,x;
void HLEDMRX_voidInit(void)
{
	/**************** Initializtion Rows and Colums *********************/
		for(u8 i=0;i<8;i++)
		{		
		MGPIO_voidSetPinDirection(ROWS[i].Port , ROWS[i].Pin , OUTPUT_SPEED_2MHZ_PP);
		MGPIO_voidSetPinDirection(COLS[i].Port , COLS[i].Pin , OUTPUT_SPEED_2MHZ_PP);
		/** Disable All Colums by Logical High**/
		MGPIO_voidSetPinValue(COLS[i].Port , COLS[i].Pin , HIGH);
		}
}

static void Set_RowsValues(u8 Copy_u8Data)
{		
		u8 Bit_State;
		for(u8 i=0 ; i<8 ;i++)
		{
			Bit_State=((Copy_u8Data>>i)&1);
			
			MGPIO_voidSetPinValue(ROWS[i].Port , ROWS[i].Pin , Bit_State);
		}
	
}


void HLEDMRX_voidSetCallBack(u8 *ArrayOfData,u8 SizeOfArray)
{
	Ptr_Data=ArrayOfData;
	size=SizeOfArray;
}
// Synchronous Function
void HLEDMRX_voidEnable_Synch(void)
{

	/* Select Controler Colums */
		for(u8 i=0;i<8;i++)
			{	
			Set_RowsValues(Ptr_Data[i]);
			// Enable Colum Control by logical Low
			MGPIO_voidSetPinValue(COLS[i].Port , COLS[i].Pin , LOW); 
			MSTK_voidSetBusyWait(2500);
			// Disable Colum Control by logical High
			MGPIO_voidSetPinValue(COLS[i].Port , COLS[i].Pin , HIGH);
			}

}


void HLEDMRX_voidEnable_Asynch(void)
{

	MGPIO_voidSetLowNibbleValue(GPIOA,0xff);
	Set_RowsValues(Ptr_Data[x]);
	MGPIO_voidSetLowNibbleValue(GPIOA,~(1<<x));

	if(x++==7)
	{
		x=0;
	}

}
void Rotate_Statment_Lift(void)
{

	u8 temp=Ptr_Data[0],i;
	for(i=0 ; i<size ; i++)
	{
		Ptr_Data[i]=Ptr_Data[i+1] ;
	}
	Ptr_Data[i]= temp ;
	

	
}
void Rotate_Statment_Right(void)
{
	 s8 i;
	 u8  temp=Ptr_Data[size-1];
	for(i=size-1 ; i>=0 ; i--)
	{
		Ptr_Data[i]=Ptr_Data[i-1] ;
	}
	Ptr_Data[0]= temp ;



}
