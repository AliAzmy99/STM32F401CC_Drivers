/********************************************************************************************/
/* SWC			: USART Driver																*/
/* Author		: Ali Azmy																	*/
/* Version		: V0.0																		*/
/* Description	: SWC for Universal Synchronous Asynchronous Receiver Transmitter			*/
/********************************************************************************************/


#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

/*Types Definitions*/
	/*USART ID Type*/
typedef enum
{
	USART_1,
	USART_2,
	USART_3,
	USART_4,
	USART_NOT_AN_USART		/*Must remain the last element*/
}SpiId_type;

	/*USART Clk Prescaler Type*/
typedef enum
{
	USART_FP_2	= (0b000),	/*APB bus frequency / 2*/
	USART_FP_4	= (0b001),	/*APB bus frequency / 4*/
	USART_FP_8	= (0b010),	/*APB bus frequency / 8*/
	USART_FP_16	= (0b011),	/*APB bus frequency / 16*/
	USART_FP_32	= (0b100),	/*APB bus frequency / 32*/
	USART_FP_64	= (0b101),	/*APB bus frequency / 64*/
	USART_FP_128	= (0b110),	/*APB bus frequency / 128*/
	USART_FP_256	= (0b111),	/*APB bus frequency / 256*/
	USART_NOT_A_PRE		/*Must remain the last element*/
}SpiClkPre_type;

	/*USART Clk Polarity Type*/
typedef enum
{
	USART_IDLE_LOW,		/*CK to 0 when idle*/
	USART_IDLE_HIGH,		/*CK to 1 when idle*/
	USART_NOT_A_CPOL		/*Must remain the last element*/
}SpiCpol_type;

	/*USART Clk Phase Type*/
typedef enum
{
	USART_READ_AT_LEADING,		/*The first clock transition is the first data capture edge*/
	USART_WRITE_AT_LEADING,		/*The second clock transition is the first data capture edge*/
	USART_NOT_A_CPHA				/*Must remain the last element*/
}SpiCpha_type;

	/*Seven Segment Configuration Structure*/
typedef struct{
	True_type enmIsMaster;				/*Whether the USART is in Master mode*/
	
	SpiClkPre_type enmSpiClkPre;		/*The Prescaler for the USART Clk from its bus*/

	SpiCpol_type enmSpiCpol;			/*The USART Clk polarity*/
	SpiCpha_type enmSpiCpha;			/*The USART Clk phase*/
}SpiConfig_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: USART_vdInit
 * Description	: This function allows the user to initialize one of the USARTs
 * I/p Argument	: Copy_enmSpiId				: The USART to initialize
 * I/p Argument	: strctSpiConfig			: The USART config struct
 */
void USART_vdInit(SpiId_type Copy_enmSpiId, SpiConfig_type* strctSpiConfig);

/* 
 * Func. Name	: USART_voidMasterTranceive
 * Description	: This function allows the user to tranceive data when in master mode
 * I/p Argument	: Copy_enmSpiId				: The USART to use
 * I/p Argument	: Copy_enmSlavePortId		: The port of the pin used to select the slave
 * I/p Argument	: Copy_enmSlavePinId		: The pin used to select the slave
 * I/p Argument : Copy_u8DataToTransmit		: The data to be transmitted to the slave
 * O/p Argument : Outptr_DataRecieved		: The data received from the slave
 */
void USART_voidMasterTranceive(SpiId_type Copy_enmSpiId, PortId_type Copy_enmSlavePortId, PinId_type Copy_enmSlavePinId, u8 Copy_u8DataToTransmit, u8* Outptr_DataRecieved);

/* 
 * Func. Name	: USART_voidSlaveTranceive
 * Description	: This function allows the user to setup the USART for data tranceiving when in slave mode
 * I/p Argument	: Copy_enmSpiId						: The USART to use
 * I/p Argument	: Inptr_vdCallbackFunction			: Pointer to the function to be called when a transmission occurs
 * 				  									  It takes the received byte as an argument
 * I/p Argument : Copy_u8InitialDataToTransmit		: The data to be transmitted to the master during the first transmission
 */
void USART_voidSlaveTranceive(SpiId_type Copy_enmSpiId, void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data), u8 Copy_u8InitialDataToTransmit);

/* 
 * Func. Name	: USART_voidSlaveUpdateDataToTransmit
 * Description	: This function allows the user to update the data to be sent by the USART during the upcomming
 * 											  transmission when in slave mode
 * I/p Argument	: Copy_enmSpiId				: The USART to use
 * I/p Argument : Copy_u8DataToTransmit		: The data to be transmitted to the master during the next transmission
 */
void USART_voidSlaveUpdateDataToTransmit(SpiId_type Copy_enmSpiId, u8 Copy_u8DataToTransmit);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*USART_INTERFACE_H*/
