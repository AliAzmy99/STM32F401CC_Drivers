/************************************************************************/
/* SWC  	    : NVIC Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for Nested Vectored Interrupt Controller			*/
/************************************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*Private Macros*/
	/*Group and Subgroup Options*/
#define G16_SG01		SCB_G16_SG01		/*16 Group(s) and 01 Subgroup(s) in each*/
#define G08_SG02		SCB_G08_SG02		/*08 Group(s) and 02 Subgroup(s) in each*/
#define G04_SG04		SCB_G04_SG04		/*04 Group(s) and 04 Subgroup(s) in each*/
#define G02_SG08		SCB_G02_SG08		/*02 Group(s) and 08 Subgroup(s) in each*/
#define G01_SG16		SCB_G01_SG16		/*01 Group(s) and 16 Subgroup(s) in each*/

	/*Registers*/
		/*First Addresses*/
#define NVIC_ISER_FIRST_ADDRESS		((volatile u32*)0xE000E100)
#define NVIC_ICER_FIRST_ADDRESS		((volatile u32*)0xE000E180)
#define NVIC_ISPR_FIRST_ADDRESS		((volatile u32*)0xE000E200)
#define NVIC_ICPR_FIRST_ADDRESS		((volatile u32*)0xE000E280)
#define NVIC_IABR_FIRST_ADDRESS		((volatile u32*)0xE000E300)
#define NVIC_IPR_FIRST_ADDRESS		((volatile u32*)0xE000E400)
#define NVIC_STIR_FIRST_ADDRESS		((volatile u32*)0xE000EF00)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*NVIC_PRIVATE_H*/
