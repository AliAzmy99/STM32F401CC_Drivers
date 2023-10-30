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
	SPI_4,
	SPI_NOT_AN_SPI		/*Must remain the last element*/
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
	SPI_FP_256	= (0b111),	/*APB bus frequency / 256*/
	SPI_NOT_A_PRE		/*Must remain the last element*/
}SpiClkPre_type;

	/*SPI Clk Polarity Type*/
typedef enum
{
	SPI_IDLE_LOW,		/*CK to 0 when idle*/
	SPI_IDLE_HIGH,		/*CK to 1 when idle*/
	SPI_NOT_A_CPOL		/*Must remain the last element*/
}SpiCpol_type;

	/*SPI Clk Phase Type*/
typedef enum
{
	SPI_READ_AT_LEADING,		/*The first clock transition is the first data capture edge*/
	SPI_WRITE_AT_LEADING,		/*The second clock transition is the first data capture edge*/
	SPI_NOT_A_CPHA				/*Must remain the last element*/
}SpiCpha_type;

	/*Seven Segment Configuration Structure*/
typedef struct{
	PortId_type enmMosiPortId;			/*The port of the MOSI pin*/
	PinId_type enmMosiPinId;			/*The MOSI pin*/
	AlternativeFunction_type enmMosiAf;	/*The MOSI pin alternative function*/

	PortId_type enmMisoPortId;			/*The port of the MISO pin*/
	PinId_type enmMisoPinId;			/*The MISO pin*/
	AlternativeFunction_type enmMisoAf;	/*The MISO pin alternative function*/
	
	PortId_type enmSckPortId;			/*The port of the SCK pin*/
	PinId_type enmSckPinId;				/*The SCK pin*/
	AlternativeFunction_type enmSckAf;	/*The SCK pin alternative function*/
	
	PortId_type enmNssPortId;			/*The port of the NSS pin*/
	PinId_type enmNssPinId;				/*The NSS pin*/
	AlternativeFunction_type enmNssAf;	/*The NSS pin alternative function*/

	True_type enmIsMaster;				/*Whether the SPI is in Master mode*/
	
	SpiClkPre_type enmSpiClkPre;		/*The Prescaler for the SPI Clk from its bus*/

	SpiCpol_type enmSpiCpol;			/*The SPI Clk polarity*/
	SpiCpha_type enmSpiCpha;			/*The SPI Clk phase*/
}SpiConfig_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/

/*__________________________________________________________________________________________________________________________________________*/


#endif /*SPI_INTERFACE_H*/
