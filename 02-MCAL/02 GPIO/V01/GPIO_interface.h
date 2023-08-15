/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 29 MAY 2023             */
/* Version : V01                     */
/*************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_HIGH  1
#define GPIO_LOW   0

/***************   GPIO(PORT) definition  *******************/
#define GPIOA 0
#define GPIOB 1
#define GPIOC 2

/***************   	PIN definition  	 *******************/
#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7
#define PIN8  8
#define PIN9  9
#define PIN10 10
#define PIN11 11
#define PIN12 12
#define PIN13 13
#define PIN14 14
#define PIN15 15

/***************   	Modes definition  	 *******************/

/***************   INPUT Mode definition   ******************/

#define INPUT_ANALOG 				0b0000
#define INPUT_FLOATING 				0b0100
#define INPUT_PULL_UP 				0b1000
#define INPUT_PULL_DOWN			 	0b1000

/***************   OUTPUT Mode definition   ******************/

//FOR 2 MHZ
#define OUTPUT_SPEED_2MHZ_PP  		0b0010 //PP-> Push Pull
#define OUTPUT_SPEED_2MHZ_OD 		0b0110 //OD->Open Drain
#define OUTPUT_SPEED_2MHZ_AF_PP 	0b1010 //AF->Alternate Function
#define OUTPUT_SPEED_2MHZ_AF_OD 	0b1110

//FOR 10 MHZ
#define OUTPUT_SPEED_10MHZ_PP	 	0b0001
#define OUTPUT_SPEED_10MHZ_OD 		0b0101
#define OUTPUT_SPEED_10MHZ_AF_PP 	0b1001
#define OUTPUT_SPEED_10MHZ_AF_OD 	0b1101

//FOR 50 MHZ
#define OUTPUT_SPEED_50MHZ_PP 		0b0011
#define OUTPUT_SPEED_50MHZ_OD 		0b0111
#define OUTPUT_SPEED_50MHZ_AF_PP	0b1011
#define OUTPUT_SPEED_50MHZ_AF_OD 	0b1111

/***************   Function definition   ******************/

void MGPIO_voidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);

void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);

void MGPIO_voidSetLowNibbleValue(u8 Copy_u8Port,u8 Copy_u8Value);

u8 	 MGPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin);

void MGPIO_voidToggleValue(u8 Copy_u8Port,u8 Copy_u8Pin);
/* This Function Locked Pin Direction Mode */

void MGPIO_voidLockPin(u8 Copy_u8Port,u8 Copy_u8Pin);


#endif