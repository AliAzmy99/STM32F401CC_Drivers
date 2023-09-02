/************************************************************************/
/* SWC			: SCH Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for scheduler										*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../../MCAL/STK/STK_Interface.h"

	/*Include Needed SCH Files*/
#include "SCH_Interface.h"
#include "SCH_Private.h"
#include "SCH_Config.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
ErrorStatus SCH_errStartScheduler(void)
{
	/*Variables Definitions*/
	ErrorStatus Loc_errReturn = NO_ERROR;

	/*1- Init System Clk*/
	Loc_errReturn = STK_errInit();
	RETURN_IF_ERROR(Loc_errReturn);

	/*2- Scheduler Functionality*/
	STK_errSetIntervalPeriodic(SCH_TICK_TIME, &PRIV_errScheduler);

	/*3- Init Task Array*/
	for (u8 Loc_u8TaskCounter = 0; MAX_NO_TASKS > Loc_u8TaskCounter; ++Loc_u8TaskCounter)
	{
		Glob_strctTaskArray[Loc_u8TaskCounter].vdTaskFunction = NULL;
	}
	

	/*Returning ErrorStatus*/
	return NO_ERROR;
}

ErrorStatus SCH_errCreateTask(u8 Copy_u8Priority, u32 Copy_u32Periodicity, u8 Copy_u8FirstDelay, void (* Inptr_vdTaskFunction)(void))
{
	if (MAX_NO_TASKS <= Copy_u8Priority)
	{
		return INVALID_PARAMETERS;
	}
	
	Glob_strctTaskArray[Copy_u8Priority].u32Periodicity = Copy_u32Periodicity;
	Glob_strctTaskArray[Copy_u8Priority].u8FirstDelay = Copy_u8FirstDelay;
	Glob_strctTaskArray[Copy_u8Priority].vdTaskFunction = Inptr_vdTaskFunction;

	/*Returning ErrorStatus*/
	return NO_ERROR;
}

ErrorStatus SCH_errStartTask(void)
{

}
/*__________________________________________________________________________________________________________________________________________*/


/*Private Functions Definitions*/
static ErrorStatus PRIV_errScheduler(void)
{
	/*Calling Task Functions*/
	for (u8 Loc_u8TaskCounter = 0; MAX_NO_TASKS > Loc_u8TaskCounter; ++Loc_u8TaskCounter)
	{
		if (!Glob_strctTaskArray[Loc_u8TaskCounter].vdTaskFunction)
		{
			continue;
		}
		if (0 == Glob_strctTaskArray[Loc_u8TaskCounter].u8FirstDelay)
		{
			Glob_strctTaskArray[Loc_u8TaskCounter].vdTaskFunction();
			Glob_strctTaskArray[Loc_u8TaskCounter].u8FirstDelay += Glob_strctTaskArray[Loc_u8TaskCounter].Copy_u32Periodicity - 1;
		}
		else
		{
			--Glob_strctTaskArray[Loc_u8TaskCounter].u8FirstDelay;
		}
	}

	/*Returning ErrorStatus*/
	return NO_ERROR;
}
