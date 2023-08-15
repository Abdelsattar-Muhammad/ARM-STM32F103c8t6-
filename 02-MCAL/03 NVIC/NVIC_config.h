/*************************************/
/* Author  : Abdelsattar Muhammad    */
/* Date    : 1 Aug 2023              */
/* Version : V02                     */
/*************************************/
#ifndef NVIC_CONFIG_H
#define NVIC_CONFIG_H 
/* 
Options for NVIC Priority Mode :
	    NVIC_GROUP_4_SUB_0		// 4 bit to select Group(16 Group) & 0 bit to select Sub-Group (0 Sub)
		NVIC_GROUP_3_SUB_1   	// 3 bit to select Group( 8 Group) & 1 bit to select Sub-Group (2 Sub)
		NVIC_GROUP_2_SUB_2	 	// 2 bit to select Group( 4 Group) & 2 bit to select Sub-Group (4 Sub)
		NVIC_GROUP_1_SUB_3		// 1 bit to select Group( 2 Group) & 3 bit to select Sub-Group (8 Sub)
		NVIC_GROUP_0_SUB_4		// 0 bit to select Group( 0 Group) & 4 bit to select Sub-Group (16 Sub)
*/



#define NVIC_PRIORITY_MODE NVIC_GROUP_2_SUB_2

#endif
