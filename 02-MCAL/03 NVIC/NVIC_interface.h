/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 1 Aug 2023              */
/* Version : V02                     */
/*************************************/


#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H 

/******************* Interrupt Number Definition =  Position In Vector Table ***********************/
typedef enum
{
/**************************  STM32 specific Interrupt Numbers ****************************************/
  WWDG_IRQ                   = 0,      /* Window WatchDog Interrupt                                 */
  PVD_IRQ                    = 1,      /* PVD through EXTI Line detection Interrupt                 */
  TAMPER_IRQ                 = 2,      /* Tamper Interrupt                                          */
  RTC_IRQ                    = 3,      /* RTC global Interrupt                                      */
  FLASH_IRQ                  = 4,      /* FLASH global Interrupt                                    */
  RCC_IRQ                    = 5,      /* RCC global Interrupt                                      */
  EXTI0_IRQ                  = 6,      /* EXTI Line0 Interrupt                                      */
  EXTI1_IRQ                  = 7,      /* EXTI Line1 Interrupt                                      */
  EXTI2_IRQ                  = 8,      /* EXTI Line2 Interrupt                                      */
  EXTI3_IRQ                  = 9,      /* EXTI Line3 Interrupt                                      */
  EXTI4_IRQ                  = 10,     /* EXTI Line4 Interrupt                                      */
  DMA1_Channel1_IRQ          = 11,     /* DMA1 Channel 1 global Interrupt                           */
  DMA1_Channel2_IRQ          = 12,     /* DMA1 Channel 2 global Interrupt                           */
  DMA1_Channel3_IRQ          = 13,     /* DMA1 Channel 3 global Interrupt                           */
  DMA1_Channel4_IRQ          = 14,     /* DMA1 Channel 4 global Interrupt                           */
  DMA1_Channel5_IRQ          = 15,     /* DMA1 Channel 5 global Interrupt                           */
  DMA1_Channel6_IRQ          = 16,     /* DMA1 Channel 6 global Interrupt                           */
  DMA1_Channel7_IRQ          = 17,     /* DMA1 Channel 7 global Interrupt                           */
  ADC1_2_IRQ                 = 18,     /* ADC1 and ADC2 global Interrupt                            */
  USB_HP_CAN_TX_IRQ          = 19,     /* USB Device High Priority or CAN1 TX Interrupts            */
  USB_LP_CAN_RX0_IRQ         = 20,     /* USB Device Low Priority or CAN1 RX0 Interrupts            */
  CAN_RX1_IRQ                = 21,     /* CAN1 RX1 Interrupt                                        */
  CAN_SCE_IRQ                = 22,     /* CAN1 SCE Interrupt                                        */
  EXTI9_5_IRQ                = 23,     /* External Line[9:5] Interrupts                             */
  TIM1_BRK_IRQ               = 24,     /* TIM1 Break Interrupt                                      */
  TIM1_UP_IRQ                = 25,     /* TIM1 Update Interrupt                                     */
  TIM1_TRG_COM_IRQ           = 26,     /* TIM1 Trigger and Commutation Interrupt                    */
  TIM1_CC_IRQ                = 27,     /* TIM1 Capture Compare Interrupt                            */
  TIM2_IRQ                   = 28,     /* TIM2 global Interrupt                                     */
  TIM3_IRQ                   = 29,     /* TIM3 global Interrupt                                     */
  TIM4_IRQ                   = 30,     /* TIM4 global Interrupt                                     */
  I2C1_EV_IRQ                = 31,     /* I2C1 Event Interrupt                                      */
  I2C1_ER_IRQ                = 32,     /* I2C1 Error Interrupt                                      */
  I2C2_EV_IRQ                = 33,     /* I2C2 Event Interrupt                                      */
  I2C2_ER_IRQ                = 34,     /* I2C2 Error Interrupt                                      */
  SPI1_IRQ                   = 35,     /* SPI1 global Interrupt                                     */
  SPI2_IRQ                   = 36,     /* SPI2 global Interrupt                                     */
  USART1_IRQ                 = 37,     /* USART1 global Interrupt                                   */
  USART2_IRQ                 = 38,     /* USART2 global Interrupt                                   */
  USART3_IRQ                 = 39,     /* USART3 global Interrupt                                   */
  EXTI15_10_IRQ              = 40,     /* External Line[15:10] Interrupts                           */
  RTC_Alarm_IRQ              = 41,     /* RTC Alarm through EXTI Line Interrupt                     */
  USBWakeUp_IRQ              = 42,     /* USB Device WakeUp from suspend through EXTI Line Interrupt*/ 
  TIM8_BRK_IRQ		  		 =	43,		/* TIM8 Break interrupt                   					 */
  TIM8_UP_IRQ                = 44,     /* TIM8 Update interrupt                  					 */
  TIM8_TRG_COM_IRQ           = 45,     /* TIM8 Trigger and Commutation interrupts					 */
  TIM8_CC_IRQ                = 46,     /* TIM8 Capture Compare interrupt         					 */        
  ADC3_IRQ  		         = 47,     /* ADC3 global interrupt                  					 */
  FSMC_IRQ 	                 = 48,     /* FSMC global interrupt                  					 */
  SDIO_IRQ 	                 = 49,     /* SDIO global interrupt                  					 */
  TIM5_IRQ                   = 50,     /* TIM5 global interrupt                  					 */
  SPI3_IRQ                   = 51,     /* SPI3 global interrupt                  					 */
  UART4_IRQ                  = 52,     /* UART4 global interrupt                 					 */
  UART5_IRQ 	             = 53,     /* UART5 global interrupt                 					 */
  TIM6_IRQ  		         = 54,     /* TIM6 global interrupt                  					 */
  TIM7_IRQ		             = 55,     /* TIM7 global interrupt                  					 */
  DMA2_Channel1_IRQ          = 56,     /* DMA2 Channel1 global interrupt         					 */
  DMA2_Channel2_IRQ	         = 57,     /* DMA2 Channel2 global interrupt         					 */
  DMA2_Channel3_IRQ          = 58,     /* DMA2 Channel3 global interrupt         					 */
  DMA2_Channel4_5_IRQ        = 59,     /* DMA2 Channel4 and DMA2 Channel5 global interrupts		 */

}IRQ_t;


/********************   Function definition    ******************/	
void MNVIC_voidEnableInterrupt(IRQ_t Copy_tIRQ);

void MNVIC_voidDisableInterrupt(IRQ_t Copy_tIRQ);

void MNVIC_voidSetPendingFlag(IRQ_t Copy_tIRQ);

void MNVIC_voidClearPendingFlag(IRQ_t Copy_tIRQ);

u8 	 MNVIC_u8ReadActiveBit(IRQ_t Copy_tIRQ);

void MNVIC_voidInitPriorityMode(void);

void MNVIC_voidSetInterruptPriority(IRQ_t Copy_tIRQ,u8 Copy_u8GroupPriority,u8 Copy_u8SubGroupPriority);

#endif
