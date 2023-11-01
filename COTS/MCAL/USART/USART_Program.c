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
/* 
 * Func. Name	: USART_vdInit
 * Description	: This function allows the user to initialize one of the USARTs
 * I/p Argument	: Copy_enmSpiId				: The USART to initialize
 * I/p Argument	: strctSpiConfig			: The USART config struct
 */
void USART_vdInit(SpiId_type Copy_enmSpiId, SpiConfig_type* strctSpiConfig)
{
	/*Variables Definitions*/
	volatile SpiRegisters_type* Loc_strctSpiRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmSpiId)
	{
	case USART_1:
		Loc_strctSpiRegister = USART1_FIRST_ADDRESS;
		break;
	case USART_2:
		Loc_strctSpiRegister = USART2_FIRST_ADDRESS;
		break;
	case USART_3:
		Loc_strctSpiRegister = USART3_FIRST_ADDRESS;
		break;
	case USART_4:
		Loc_strctSpiRegister = USART4_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	/*Configuring USART Registers*/
	Loc_strctSpiRegister->CR1 = 0b0000000000000000;
	if (strctSpiConfig->enmIsMaster)
	{
		SET_BIT(Loc_strctSpiRegister->CR1, USART_CR1_MSTR);			/*Setting as master*/
		SET_BIT(Loc_strctSpiRegister->CR1, USART_CR1_SSM);			/*Enabling the software slave management*/
		SET_BIT(Loc_strctSpiRegister->CR1, USART_CR1_SSI);			/*Deselecting as slave internally*/
	}
	
	Loc_strctSpiRegister->CR1 |= (strctSpiConfig->enmSpiClkPre) << USART_CR1_BR0;		/*Setting prescaler*/
	MAKE_BIT(Loc_strctSpiRegister->CR1, USART_CR1_CPOL, strctSpiConfig->enmSpiCpol);	/*Setting Clk Polarity*/
	MAKE_BIT(Loc_strctSpiRegister->CR1, USART_CR1_CPHA, strctSpiConfig->enmSpiCpha);	/*Setting Clk Phase*/
	SET_BIT(Loc_strctSpiRegister->CR1, USART_CR1_SPE);								/*Enabling the USART*/
}

/* 
 * Func. Name	: USART_voidMasterTranceive
 * Description	: This function allows the user to tranceive data when in master mode
 * I/p Argument	: Copy_enmSpiId				: The USART to use
 * I/p Argument	: Copy_enmSlavePortId		: The port of the pin used to select the slave
 * I/p Argument	: Copy_enmSlavePinId		: The pin used to select the slave
 * I/p Argument : Copy_u8DataToTransmit		: The data to be transmitted to the slave
 * O/p Argument : Outptr_DataRecieved		: The data received from the slave
 */
void USART_voidMasterTranceive(SpiId_type Copy_enmSpiId, PortId_type Copy_enmSlavePortId, PinId_type Copy_enmSlavePinId, u8 Copy_u8DataToTransmit, u8* Outptr_DataRecieved)
{
	/*Variables Definitions*/
	volatile SpiRegisters_type* Loc_strctSpiRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmSpiId)
	{
	case USART_1:
		Loc_strctSpiRegister = USART1_FIRST_ADDRESS;
		break;
	case USART_2:
		Loc_strctSpiRegister = USART2_FIRST_ADDRESS;
		break;
	case USART_3:
		Loc_strctSpiRegister = USART3_FIRST_ADDRESS;
		break;
	case USART_4:
		Loc_strctSpiRegister = USART4_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	/*Select Slave*/
	GPIO_vdSetPinValue(Copy_enmSlavePortId, Copy_enmSlavePinId, STD_LOW);

	/*Send Data*/
	Loc_strctSpiRegister->DR = Copy_u8DataToTransmit;		/*Writing to the DR register automatically triggers the transmition */
	
	/*Wait Until USART is not Busy*/
	while(!GET_BIT(Loc_strctSpiRegister->SR, USART_SR_RXNE));

	/*Deselect Slave*/
	GPIO_vdSetPinValue(Copy_enmSlavePortId, Copy_enmSlavePinId, STD_HIGH);

	/*Output Data*/
	*Outptr_DataRecieved = (u8) (Loc_strctSpiRegister->DR);
}

/* 
 * Func. Name	: USART_voidSlaveTranceive
 * Description	: This function allows the user to setup the USART for data tranceiving when in slave mode
 * I/p Argument	: Copy_enmSpiId						: The USART to use
 * I/p Argument	: Inptr_vdCallbackFunction			: Pointer to the function to be called when a transmission occurs
 * 				  									  It takes the received byte as an argument
 * I/p Argument : Copy_u8InitialDataToTransmit		: The data to be transmitted to the master during the first transmission
 */
void USART_voidSlaveTranceive(SpiId_type Copy_enmSpiId, void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data), u8 Copy_u8InitialDataToTransmit)
{
	/*Variables Definitions*/
	volatile SpiRegisters_type* Loc_strctSpiRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmSpiId)
	{
	case USART_1:
		Loc_strctSpiRegister = USART1_FIRST_ADDRESS;
		break;
	case USART_2:
		Loc_strctSpiRegister = USART2_FIRST_ADDRESS;
		break;
	case USART_3:
		Loc_strctSpiRegister = USART3_FIRST_ADDRESS;
		break;
	case USART_4:
		Loc_strctSpiRegister = USART4_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	SET_BIT(Loc_strctSpiRegister->CR2, USART_CR2_RXNEIE);
	Globptr_vdCallbackFunction = Inptr_vdCallbackFunction;
	Loc_strctSpiRegister->DR = Copy_u8InitialDataToTransmit;
}

/* 
 * Func. Name	: USART_voidSlaveUpdateDataToTransmit
 * Description	: This function allows the user to update the data to be sent by the USART during the upcomming
 * 											  transmission when in slave mode
 * I/p Argument	: Copy_enmSpiId				: The USART to use
 * I/p Argument : Copy_u8DataToTransmit		: The data to be transmitted to the master during the next transmission
 */
void USART_voidSlaveUpdateDataToTransmit(SpiId_type Copy_enmSpiId, u8 Copy_u8DataToTransmit)
{
	/*Variables Definitions*/
	volatile SpiRegisters_type* Loc_strctSpiRegister;

	/*Choosing Correct Register Address*/
	switch (Copy_enmSpiId)
	{
	case USART_1:
		Loc_strctSpiRegister = USART1_FIRST_ADDRESS;
		break;
	case USART_2:
		Loc_strctSpiRegister = USART2_FIRST_ADDRESS;
		break;
	case USART_3:
		Loc_strctSpiRegister = USART3_FIRST_ADDRESS;
		break;
	case USART_4:
		Loc_strctSpiRegister = USART4_FIRST_ADDRESS;
		break;
	default:
		return;
		break;
	}

	Loc_strctSpiRegister->DR = Copy_u8DataToTransmit;
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
 * Func. Name	: USART3_IRQHandler
 * Description	: This function calls the callback function giving it the received data and clears the interrupt flag
 */
void USART3_IRQHandler(void)
{
	/*Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (USART3_FIRST_ADDRESS->DR));
	}
}

/*
 * Func. Name	: USART4_IRQHandler
 * Description	: This function calls the callback function giving it the received data and clears the interrupt flag
 */
void USART4_IRQHandler(void)
{
	/*Call Callback Function*/
	if (Globptr_vdCallbackFunction)
	{
		Globptr_vdCallbackFunction((u8) (USART4_FIRST_ADDRESS->DR));
	}
}
