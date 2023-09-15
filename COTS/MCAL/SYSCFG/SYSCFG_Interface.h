/************************************************************************/
/* SWC  	    : SYSCFG Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Configuration Controller				*/
/************************************************************************/


#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H


/*Public Macros*/
	/*Port ID Options*/
#define SYSCFG_PORT_A			GPIO_PORT_A
#define SYSCFG_PORT_B			GPIO_PORT_B
#define SYSCFG_PORT_C			GPIO_PORT_C
#define SYSCFG_NOT_A_PORT		GPIO_NOT_A_PORT

	/*Line ID Options*/
#define SYSCFG_LINE_0			EXTI_LINE_0
#define SYSCFG_LINE_1			EXTI_LINE_1
#define SYSCFG_LINE_2			EXTI_LINE_2
#define SYSCFG_LINE_3			EXTI_LINE_3
#define SYSCFG_LINE_4			EXTI_LINE_4
#define SYSCFG_LINE_5			EXTI_LINE_5
#define SYSCFG_LINE_6			EXTI_LINE_6
#define SYSCFG_LINE_7			EXTI_LINE_7
#define SYSCFG_LINE_8			EXTI_LINE_8
#define SYSCFG_LINE_9			EXTI_LINE_9
#define SYSCFG_LINE_10			EXTI_LINE_10
#define SYSCFG_LINE_11			EXTI_LINE_11
#define SYSCFG_LINE_12			EXTI_LINE_12
#define SYSCFG_LINE_13			EXTI_LINE_13
#define SYSCFG_LINE_14			EXTI_LINE_14
#define SYSCFG_LINE_15			EXTI_LINE_15
#define SYSCFG_NOT_A_LINE		EXTI_NOT_A_LINE
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: SYSCFG_vdSetExtiLinePort
 * Description	: This function allows the user to choose the Port that a particular EXTI line is connected to
 * I/p Argument	: Copy_u8Line			Options: SYSCFG_LINE_0 -> SYSCFG_LINE_15
 * I/p Argument : Copy_u8Port			Options: SYSCFG_PORT_A -> SYSCFG_PORT_C
 */
void SYSCFG_vdSetExtiLinePort(u8 Copy_u8Line, u8 Copy_u8Port);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SYSCFG_INTERFACE_H*/
