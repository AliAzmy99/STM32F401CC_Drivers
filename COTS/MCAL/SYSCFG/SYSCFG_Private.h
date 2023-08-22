/************************************************************************/
/* SWC  	    : SYSCFG Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Configuration Controller				*/
/************************************************************************/


#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H


/*Private Macros*/
	/*Registers*/
#define SYSCFG_EXTICR1				(*(volatile u32*)0x40013808)
#define SYSCFG_EXTICR2				(*(volatile u32*)0x4001380C)
#define SYSCFG_EXTICR3				(*(volatile u32*)0x40013810)
#define SYSCFG_EXTICR4				(*(volatile u32*)0x40013814)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SYSCFG_PRIVATE_H*/
