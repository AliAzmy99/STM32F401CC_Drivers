/************************************************************************/
/* SWC			: LEDMAT Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for LED Matrix									*/
/************************************************************************/


#ifndef LEDMAT_CONFIG_H
#define LEDMAT_CONFIG_H

/*Choosing Where the Matrix Pins are Connected*/
	/*Choosing Where the Column Pins are Connected*/
#define COLUMN_PORT				GPIO_PORT_A		/*Options: GPIO_PORT_A, GPIO_PORT_B*/
#define COLUMN_FIRST_PIN		GPIO_PIN_0		/*Options: GPIO_PIN_0 -> GPIO_PIN_8*/

	/*Choosing Where the Row Pins are Connected*/
#define ROW_PORT				GPIO_PORT_B		/*Options: GPIO_PORT_A, GPIO_PORT_B*/
#define ROW_FIRST_PIN			GPIO_PIN_0		/*Options: GPIO_PIN_0 -> GPIO_PIN_8*/
/*__________________________________________________________________________________________________________________________________________*/


/*Choosing Matrix Polarity*/
#define MATRTIX_POLARITY		CATHODE_AT_COLUMNS	/*Options: ANODE_AT_COLUMNS, CATHODE_AT_COLUMNS*/
/*__________________________________________________________________________________________________________________________________________*/


#endif /*LEDMAT_CONFIG_H*/
