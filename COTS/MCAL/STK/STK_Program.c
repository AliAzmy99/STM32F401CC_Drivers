/************************************************************************/
/* SWC  	    : STK Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Timer									*/
/************************************************************************/


#warning Add Prescaller adjustments
/*Include Needed Files*/
	/*Include Needed Library Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed STK Files*/
#include "STK_Interface.h"
#include "STK_Private.h"
#include "STK_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
ErrorStatus STK_errInit(void)
{
	/*1- Stop Timer*/
	CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);

	/*2- Disable Interrupts*/
	CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);

	/*3- Choose Clk Src*/
	#if (SRC_AHB == STK_CLK_SRC)
		SET_BIT(STK_CTRL, STK_CTRL_CLKSOURCE);
	#elif (SRC_AHB_DIV_8 == STK_CLK_SRC)
		CLR_BIT(STK_CTRL, STK_CTRL_CLKSOURCE);
	#else
		#error Error: Invalid STK_CLK_SRC Configuration
	#endif

	return NO_ERROR;
}

ErrorStatus STK_errSetWait(u32 Copy_u32TickCount)
{
	/*I/p validation*/
	if (0xFFFFFF < Copy_u32TickCount)
	{
		return INVALID_PARAMETERS;
	}
	
	/*1- Load the TickCount into the LOAD Register*/
	STK_LOAD = Copy_u32TickCount;

	/*2- Initialize the VAL Register */
	STK_VAL = 0;

	/*3- Start Timer*/
	SET_BIT(STK_CTRL, STK_CTRL_ENABLE);

	/*4- Poll on the Count Flag*/
	while (!GET_BIT(STK_CTRL, STK_CTRL_COUNTFLAG))
	{
		/*Wait*/
	}
	
	/*5- Stop Timer*/
	CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);

	return NO_ERROR;
}

ErrorStatus STK_errSetIntervalSingle(u32 Copy_u32TickCount, void (* Inptr_vdCallbackFunction)(void))
{
	/*I/p validation*/
	if (0xFFFFFF < Copy_u32TickCount)
	{
		return INVALID_PARAMETERS;
	}

	/*1- Load the TickCount*/
	STK_LOAD = Copy_u32TickCount;

	/*2- Initialize the VAL Register */
	STK_VAL = 0;

	/*3- Set Callback Function*/
	Globptr_vdCallbackFunction = Inptr_vdCallbackFunction;

	/*4- Set Interval Flag*/
	Glob_u8IntervalFlag = INTERVAL_FLAG_SINGLE_MODE;

	/*5- Enable Interrupts*/
	SET_BIT(STK_CTRL, STK_CTRL_TICKINT);

	/*6- Start Timer*/
	SET_BIT(STK_CTRL, STK_CTRL_ENABLE);

	return NO_ERROR;
}

ErrorStatus STK_errSetIntervalPeriodic(u32 Copy_u32TickCount, void (* Inptr_vdCallbackFunction)(void))
{
	/*I/p validation*/
	if (0xFFFFFF < Copy_u32TickCount)
	{
		return INVALID_PARAMETERS;
	}

	/*1- Load the TickCount*/
	STK_LOAD = Copy_u32TickCount;

	/*2- Initialize the VAL Register */
	STK_VAL = 0;

	/*3- Set Callback Function*/
	Globptr_vdCallbackFunction = Inptr_vdCallbackFunction;

	/*4- Set Interval Flag*/
	Glob_u8IntervalFlag = INTERVAL_FLAG_PERIODIC_MODE;

	/*5- Enable Interrupts*/
	SET_BIT(STK_CTRL, STK_CTRL_TICKINT);

	/*6- Start Timer*/
	SET_BIT(STK_CTRL, STK_CTRL_ENABLE);

	return NO_ERROR;
}

ErrorStatus STK_errGetElapsedTicks(u32* Outptr_u32ElapsedTicks)
{
	/*I/p Validation*/
	if (!Outptr_u32ElapsedTicks)
	{
		return NULL_POINTER_PASSED;
	}

	/*Outputting Elapsed Ticks*/
	*Outptr_u32ElapsedTicks = STK_LOAD - STK_VAL;

	return NO_ERROR;
}

ErrorStatus STK_errGetRemainingTicks(u32* Outptr_u32RemainingTicks)
{
	/*I/p Validation*/
	if (!Outptr_u32RemainingTicks)
	{
		return NULL_POINTER_PASSED;
	}

	/*Outputting Remaining Ticks*/
	*Outptr_u32RemainingTicks = STK_VAL;

	return NO_ERROR;
}

ErrorStatus STK_errStop(void)
{
	/*Stop Timer*/
	CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);

	/*Stop Interrupts*/
	CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);

	return NO_ERROR;
}
/*__________________________________________________________________________________________________________________________________________*/


/*Interrupt Service Routines Defenitions*/
void SysTick_Handler(void)
{
	/*Variables Defenitions*/
	u8 Loc_u8Temp = 0;

	/*1-Stopping Timer if Single Mode */
	if (INTERVAL_FLAG_SINGLE_MODE == Glob_u8IntervalFlag)
	{
		/*Stop Timer*/
		CLR_BIT(STK_CTRL, STK_CTRL_ENABLE);
		/*Stop Interrupts*/
		CLR_BIT(STK_CTRL, STK_CTRL_TICKINT);
	}

	/*2- Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction();
	}

	/*3- Clear Interrupt Flag*/
	Loc_u8Temp = GET_BIT(STK_CTRL, STK_CTRL_COUNTFLAG);
}
