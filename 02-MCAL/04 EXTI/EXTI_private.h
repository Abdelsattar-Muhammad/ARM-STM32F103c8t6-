/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 2 Aug 2023              */
/* Version : V01                     */
/*************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


/************************** REGISTER Definition *****************************/
typedef struct
{
	volatile u32 IMR ;
	volatile u32 EMR ;
	volatile u32 RTSR ;
	volatile u32 FTSR ;
	volatile u32 SWIER ;
	volatile u32 PR ;
		
}EXTI_t;

/************************ Base ADDRESS ***************************************/

#define EXTI_BASE_ADDRESS 0x40010400 

#define EXTI ((volatile EXTI_t *) EXTI_BASE_ADDRESS)


#endif
