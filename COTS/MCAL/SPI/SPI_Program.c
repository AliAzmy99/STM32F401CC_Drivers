/************************************************************************/
/* SWC			: SPI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Serial Peripheral Interface					*/
/************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../../MCAL/GPIO/GPIO_Interface.h"

	/*Include Needed SPI Files*/
#include "SPI_Config.h"
#include "SPI_Interface.h"
#include "SPI_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
void SPI_vdInit(SlaveMaster_type Copy_enmSlaveMaster, )
{
	GPIO_vdSetPinMode(MOSI, , GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetPinMode(MISO, , GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetPinMode(CLK, , GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetPinMode(SS, , GPIO_ALTERNATE_FUNCTION);

	SPI_CR1 = 0b0000000101000000;		/*0b0000 0001 0100 0000*/

}