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
static void (* Globptr_vdCallbackFunction_EXTI0)(void) = NULL;			/*The callback function called by EXTI0's ISR*/
static void (* Globptr_vdCallbackFunction_EXTI1)(void) = NULL;			/*The callback function called by EXTI1's ISR*/
static void (* Globptr_vdCallbackFunction_EXTI2)(void) = NULL;			/*The callback function called by EXTI2's ISR*/
static void (* Globptr_vdCallbackFunction_EXTI3)(void) = NULL;			/*The callback function called by EXTI3's ISR*/
static void (* Globptr_vdCallbackFunction_EXTI4)(void) = NULL;			/*The callback function called by EXTI4's ISR*/
static void (* Globptr_vdCallbackFunction_EXTI9_5)(void) = NULL;		/*The callback function called by EXTI5 to EXTI9's ISR*/
static void (* Globptr_vdCallbackFunction_EXTI15_10)(void) = NULL;		/*The callback function called by EXTI10 to EXTI15's ISR*/
/*__________________________________________________________________________________________________________________________________________*/


#endif /*EXTI_PRIVATE_H*/
