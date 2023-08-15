/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 6 Aug 2023              */
/* Version : V01                     */
/*************************************/
#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H
typedef enum{
	
				ON_OFF=69,
				MOOD=70,
				MUTE=71,
				ZERO=22,	
				ONE=12,
				TWO=24,
				THREE=94,
				FOUR=8,
				FIVE=28,
				SIX=90,
				SEVEN=66,
				EIGHT=82,
				NINE=74,
				VOL_UP=9,
				VOL_DWON=21,
				
				}IR_PINS;
u8   IR_u8ReadReceivedData(void);
void IR_voidSetCallBack(void (*Copy_FPtr)(void));
void IR_voidDataReceived(void);
void IR_voidGetFrame(void);

#endif

