/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 13 Aug 2023              */
/* Version : V02                     */
/*	v02 add SPI Remap
/*************************************/

#ifndef AFIO_INTERFACE_H
#define AFIO_INTERFACE_H

/***************   Function definition    ******************/

void AFIO_voidSetEXTIConfiguration(EXTI_LINE_t Copy_tEXTILine,PORT_t Copy_tPortMap);

/* Remap SPI1 On Port A or Port B */
void AFIO_voidSPI1_REMAP(PORT_t Copy_tPortMap);


#endif
