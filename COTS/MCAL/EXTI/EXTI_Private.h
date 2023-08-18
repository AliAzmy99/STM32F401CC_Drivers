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

/*__________________________________________________________________________________________________________________________________________*/


/*Private Global Variables Definitions*/
static void (* Globptr_vdCallbackFunction_EXTI0)(void) = NULL;
static void (* Globptr_vdCallbackFunction_EXTI1)(void) = NULL;
static void (* Globptr_vdCallbackFunction_EXTI2)(void) = NULL;
static void (* Globptr_vdCallbackFunction_EXTI3)(void) = NULL;
static void (* Globptr_vdCallbackFunction_EXTI4)(void) = NULL;
static void (* Globptr_vdCallbackFunction_EXTI9_5)(void) = NULL;
static void (* Globptr_vdCallbackFunction_EXTI15_10)(void) = NULL;
/*__________________________________________________________________________________________________________________________________________*/


#endif /*EXTI_PRIVATE_H*/
