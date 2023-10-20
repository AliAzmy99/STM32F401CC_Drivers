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
void SPI_vdInit(void)
{
	GPIO_vdSetPinMode(PIN_MOSI, PORT_MOSI, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetPinMode(PIN_MISO, PORT_MISO, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetPinMode(PIN_SCK, PORT_SCK, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetPinMode(PIN_NSS, PORT_NSS, GPIO_ALTERNATE_FUNCTION);

	if (IS_MASTER)
	{
		SPI_CR1 = 0b0000001101000000;		/*0b 0000 0011 0100 0000*/
	}
	else
	{
		SPI_CR1 = 0b0000000101000000;		/*0b 0000 0001 0100 0000*/
	}
	SPI_CR1 |= SPI_CLK_PRE << SPI_CR1_BR0;	/*Setting prescaler*/
}

void SPI_voidTranceive(PortId_type Copy_enmPortId, PinId_type Copy_enmPinId, u8 Copy_u8DataToTransmit, u8* Outptr_DataRecieved)
{
	/*Select Slave*/
	GPIO_vdSetPinValue(Copy_enmPortId, Copy_enmPinId, STD_LOW);

	/*Send Data*/
	SPI_DR = Copy_u8DataToTransmit;		/*Writing to the DR register automatically triggers the transmition */
	
	/*Wait Until SPI is not Busy*/
	while(GET_BIT(SPI_SR, 7));

	/*Deselect Slave*/
	GPIO_vdSetPinValue(Copy_enmPortId, Copy_enmPinId, STD_HIGH);

	/*Output Data*/
	*Outptr_DataRecieved = (u8) (SPI_DR);
}