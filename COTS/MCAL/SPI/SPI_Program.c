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
	GPIO_vdSetPinMode(PORT_MOSI, PIN_MOSI, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetAlternativeFunction(PORT_MOSI, PIN_MOSI, AF_MOSI);

	GPIO_vdSetPinMode(PORT_MISO, PIN_MISO, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetAlternativeFunction(PORT_MISO, PIN_MISO, AF_MISO);

	GPIO_vdSetPinMode(PORT_SCK, PIN_SCK, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetAlternativeFunction(PORT_SCK, PIN_SCK, AF_SCK);

	GPIO_vdSetPinMode(PORT_NSS, PIN_NSS, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetAlternativeFunction(PORT_NSS, PIN_NSS, AF_NSS);

	if (IS_MASTER)
	{
		SPI_CR1 = 0b0000001101000000;		/*0b 0000 0011 0100 0000*/
	}
	else
	{
		SPI_CR1 = 0b0000000101000000;		/*0b 0000 0001 0100 0000*/
	}
	SPI_CR1 |= SPI_CLK_PRE << SPI_CR1_BR0;		/*Setting prescaler*/
	MAKE_BIT(SPI_CR1, SPI_CR1_CPOL, SPI_CPOL);	/*Setting Clk Polarity*/
	MAKE_BIT(SPI_CR1, SPI_CR1_CPHA, SPI_CPHA);	/*Setting Clk Phase*/
}

void SPI_voidMasterTranceive(PortId_type Copy_enmSlavePortId, PinId_type Copy_enmSlavePinId, u8 Copy_u8DataToTransmit, u8* Outptr_DataRecieved)
{
	/*Select Slave*/
	GPIO_vdSetPinValue(Copy_enmSlavePortId, Copy_enmSlavePinId, STD_LOW);

	/*Send Data*/
	SPI_DR = Copy_u8DataToTransmit;		/*Writing to the DR register automatically triggers the transmition */
	
	/*Wait Until SPI is not Busy*/
	while(!GET_BIT(SPI_SR, SPI_SR_RXNE));

	/*Deselect Slave*/
	GPIO_vdSetPinValue(Copy_enmSlavePortId, Copy_enmSlavePinId, STD_HIGH);

	/*Output Data*/
	*Outptr_DataRecieved = (u8) (SPI_DR);
}

void SPI_voidSlaveTranceive(void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data), u8 Copy_u8InitialDataToTransmit)
{
	SET_BIT(SPI_CR2, SPI_CR2_RXNEIE);
	Globptr_vdCallbackFunction = Inptr_vdCallbackFunction;
	SPI_DR = Copy_u8InitialDataToTransmit;
}

void SPI_voidSlaveUpdateDataToTransmit(u8 Copy_u8DataToTransmit)
{
	SPI_DR = Copy_u8DataToTransmit;
}
/*__________________________________________________________________________________________________________________________________________*/


/*Interrupt Service Routines Definitions*/
void SPI1_IRQHandler(void)
{
	/*1- Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (SPI_DR));
	}
}
