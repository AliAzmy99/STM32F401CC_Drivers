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
	USART_6,
	USART_NOT_AN_USART		/*Must remain the last element*/
}UsartId_type;

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
}UsartClkPre_type;

	/*USART Clk Polarity Type*/
typedef enum
{
	USART_STEADY_LOW,		/*CK to 0 when idle*/
	USART_STEADY_HIGH,		/*CK to 1 when idle*/
	USART_NOT_A_CPOL		/*Must remain the last element*/
}UsartCpol_type;

	/*USART Clk Phase Type*/
typedef enum
{
	USART_READ_AT_LEADING,		/*The first clock transition is the first data capture edge*/
	USART_WRITE_AT_LEADING,		/*The second clock transition is the first data capture edge*/
	USART_NOT_A_CPHA				/*Must remain the last element*/
}UsartCpha_type;

	/*Seven Segment Configuration Structure*/
typedef struct{
	True_type enmIsMaster;					/*Whether the USART is in Master mode*/
	
	UsartClkPre_type enmUsartClkPre;		/*The Prescaler for the USART Clk from its bus*/

	UsartCpol_type enmUsartCpol;			/*The USART Clk polarity*/
	UsartCpha_type enmUsartCpha;			/*The USART Clk phase*/
}UsartConfig_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/

/*__________________________________________________________________________________________________________________________________________*/


#endif /*USART_INTERFACE_H*/
