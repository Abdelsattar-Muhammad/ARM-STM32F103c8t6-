/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 30 July 2023            */
/* Version : V01                     */
/*************************************/ 

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

void LED_TurnOn(PORT_t Copy_tPort,PINS_t Copy_tPin);
void LED_TurnOff(PORT_t Copy_tPort,PINS_t Copy_tPin);
void LED_Init(PORT_t Copy_tPort,PINS_t Copy_tPin);
void LED_Toggle(PORT_t Copy_tPort,PINS_t Copy_tPin);
#endif