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
void SPI_vdInit(SpiId_type Copy_enmSpiId, SpiConfig_type* strctSpiConfig)
{
	/*Variables Definitions*/
	volatile SpiRegisters_type* Loc_strctSpiRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmSpiId)
	{
	case SPI_1:
		Loc_strctSpiRegister = SPI1_FIRST_ADDRESS;
		break;
	case SPI_2:
		Loc_strctSpiRegister = SPI2_FIRST_ADDRESS;
		break;
	case SPI_3:
		Loc_strctSpiRegister = SPI3_FIRST_ADDRESS;
		break;
	case SPI_4:
		Loc_strctSpiRegister = SPI4_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	/*Setting-Up Pins*/
	GPIO_vdSetPinMode(strctSpiConfig->enmMosiPortId, strctSpiConfig->enmMosiPinId, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetAlternativeFunction(strctSpiConfig->enmMosiPortId, strctSpiConfig->enmMosiPinId, strctSpiConfig->enmMosiAf);

	GPIO_vdSetPinMode(strctSpiConfig->enmMisoPortId, strctSpiConfig->enmMisoPinId, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetAlternativeFunction(strctSpiConfig->enmMisoPortId, strctSpiConfig->enmMisoPinId, strctSpiConfig->enmMisoAf);

	GPIO_vdSetPinMode(strctSpiConfig->enmSckPortId, strctSpiConfig->enmSckPinId, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetAlternativeFunction(strctSpiConfig->enmSckPortId, strctSpiConfig->enmSckPinId, strctSpiConfig->enmSckAf);

	GPIO_vdSetPinMode(strctSpiConfig->enmNssPortId, strctSpiConfig->enmNssPinId, GPIO_ALTERNATE_FUNCTION);
	GPIO_vdSetAlternativeFunction(strctSpiConfig->enmNssPortId, strctSpiConfig->enmNssPinId, strctSpiConfig->enmNssAf);

	/*Configuring SPI Registers*/
	if (strctSpiConfig->enmIsMaster)
	{
		Loc_strctSpiRegister->CR1 = 0b0000001101000000;		/*0b 0000 0011 0100 0000*/
	}
	else
	{
		Loc_strctSpiRegister->CR1 = 0b0000000101000000;		/*0b 0000 0001 0100 0000*/
	}
	Loc_strctSpiRegister->CR1 |= (strctSpiConfig->enmSpiClkPre) << SPI_CR1_BR0;		/*Setting prescaler*/
	MAKE_BIT(Loc_strctSpiRegister->CR1, SPI_CR1_CPOL, strctSpiConfig->enmSpiCpol);	/*Setting Clk Polarity*/
	MAKE_BIT(Loc_strctSpiRegister->CR1, SPI_CR1_CPHA, strctSpiConfig->enmSpiCpha);	/*Setting Clk Phase*/
}

void SPI_voidMasterTranceive(SpiId_type Copy_enmSpiId, PortId_type Copy_enmSlavePortId, PinId_type Copy_enmSlavePinId, u8 Copy_u8DataToTransmit, u8* Outptr_DataRecieved)
{
	/*Variables Definitions*/
	volatile SpiRegisters_type* Loc_strctSpiRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmSpiId)
	{
	case SPI_1:
		Loc_strctSpiRegister = SPI1_FIRST_ADDRESS;
		break;
	case SPI_2:
		Loc_strctSpiRegister = SPI2_FIRST_ADDRESS;
		break;
	case SPI_3:
		Loc_strctSpiRegister = SPI3_FIRST_ADDRESS;
		break;
	case SPI_4:
		Loc_strctSpiRegister = SPI4_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	/*Select Slave*/
	GPIO_vdSetPinValue(Copy_enmSlavePortId, Copy_enmSlavePinId, STD_LOW);

	/*Send Data*/
	Loc_strctSpiRegister->DR = Copy_u8DataToTransmit;		/*Writing to the DR register automatically triggers the transmition */
	
	/*Wait Until SPI is not Busy*/
	while(!GET_BIT(Loc_strctSpiRegister->SR, SPI_SR_RXNE));

	/*Deselect Slave*/
	GPIO_vdSetPinValue(Copy_enmSlavePortId, Copy_enmSlavePinId, STD_HIGH);

	/*Output Data*/
	*Outptr_DataRecieved = (u8) (Loc_strctSpiRegister->DR);
}

void SPI_voidSlaveTranceive(SpiId_type Copy_enmSpiId, void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data), u8 Copy_u8InitialDataToTransmit)
{
	/*Variables Definitions*/
	volatile SpiRegisters_type* Loc_strctSpiRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmSpiId)
	{
	case SPI_1:
		Loc_strctSpiRegister = SPI1_FIRST_ADDRESS;
		break;
	case SPI_2:
		Loc_strctSpiRegister = SPI2_FIRST_ADDRESS;
		break;
	case SPI_3:
		Loc_strctSpiRegister = SPI3_FIRST_ADDRESS;
		break;
	case SPI_4:
		Loc_strctSpiRegister = SPI4_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	SET_BIT(Loc_strctSpiRegister->CR2, SPI_CR2_RXNEIE);
	Globptr_vdCallbackFunction = Inptr_vdCallbackFunction;
	Loc_strctSpiRegister->DR = Copy_u8InitialDataToTransmit;
}

void SPI_voidSlaveUpdateDataToTransmit(SpiId_type Copy_enmSpiId, u8 Copy_u8DataToTransmit)
{
	/*Variables Definitions*/
	volatile SpiRegisters_type* Loc_strctSpiRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmSpiId)
	{
	case SPI_1:
		Loc_strctSpiRegister = SPI1_FIRST_ADDRESS;
		break;
	case SPI_2:
		Loc_strctSpiRegister = SPI2_FIRST_ADDRESS;
		break;
	case SPI_3:
		Loc_strctSpiRegister = SPI3_FIRST_ADDRESS;
		break;
	case SPI_4:
		Loc_strctSpiRegister = SPI4_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	Loc_strctSpiRegister->DR = Copy_u8DataToTransmit;
}
/*__________________________________________________________________________________________________________________________________________*/


/*Interrupt Service Routines Definitions*/
void SPI1_IRQHandler(void)
{
	/*Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (SPI1_FIRST_ADDRESS->DR));
	}
}

void SPI2_IRQHandler(void)
{
	/*Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (SPI2_FIRST_ADDRESS->DR));
	}
}

void SPI3_IRQHandler(void)
{
	/*Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (SPI3_FIRST_ADDRESS->DR));
	}
}

void SPI4_IRQHandler(void)
{
	/*Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (SPI4_FIRST_ADDRESS->DR));
	}
}
