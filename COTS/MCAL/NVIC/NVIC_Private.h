/************************************************************************/
/* SWC  	    : NVIC Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for Nested Vectored Interrupt Controller			*/
/************************************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*Private Macros*/
	/*NVIC_CLK_SRC Options*/


	/*Registers, NVIC First Address: 0xE000E010*/
#define NVIC_CTRL 			(*((volatile u32*)0xE000E010))


    /*Bits*/
        /*NVIC_CTRL*/

/*__________________________________________________________________________________________________________________________________________*/


/*Private Global Variables Definitions*/

/*__________________________________________________________________________________________________________________________________________*/


#endif /*NVIC_PRIVATE_H*/
