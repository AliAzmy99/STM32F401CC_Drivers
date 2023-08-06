/************************************************************************/
/* SWC  	    : STK Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for Reset and Clock Control						*/
/************************************************************************/


#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/*Public Macros*/
    /*Peripheral ID Options*/

/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
ErrorStatus STK_errInit(void);
ErrorStatus STK_errSetBusyWait(u32 Copy_u32TickCount);
ErrorStatus STK_errSetIntervalSingle(u32 Copy_u32TickCount, void (*CallbackFunction)(void));
ErrorStatus STK_errSetIntervalPeriodic(u32 Copy_u32TickCount, void (*CallbackFunction)(void));
ErrorStatus STK_errGetElapsedTicks(u32* Outptr_u32ElapsedTicks);
ErrorStatus STK_errGetRemainingTicks(u32* Outptr_u32RemainingTicks);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*STK_INTERFACE_H*/
