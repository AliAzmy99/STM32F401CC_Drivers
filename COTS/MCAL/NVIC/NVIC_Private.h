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
#define G16_SG01	(0u)		/*16 Group(s) and 01 Subgroup(s) in each*/
#define G08_SG02	(1u)		/*08 Group(s) and 02 Subgroup(s) in each*/
#define G04_SG04	(2u)		/*04 Group(s) and 04 Subgroup(s) in each*/
#define G02_SG08	(3u)		/*02 Group(s) and 08 Subgroup(s) in each*/
#define G01_SG16	(4u)		/*01 Group(s) and 16 Subgroup(s) in each*/

	/*Registers*/
		/*First Addresses*/
#define NVIC_ISER_FIRST_ADDRESS		((volatile u32*)0xE000EF00)
#define NVIC_ICER_FIRST_ADDRESS		((volatile u32*)0xE000EF80)
#define NVIC_ISPR_FIRST_ADDRESS		((volatile u32*)0xE000F000)
#define NVIC_ICPR_FIRST_ADDRESS		((volatile u32*)0xE000F080)
#define NVIC_IABR_FIRST_ADDRESS		((volatile u32*)0xE000F100)
#define NVIC_IPR_FIRST_ADDRESS		((volatile u32*)0xE000F200)
#define NVIC_STIR_FIRST_ADDRESS		((volatile u32*)0xE000FC00)

	/*SCB*/
		/*Registers*/
#define SCB_AIRCR				(*(volatile u32*)0xE000ED0C)
		/*Bits*/
			/*AIRCR*/
#define SCB_AIRCR_PRIGROUP		(8u)
		/*Keys*/
#define VECTKEY					(0x5FA0000)
/*__________________________________________________________________________________________________________________________________________*/


#endif /*NVIC_PRIVATE_H*/
