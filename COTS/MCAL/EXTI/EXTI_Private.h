/************************************************************************/
/* SWC			: EXTI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for External Interrupts/Events Controller			*/
/************************************************************************/


#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


/*Private Macros*/
	/*Registers, EXTI First Address: 0x40013C00*/
#define EXTI_IMR		(*((volatile u32*)0x40013C00))
#define EXTI_EMR		(*((volatile u32*)0x40013C04))
#define EXTI_RTSR		(*((volatile u32*)0x40013C08))
#define EXTI_FTSR		(*((volatile u32*)0x40013C0C))
#define EXTI_SWIER		(*((volatile u32*)0x40013C10))
#define EXTI_PR			(*((volatile u32*)0x40013C14))

	/*Bits*/
		/*EXTI_PR*/
#define EXTI_PR_PR0		(0u)
#define EXTI_PR_PR1		(1u)
#define EXTI_PR_PR2		(2u)
#define EXTI_PR_PR3		(3u)
#define EXTI_PR_PR4		(4u)
#define EXTI_PR_PR5		(5u)
#define EXTI_PR_PR6		(6u)
#define EXTI_PR_PR7		(7u)
#define EXTI_PR_PR8		(8u)
#define EXTI_PR_PR9		(9u)
#define EXTI_PR_PR10	(10u)
#define EXTI_PR_PR11	(11u)
#define EXTI_PR_PR12	(12u)
#define EXTI_PR_PR13	(13u)
#define EXTI_PR_PR14	(14u)
#define EXTI_PR_PR15	(15u)
/*__________________________________________________________________________________________________________________________________________*/


/*Private Global Variables Definitions*/
static void (* Globptr_vdCallbackFunctions[16])(void) = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};		/*The callback functions called by EXTI's ISRs*/
static u8 Glob_u8LinePorts[EXTI_NOT_A_LINE] = {LINE_0_PORT, LINE_1_PORT, LINE_2_PORT, LINE_3_PORT, LINE_4_PORT, LINE_5_PORT, LINE_6_PORT, LINE_7_PORT, LINE_8_PORT, LINE_9_PORT, LINE_10_PORT, LINE_11_PORT, LINE_12_PORT, LINE_13_PORT, LINE_14_PORT, LINE_15_PORT};	/*The ports of the EXTI lines*/
/*__________________________________________________________________________________________________________________________________________*/


#endif /*EXTI_PRIVATE_H*/
