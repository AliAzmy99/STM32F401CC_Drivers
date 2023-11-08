/************************************************************************/
/* SWC			: SPI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Serial Peripheral Interface					*/
/************************************************************************/


#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/*Types Definitions*/
	/*SPI ID Type*/
typedef enum
{
	SPI_1,
	SPI_2,
	SPI_3,
	SPI_4
}SpiId_type;

	/*SPI Clk Prescaler Type*/
typedef enum
{
	SPI_FP_2	= (0b000),	/*APB bus frequency / 2*/
	SPI_FP_4	= (0b001),	/*APB bus frequency / 4*/
	SPI_FP_8	= (0b010),	/*APB bus frequency / 8*/
	SPI_FP_16	= (0b011),	/*APB bus frequency / 16*/
	SPI_FP_32	= (0b100),	/*APB bus frequency / 32*/
	SPI_FP_64	= (0b101),	/*APB bus frequency / 64*/
	SPI_FP_128	= (0b110),	/*APB bus frequency / 128*/
	SPI_FP_256	= (0b111)	/*APB bus frequency / 256*/
}SpiClkPre_type;

	/*SPI Clk Polarity Type*/
typedef enum
{
	SPI_IDLE_LOW,		/*CK to 0 when idle*/
	SPI_IDLE_HIGH		/*CK to 1 when idle*/
}SpiCpol_type;

	/*SPI Clk Phase Type*/
typedef enum
{
	SPI_READ_AT_LEADING,		/*The first clock transition is the first data capture edge*/
	SPI_WRITE_AT_LEADING		/*The second clock transition is the first data capture edge*/
}SpiCpha_type;

	/*SPI Configuration Structure*/
typedef struct{
	True_type enmIsMaster;				/*Whether the SPI is in Master mode*/
	
	SpiClkPre_type enmSpiClkPre;		/*The Prescaler for the SPI Clk from its bus*/

	SpiCpol_type enmSpiCpol;			/*The SPI Clk polarity*/
	SpiCpha_type enmSpiCpha;			/*The SPI Clk phase*/
}SpiConfig_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: SPI_vdInit
 * Description	: This function allows the user to initialize one of the SPIs
 * I/p Argument	: Copy_enmSpiId				: The SPI to initialize
 * I/p Argument	: strctSpiConfig			: The SPI config struct
 */
void SPI_vdInit(SpiId_type Copy_enmSpiId, SpiConfig_type* strctSpiConfig);

/* 
 * Func. Name	: SPI_voidMasterTranceive
 * Description	: This function allows the user to tranceive data when in master mode
 * I/p Argument	: Copy_enmSpiId				: The SPI to use
 * I/p Argument	: Copy_enmSlavePortId		: The port of the pin used to select the slave
 * I/p Argument	: Copy_enmSlavePinId		: The pin used to select the slave
 * I/p Argument : Copy_u8DataToTransmit		: The data to be transmitted to the slave
 * O/p Argument : Outptr_DataRecieved		: The data received from the slave
 */
void SPI_voidMasterTranceive(SpiId_type Copy_enmSpiId, PortId_type Copy_enmSlavePortId, PinId_type Copy_enmSlavePinId, u8 Copy_u8DataToTransmit, u8* Outptr_DataRecieved);

/* 
 * Func. Name	: SPI_voidSlaveTranceive
 * Description	: This function allows the user to setup the SPI for data tranceiving when in slave mode
 * I/p Argument	: Copy_enmSpiId						: The SPI to use
 * I/p Argument	: Inptr_vdCallbackFunction			: Pointer to the function to be called when a transmission occurs
 * 				  									  It takes the received byte as an argument
 * I/p Argument : Copy_u8InitialDataToTransmit		: The data to be transmitted to the master during the first transmission
 */
void SPI_voidSlaveTranceive(SpiId_type Copy_enmSpiId, void (* Inptr_vdCallbackFunction)(u8 Copy_u8Data), u8 Copy_u8InitialDataToTransmit);

/* 
 * Func. Name	: SPI_voidSlaveUpdateDataToTransmit
 * Description	: This function allows the user to update the data to be sent by the SPI during the upcomming
 * 											  transmission when in slave mode
 * I/p Argument	: Copy_enmSpiId				: The SPI to use
 * I/p Argument : Copy_u8DataToTransmit		: The data to be transmitted to the master during the next transmission
 */
void SPI_voidSlaveUpdateDataToTransmit(SpiId_type Copy_enmSpiId, u8 Copy_u8DataToTransmit);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SPI_INTERFACE_H*/
