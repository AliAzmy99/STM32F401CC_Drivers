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
 * Func. Name	: STK_errInit
 * Description	: This function allows the user to initiate the system timer
 * Return		: Error status of function
 */
ErrorStatus STK_errInit(void);

/* 
 * Func. Name	: STK_errSetWait
 * Description	: This function allows the user to stop the processor for a certain amount of timer ticks.
 * Note			: Interrupts will still be able to trigger ISRs.
 * I/p Argument	: Copy_u32TickCount				Options: 0 -> 2^(24) - 1
 * Return		: Error status of function
 */
ErrorStatus STK_errSetWait(u32 Copy_u32TickCount);

/* 
 * Func. Name	: STK_errSetIntervalSingle
 * Description	: This function allows the user to trigger a callback function after a certain amount of timer ticks.
 * I/p Argument	: Copy_u32TickCount				Options: 0 -> 2^(24) - 1
 * Return		: Error status of function
 */
ErrorStatus STK_errSetIntervalSingle(u32 Copy_u32TickCount, void (* Inptr_vdCallbackFunction)(void));

/* 
 * Func. Name	: STK_errSetIntervalPeriodic
 * Description	: This function allows the user to trigger a callback function every certain amount of timer ticks.
 * I/p Argument	: Copy_u32TickCount				Options: 0 -> 2^(24) - 1
 * Return		: Error status of function
 */
ErrorStatus STK_errSetIntervalPeriodic(u32 Copy_u32TickCount, void (* Inptr_vdCallbackFunction)(void));

/* 
 * Func. Name	: STK_errGetElapsedTicks
 * Description	: This function allows the user to get the elapsed timer ticks.
 * O/p Argument	: Outptr_u32ElapsedTicks		Options: 0 -> 2^(24) - 1
 * Return		: Error status of function
 */
ErrorStatus STK_errGetElapsedTicks(u32* Outptr_u32ElapsedTicks);

/* 
 * Func. Name	: STK_errGetRemainingTicks
 * Description	: This function allows the user to get the remaining timer ticks.
 * O/p Argument	: Outptr_u32RemainingTicks		Options: 0 -> 2^(24) - 1
 * Return		: Error status of function
 */
ErrorStatus STK_errGetRemainingTicks(u32* Outptr_u32RemainingTicks);

/* 
 * Func. Name	: STK_errStop
 * Description	: This function allows the user to stop the timer.
 * Return		: Error status of function
 */
ErrorStatus STK_errStop(void);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*STK_INTERFACE_H*/
