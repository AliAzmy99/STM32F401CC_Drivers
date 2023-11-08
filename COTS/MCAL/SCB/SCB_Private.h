/************************************************************************/
/* SWC  	    : SCB Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Control Block							*/
/************************************************************************/


#ifndef SCB_PRIVATE_H
#define SCB_PRIVATE_H


/*Private Macros*/
	/*Registers*/
#define SCB_AIRCR				(*(volatile u32*)0xE000ED0C)

	/*Bits*/
		/*AIRCR*/
#define SCB_AIRCR_PRIGROUP		(8u)
#define SCB_AIRCR_VECTKEY		(16u)

	/*Keys*/
#define VECTKEY					(0x5FA)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SCB_PRIVATE_H*/
