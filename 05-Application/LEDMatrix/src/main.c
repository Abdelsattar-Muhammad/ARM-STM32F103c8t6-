/*
 * main.c
 *
 *  Created on: ٠٦‏/٠٨‏/٢٠٢٣
 *      Author: Abdelsattar
 */

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"
#include "LEDMRX_interface.h"
#include "OS_interface.h"

u8 arr[]={0, 121, 73, 73, 79, 0, 126, 9, 9, 9, 126, 0, 127, 1, 7, 12, 7, 1, 127, 0, 0, 126, 9, 9, 9, 126, 0, 127, 64, 64, 64, 0, 127, 73, 73, 73, 0, 127, 8, 20, 34, 65, 0, 0, 0, 0, 0, 0};
u8 size=sizeof(arr)/sizeof(arr[0]);

void main(void)
{

	MRCC_voidInitSysClock();
	// Enable GPIOA & GPIOB from Rcc
	MRCC_voidEnableClock(RCC_APB2,APB2_GPIOB_EN);
	MRCC_voidEnableClock(RCC_APB2,APB2_GPIOA_EN);
	//initialize SysTick
	//MSTK_voidInit();
	HLEDMRX_voidInit();
	HLEDMRX_voidSetCallBack(arr,size);
	OS_voidCreateTask(0,5,HLEDMRX_voidEnable_Asynch,0);
	OS_voidCreateTask(1,500,Rotate_Statment_Lift,2);
	OS_voidStart();

	while(1)
	{

	}

}


