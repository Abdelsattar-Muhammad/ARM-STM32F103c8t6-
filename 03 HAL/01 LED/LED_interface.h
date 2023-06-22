/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 30 MAY 2023             */
/* Version : V01                     */
/*************************************/ 

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

void LED_TurnOn(PORT_t Copy_u8Port,PINS_t Copy_u8Pin);
void LED_TurnOff(PORT_t Copy_u8Port,PINS_t Copy_u8Pin);
void LED_Init(PORT_t Copy_u8Port,PINS_t Copy_u8Pin);
void LED_Toggle(PORT_t Copy_u8Port,PINS_t Copy_u8Pin);
#endif