/************************************************************************/
/* SWC			: STK Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for System Timer									*/
/************************************************************************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/*Public Functions Declarations*/
/* 
 * Func. Name	: STK_vdInit
 * Description	: This function allows the user to initialize the system timer
 */
void STK_vdInit(void);

/* 
 * Func. Name	: STK_vdSetWait
 * Description	: This function allows the user to stop the processor for a certain amount of timer ticks
 * Note			: Interrupts will still be able to trigger ISRs
 * I/p Argument	: Copy_u32TickCount				Options: 0 -> 2^(24) - 1
 */
void STK_vdSetWait(u32 Copy_u32TickCount);

/* 
 * Func. Name	: STK_vdSetIntervalSingle
 * Description	: This function allows the user to trigger a callback function after a certain amount of timer ticks
 * I/p Argument	: Copy_u32TickCount				Options: 0 -> 2^(24) - 1
 * I/p Argument	: Inptr_vdCallbackFunction		pointer to callback function
 */
void STK_vdSetIntervalSingle(u32 Copy_u32TickCount, void (* Inptr_vdCallbackFunction)(void));

/* 
 * Func. Name	: STK_vdSetIntervalPeriodic
 * Description	: This function allows the user to trigger a callback function every certain amount of timer ticks
 * I/p Argument	: Copy_u32TickCount				Options: 0 -> 2^(24) - 1
 * I/p Argument	: Inptr_vdCallbackFunction		pointer to callback function
 */
void STK_vdSetIntervalPeriodic(u32 Copy_u32TickCount, void (* Inptr_vdCallbackFunction)(void));

/* 
 * Func. Name	: STK_vdGetElapsedTicks
 * Description	: This function allows the user to get the elapsed timer ticks
 * O/p Argument	: Outptr_u32ElapsedTicks		Options: 0 -> 2^(24) - 1
 */
void STK_vdGetElapsedTicks(u32* Outptr_u32ElapsedTicks);

/* 
 * Func. Name	: STK_vdGetRemainingTicks
 * Description	: This function allows the user to get the remaining timer ticks
 * O/p Argument	: Outptr_u32RemainingTicks		Options: 0 -> 2^(24) - 1
 */
void STK_vdGetRemainingTicks(u32* Outptr_u32RemainingTicks);

/* 
 * Func. Name	: STK_vdStop
 * Description	: This function allows the user to stop the timer
 */
void STK_vdStop(void);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*STK_INTERFACE_H*/
