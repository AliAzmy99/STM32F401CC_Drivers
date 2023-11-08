/********************************************************************************************/
/* SWC			: USART Driver																*/
/* Author		: Ali Azmy																	*/
/* Version		: V0.0																		*/
/* Description	: SWC for Universal Synchronous Asynchronous Receiver Transmitter			*/
/********************************************************************************************/


#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H


/*Types Definitions*/
typedef struct
{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;
}UsartRegisters_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Private Macros*/
	/*Registers*/
#define USART1_FIRST_ADDRESS	((volatile UsartRegisters_type*) 0x40011000)
#define USART2_FIRST_ADDRESS	((volatile UsartRegisters_type*) 0x40004400)
#define USART6_FIRST_ADDRESS	((volatile UsartRegisters_type*) 0x40011400)

	/*Bits*/
		/*USART_CR1*/

		/*USART_CR2*/

		/*USART_SR*/

/*__________________________________________________________________________________________________________________________________________*/


/*Private Global Variables Definitions*/
static void (* Globptr_vdCallbackFunction)(u8 Copy_u8Data) = NULL;	/*The callback function called when data is received*/
/*__________________________________________________________________________________________________________________________________________*/


#endif /*USART_PRIVATE_H*/
