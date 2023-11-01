/************************************************************************/
/* SWC			: SPI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Serial Peripheral Interface					*/
/************************************************************************/


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


/*Types Definitions*/
typedef struct
{
	u16 CR1;
	const u16 Reserved_1;
	u16 CR2;
	const u16 Reserved_2;
	u16 SR;
	const u16 Reserved_3;
	u16 DR;
	const u16 Reserved_4;
	u16 CRPR;
	const u16 Reserved_5;
	u16 RXCRCR;
	const u16 Reserved_6;
	u16 TXCRCR;
	const u16 Reserved_7;
	u16 I2SCFGR;
	const u16 Reserved_8;
	u16 I2SPR;
}SpiRegisters_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Private Macros*/
	/*Registers*/
#define SPI1_FIRST_ADDRESS	((volatile SpiRegisters_type*) 0x40013000)
#define SPI2_FIRST_ADDRESS	((volatile SpiRegisters_type*) 0x40013800)
#define SPI3_FIRST_ADDRESS	((volatile SpiRegisters_type*) 0x40013C00)
#define SPI4_FIRST_ADDRESS	((volatile SpiRegisters_type*) 0x40013400)

	/*Bits*/
		/*SPI_CR1*/
#define SPI_CR1_CPHA		(0u)
#define SPI_CR1_CPOL		(1u)
#define SPI_CR1_MSTR		(2u)
#define SPI_CR1_BR0			(3u)
#define SPI_CR1_BR1			(4u)
#define SPI_CR1_BR2			(5u)
#define SPI_CR1_SPE			(6u)
#define SPI_CR1_LSBFIRST	(7u)
#define SPI_CR1_SSI			(8u)
#define SPI_CR1_SSM			(9u)
#define SPI_CR1_RXONLY		(10u)
#define SPI_CR1_DFF			(11u)
#define SPI_CR1_CRCNEXT		(12u)
#define SPI_CR1_CRCEN		(13u)
#define SPI_CR1_BIDIOE		(14u)
#define SPI_CR1_BIDIMODE	(15u)
		/*SPI_CR2*/
#define SPI_CR2_RXNEIE		(6u)
#define SPI_CR2_TXEIE		(7u)
		/*SPI_SR*/
#define SPI_SR_RXNE		(0u)
#define SPI_SR_TXE		(1u)
#define SPI_SR_BSY		(7u)
/*__________________________________________________________________________________________________________________________________________*/


/*Private Global Variables Definitions*/
static void (* Globptr_vdCallbackFunction)(u8 Copy_u8Data) = NULL;	/*The callback function called when the master transmits data*/
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SPI_PRIVATE_H*/
