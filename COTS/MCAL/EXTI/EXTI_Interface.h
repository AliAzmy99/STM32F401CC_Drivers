/************************************************************************/
/* SWC			: EXTI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for External Interrupts/Events Controller			*/
/************************************************************************/


#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


/*Public Macros*/
	/*Edge ID Options*/
#define EXTI_RISING_EDGE		(0u)
#define EXTI_FALLING_EDGE		(1u)
#define EXTI_DUAL_EDGE			(2u)
#define EXTI_NO_EDGE			(3u)

	/*Line ID Options*/
#define EXTI_LINE_0			GPIO_PIN_0
#define EXTI_LINE_1			GPIO_PIN_1
#define EXTI_LINE_2			GPIO_PIN_2
#define EXTI_LINE_3			GPIO_PIN_3
#define EXTI_LINE_4			GPIO_PIN_4
#define EXTI_LINE_5			GPIO_PIN_5
#define EXTI_LINE_6			GPIO_PIN_6
#define EXTI_LINE_7			GPIO_PIN_7
#define EXTI_LINE_8			GPIO_PIN_8
#define EXTI_LINE_9			GPIO_PIN_9
#define EXTI_LINE_10		GPIO_PIN_10
#define EXTI_LINE_11		GPIO_PIN_11
#define EXTI_LINE_12		GPIO_PIN_12
#define EXTI_LINE_13		GPIO_PIN_13
#define EXTI_LINE_14		GPIO_PIN_14
#define EXTI_LINE_15		GPIO_PIN_15
#define EXTI_NOT_A_LINE		GPIO_NOT_A_PIN
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: EXTI_errInit
 * Description	: This function allows the user to initialize the external interrupts/events controller
 * Return		: Error status of function
 */
ErrorStatus EXTI_errInit(void);

/* 
 * Func. Name	: EXTI_errEnableInterrupt
 * Description	: This function allows the user to enable a certain interrupt
 * I/p Argument	: Copy_u8InterruptLine				Options: EXTI_LINE_0 -> EXTI_LINE_15
 * Return		: Error status of function
 */
ErrorStatus EXTI_errEnableInterrupt(u8 Copy_u8InterruptLine);

/* 
 * Func. Name	: EXTI_errDisableInterrupt
 * Description	: This function allows the user to disable a certain interrupt
 * I/p Argument	: Copy_u8InterruptLine				Options: EXTI_LINE_0 -> EXTI_LINE_15
 * Return		: Error status of function
 */
ErrorStatus EXTI_errDisableInterrupt(u8 Copy_u8InterruptLine);

/* 
 * Func. Name	: EXTI_errSetCallbackFunction
 * Description	: This function allows the user set the callback function that will be called when a certain interrupt line triggers its ISR
 * I/p Argument	: Copy_u8InterruptLine				Options: EXTI_LINE_0 -> EXTI_LINE_15
 * I/p Argument	: Inptr_vdCallbackFunction			pointer to callback function
 * Return		: Error status of function
 */
ErrorStatus EXTI_errSetCallbackFunction(u8 Copy_u8InterruptLine, void (* Inptr_vdCallbackFunction)(void));

/* 
 * Func. Name	: EXTI_errEnableEvent
 * Description	: This function allows the user to enable a certain event
 * I/p Argument	: Copy_u8EventLine					Options: EXTI_LINE_0 -> EXTI_LINE_15
 * Return		: Error status of function
 */
ErrorStatus EXTI_errEnableEvent(u8 Copy_u8EventLine);

/* 
 * Func. Name	: EXTI_errDisableEvent
 * Description	: This function allows the user to disable a certain event
 * I/p Argument	: Copy_u8EventLine					Options: EXTI_LINE_0 -> EXTI_LINE_15
 * Return		: Error status of function
 */
ErrorStatus EXTI_errDisableEvent(u8 Copy_u8EventLine);

/* 
 * Func. Name	: EXTI_errSelectEdgeTriggers
 * Description	: This function allows the user to choose which edges trigger a certain interrupt/event line
 * I/p Argument	: Copy_u8Line						Options: EXTI_LINE_0 -> EXTI_LINE_15
 * I/p Argument	: Copy_u8EdgeTrigger				Options: EXTI_RISING_EDGE, EXTI_FALLING_EDGE, EXTI_DUAL_EDGE, EXTI_NO_EDGE
 * Return		: Error status of function
 */
ErrorStatus EXTI_errSelectEdgeTriggers(u8 Copy_u8Line, u8 Copy_u8EdgeTrigger);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*EXTI_INTERFACE_H*/
