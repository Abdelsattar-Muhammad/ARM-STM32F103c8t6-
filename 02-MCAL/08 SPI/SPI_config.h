/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 14 Aug 2023              */
/* Version : V01                     */
/*************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

typedef enum{
		fPCLK_2  ,
		fPCLK_4  ,
		fPCLK_8  ,
		fPCLK_16 ,
		fPCLK_32 ,
		fPCLK_64 ,
		fPCLK_128,
		fPCLK_256
			};	

/* Select BAUD RATE From above Choices*/

#define BAUD_RATE fPCLK_4
typedef enum{
		SLAVE=0,
		MASTER	,
		
			};

/* Select MCU States From above Choices*/
#define MCU_STATE		  MASTER	




#endif