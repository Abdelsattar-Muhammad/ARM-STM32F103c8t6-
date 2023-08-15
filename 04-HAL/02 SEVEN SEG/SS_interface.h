/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 30 Jul 2023             */
/* Version : V01                     */
/*************************************/

#ifndef SS_INTERFACE_H
#define SS_INTERFACE_H
/* Seven Segment Have 2 Types : Common Cathode and Common Anode 
	You Should Selected Type Of your Seven Segment */

#define COMMON_CATHODE

typedef struct {
		u8 Port;
		u8 Pin;
}SS_t;

static SS_t SS_PINS[7]={{GPIOA,0},//A
						{GPIOA,1},//B
						{GPIOA,2},//C
						{GPIOA,3},//D
						{GPIOA,4},//E
						{GPIOA,5},//F
						{GPIOA,6} //G
				};

void SS_voidInit(void);

void SS_voidWriteNumber(u8 Copy_u8Number);

#endif
