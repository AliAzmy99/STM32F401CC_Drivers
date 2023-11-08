/********************************************************************************************/
/* SWC			: USART Driver																*/
/* Author		: Ali Azmy																	*/
/* Version		: V0.0																		*/
/* Description	: SWC for Universal Synchronous Asynchronous Receiver Transmitter			*/
/********************************************************************************************/


/*Include Needed Files*/
	/*Include Needed LIB Files*/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/MACROS.h"

	/*Include Needed MCAL Files*/
#include "../../MCAL/GPIO/GPIO_Interface.h"

	/*Include Needed USART Files*/
#include "USART_Config.h"
#include "USART_Interface.h"
#include "USART_Private.h"
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Definitions*/
void USART_vdInit(UsartId_type Copy_enmUsartId, UsartConfig_type* strctUsartConfig)
{
	/*Variables Definitions*/
	volatile UsartRegisters_type* Loc_strctUsartRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmUsartId)
	{
	case USART_1:
		Loc_strctUsartRegister = USART1_FIRST_ADDRESS;
		break;
	case USART_2:
		Loc_strctUsartRegister = USART2_FIRST_ADDRESS;
		break;
	case USART_6:
		Loc_strctUsartRegister = USART6_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	/*Configuring USART Registers*/
	Loc_strctUsartRegister->CR1 = 0b0000000000000000;
	if (strctUsartConfig->enmIsMaster)
	{
		SET_BIT(Loc_strctUsartRegister->CR1, USART_CR1_MSTR);			/*Setting as master*/
		SET_BIT(Loc_strctUsartRegister->CR1, USART_CR1_SSM);			/*Enabling the software slave management*/
		SET_BIT(Loc_strctUsartRegister->CR1, USART_CR1_SSI);			/*Deselecting as slave internally*/
	}
	
	Loc_strctUsartRegister->CR1 |= (strctUsartConfig->enmUsartClkPre) << USART_CR1_BR0;		/*Setting prescaler*/
	MAKE_BIT(Loc_strctUsartRegister->CR1, USART_CR1_CPOL, strctUsartConfig->enmUsartCpol);	/*Setting Clk Polarity*/
	MAKE_BIT(Loc_strctUsartRegister->CR1, USART_CR1_CPHA, strctUsartConfig->enmUsartCpha);	/*Setting Clk Phase*/
	SET_BIT(Loc_strctUsartRegister->CR1, USART_CR1_SPE);								/*Enabling the USART*/
}

void USART_voidMasterTranceive(UsartId_type Copy_enmUsartId, PortId_type Copy_enmSlavePortId, PinId_type Copy_enmSlavePinId, u8 Copy_u8DataToTransmit, u8* Outptr_DataRecieved)
{
	/*Variables Definitions*/
	volatile UsartRegisters_type* Loc_strctUsartRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmUsartId)
	{
	case USART_1:
		Loc_strctUsartRegister = USART1_FIRST_ADDRESS;
		break;
	case USART_2:
		Loc_strctUsartRegister = USART2_FIRST_ADDRESS;
		break;
	case USART_6:
		Loc_strctUsartRegister = USART6_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	/*Select Slave*/
	GPIO_vdSetPinValue(Copy_enmSlavePortId, Copy_enmSlavePinId, STD_LOW);

	/*Send Data*/
	Loc_strctUsartRegister->DR = Copy_u8DataToTransmit;		/*Writing to the DR register automatically triggers the transmition */
	
	/*Wait Until USART is not Busy*/
	while(!GET_BIT(Loc_strctUsartRegister->SR, USART_SR_RXNE));

	/*Deselect Slave*/
	GPIO_vdSetPinValue(Copy_enmSlavePortId, Copy_enmSlavePinId, STD_HIGH);

	/*Output Data*/
	*Outptr_DataRecieved = (u8) (Loc_strctUsartRegister->DR);
}

void USART_voidSlaveTranceive(UsartId_type Copy_enmUsartId, void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data), u8 Copy_u8InitialDataToTransmit)
{
	/*Variables Definitions*/
	volatile UsartRegisters_type* Loc_strctUsartRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmUsartId)
	{
	case USART_1:
		Loc_strctUsartRegister = USART1_FIRST_ADDRESS;
		break;
	case USART_2:
		Loc_strctUsartRegister = USART2_FIRST_ADDRESS;
		break;
	case USART_6:
		Loc_strctUsartRegister = USART6_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	SET_BIT(Loc_strctUsartRegister->CR2, USART_CR2_RXNEIE);
	Globptr_vdCallbackFunction = Inptr_vdCallbackFunction;
	Loc_strctUsartRegister->DR = Copy_u8InitialDataToTransmit;
}

void USART_voidSlaveUpdateDataToTransmit(UsartId_type Copy_enmUsartId, u8 Copy_u8DataToTransmit)
{
	/*Variables Definitions*/
	volatile UsartRegisters_type* Loc_strctUsartRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmUsartId)
	{
	case USART_1:
		Loc_strctUsartRegister = USART1_FIRST_ADDRESS;
		break;
	case USART_2:
		Loc_strctUsartRegister = USART2_FIRST_ADDRESS;
		break;
	case USART_6:
		Loc_strctUsartRegister = USART6_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	Loc_strctUsartRegister->DR = Copy_u8DataToTransmit;
}
/*__________________________________________________________________________________________________________________________________________*/


/*Interrupt Service Routines Definitions*/
/*
 * Func. Name	: USART1_IRQHandler
 * Description	: This function calls the callback function giving it the received data and clears the interrupt flag
 */
void USART1_IRQHandler(void)
{
	/*Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (USART1_FIRST_ADDRESS->DR));
	}
}

/*
 * Func. Name	: USART2_IRQHandler
 * Description	: This function calls the callback function giving it the received data and clears the interrupt flag
 */
void USART2_IRQHandler(void)
{
	/*Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (USART2_FIRST_ADDRESS->DR));
	}
}

/*
 * Func. Name	: USART6_IRQHandler
 * Description	: This function calls the callback function giving it the received data and clears the interrupt flag
 */
void USART6_IRQHandler(void)
{
	/*Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (USART6_FIRST_ADDRESS->DR));
	}
}
