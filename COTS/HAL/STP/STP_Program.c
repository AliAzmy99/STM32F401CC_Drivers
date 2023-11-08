/************************************************************************/
/* SWC			: STP Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Serial to Parallel using 74HC595				*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../../MCAL/STK/STK_Interface.h"
#include "../../MCAL/GPIO/GPIO_Interface.h"

	/*Include Needed STP Files*/
#include "STP_Config.h"
#include "STP_Interface.h"
#include "STP_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
/* 
 * Func. Name	: STP_vdInit
 * Description	: This function allows the user to initialize the STP driver
 */
void STP_vdInit(void)
{
	GPIO_vdSetPinMode(DS_PORT, DS_PIN, GPIO_OUTPUT);
	GPIO_vdSetPinOutputType(DS_PORT, DS_PIN, GPIO_PUSH_PULL);
	GPIO_vdSetPinOutputSpeed(DS_PORT, DS_PIN, GPIO_LOW_SPEED);

	GPIO_vdSetPinMode(SH_CLK_PORT, SH_CLK_PIN, GPIO_OUTPUT);
	GPIO_vdSetPinOutputType(SH_CLK_PORT, SH_CLK_PIN, GPIO_PUSH_PULL);
	GPIO_vdSetPinOutputSpeed(SH_CLK_PORT, SH_CLK_PIN, GPIO_LOW_SPEED);

	GPIO_vdSetPinMode(ST_CLK_PORT, ST_CLK_PIN, GPIO_OUTPUT);
	GPIO_vdSetPinOutputType(ST_CLK_PORT, ST_CLK_PIN, GPIO_PUSH_PULL);
	GPIO_vdSetPinOutputSpeed(ST_CLK_PORT, ST_CLK_PIN, GPIO_LOW_SPEED);
}

/* 
 * Func. Name	: STP_vdSendSynch
 * Description	: This function allows the user to send data synchronously
 * I/p Argument	: Copy_u32Data
 */
void STP_vdSendSynch(u32 Copy_u32Data)
{
	for(s8 Loc_u8Counter = (NUM_CHAINED_ICS << 3) - 1; 0 <= Loc_u8Counter; Loc_u8Counter--)
	{
		GPIO_vdSetPinValueDirectAccess(DS_PORT, DS_PIN, GET_BIT(Copy_u32Data, Loc_u8Counter));
		STK_vdSetWait(1);
		GPIO_vdSetPinValueDirectAccess(SH_CLK_PORT, SH_CLK_PIN, STD_HIGH);
		STK_vdSetWait(1);
		GPIO_vdSetPinValueDirectAccess(SH_CLK_PORT, SH_CLK_PIN, STD_LOW);
	}
	
	STK_vdSetWait(1);
	GPIO_vdSetPinValueDirectAccess(ST_CLK_PORT, ST_CLK_PIN, STD_HIGH);
	STK_vdSetWait(1);
	GPIO_vdSetPinValueDirectAccess(ST_CLK_PORT, ST_CLK_PIN, STD_LOW);
}
