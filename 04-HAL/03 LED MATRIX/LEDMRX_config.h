/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 5 Aug 2023              */
/* Version : V01                     */
/*************************************/
#ifndef LEDMRX_CONFIG_H
#define LEDMRX_CONFIG_H

/************** Definitions Of Pins***********************/
typedef struct{
		u8 Port;
		u8 Pin;
		
		}Rows_t,Cols_t;


Cols_t COLS[8]={{GPIOA,0},
				{GPIOA,1},
				{GPIOA,2},
				{GPIOA,3},
				{GPIOA,4},
				{GPIOA,5},
				{GPIOA,6},
				{GPIOA,7} 	};

Rows_t ROWS[8]={{GPIOB,0},
				{GPIOB,1},
				{GPIOB,5},
				{GPIOB,6},
				{GPIOB,7},
				{GPIOB,8},
				{GPIOB,9},
				{GPIOB,10} 	};

       
#endif
