/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 17 June 2023             */
/* Version : V02                     */
/*************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H 

 
/**********************  	REGISTER Definition		 ***********************/

typedef struct{
	
	volatile u32 ISER[2];       	//Interrupt set-enable registers from 0:31 & from 32 :59
	volatile u32 RESERVED0[30];		//Reserved Location
	volatile u32 ICER[2];			//Interrupt clear-enable registers from 0:31 & from 32 :59
	volatile u32 RESERVED1[30];		//Reserved Location
	volatile u32 ISPR[2];			//Interrupt set-pending registers from 0:31	& from 32 :59
	volatile u32 RESERVED2[30];		//Reserved Location
	volatile u32 ICPR[2];			//Interrupt clear-pending registers from 0:31 & from 32 :59
	volatile u32 RESERVED3[30];		//Reserved Location
	volatile u32 IABR[2]; 			//Interrupt active bit registers from 0:31	& from 32 :59
	volatile u32 RESERVED4[62];		//Reserved Location
	volatile u8  IPR[60];			//Interrupt priority registers
	volatile u32 RESERVED5[698];	//Reserved Location
	volatile u32 STIR ;				//Software trigger interrupt register

}NVIC_t;



/*************************  Group Priority Definition ***********************/


#define	    NVIC_GROUP_4_SUB_0		0x05FA0300 // 4 bit to select Group 0 bit to select Sub-Group
#define		NVIC_GROUP_3_SUB_1		0x05FA0400 // 3 bit to select Group 1 bit to select Sub-Group
#define		NVIC_GROUP_2_SUB_2		0x05FA0500 // 2 bit to select Group 2 bit to select Sub-Group
#define		NVIC_GROUP_1_SUB_3		0x05FA0600 // 1 bit to select Group 3 bit to select Sub-Group
#define		NVIC_GROUP_0_SUB_4		0x05FA0700 // 0 bit to select Group 4 bit to select Sub-Group


	
/************************  BASE ADDRESS Definition ***********************/

#define		 NVIC_BASE_ADDRESS 0xE000E100

#define		 NVIC 	(( volatile NVIC_t* ) NVIC_BASE_ADDRESS )


#define 	SCB_AIRCR 	*((volatile  u32*) 0xE000ED0C )

#endif
  
