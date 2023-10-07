/************************************************************************/
/* SWC			: SPI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Serial Peripheral Interface					*/
/************************************************************************/


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


/*Private Macros*/
	/*Registers*/
#define SPI_CR1			(*((volatile u32*)0x40013000))
#define SPI_CR2			(*((volatile u32*)0x40013004))
#define SPI_SR			(*((volatile u32*)0x40013008))
#define SPI_DR			(*((volatile u32*)0x4001300C))
#define SPI_CRPR		(*((volatile u32*)0x40013010))
#define SPI_RXCRCR		(*((volatile u32*)0x40013014))
#define SPI_TXCRCR		(*((volatile u32*)0x40013018))
#define SPI_I2SCFGR		(*((volatile u32*)0x4001301C))
#define SPI_I2SPR		(*((volatile u32*)0x40013020))

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
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SPI_PRIVATE_H*/
