/************************************************************************/
/* SWC			: SPI Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Serial Peripheral Interface					*/
/************************************************************************/


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H


/*Private Macros*/
	/*SPI_CLK_PRE Options*/
#define SPI_FP_2	(0b000)
#define SPI_FP_4	(0b001)
#define SPI_FP_8	(0b010)
#define SPI_FP_16	(0b011)
#define SPI_FP_32	(0b100)
#define SPI_FP_64	(0b101)
#define SPI_FP_128	(0b110)
#define SPI_FP_256	(0b111)

	/*SPI_CPOL Options*/
#define SPI_IDLE_LOW		(0u)		/*CK to 0 when idle*/
#define SPI_IDLE_HIGH		(1u)		/*CK to 1 when idle*/

	/*SPI_CPHA Options*/
#define SPI_READ_AT_LEADING		(0u)	/*The first clock transition is the first data capture edge*/
#define SPI_WRITE_AT_LEADING	(1u)	/*The second clock transition is the first data capture edge*/

	/*Registers*/
#define SPI_CR1			(*((volatile u16*)0x40013000))
#define SPI_CR2			(*((volatile u16*)0x40013004))
#define SPI_SR			(*((volatile u16*)0x40013008))
#define SPI_DR			(*((volatile u16*)0x4001300C))
#define SPI_CRPR		(*((volatile u16*)0x40013010))
#define SPI_RXCRCR		(*((volatile u16*)0x40013014))
#define SPI_TXCRCR		(*((volatile u16*)0x40013018))
#define SPI_I2SCFGR		(*((volatile u16*)0x4001301C))
#define SPI_I2SPR		(*((volatile u16*)0x40013020))

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
