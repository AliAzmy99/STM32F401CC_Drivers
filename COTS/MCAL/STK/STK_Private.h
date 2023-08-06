/************************************************************************/
/* SWC  	    : STK Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for Reset and Clock Control						*/
/************************************************************************/


#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H


/*Private Macros*/
	/*STK_CLK_SRC Options*/
#define SRC_AHB			(1u)
#define SRC_AHB_DIV_8	(2u)

	/*Glob_u8IntervalFlag Options*/
#define INTERVAL_FLAG_SINGLE_MODE (0u)
#define INTERVAL_FLAG_PERIODIC_MODE (1u)

	/*Registers, STK First Address: 0xE000E010*/
#define STK_CTRL 			(*((volatile u32*)0xE000E010))
#define STK_LOAD 			(*((volatile u32*)0xE000E014))
#define STK_VAL 			(*((volatile u32*)0xE000E018))
#define STK_CALIB 			(*((volatile u32*)0xE000E01C))

    /*Bits*/
        /*STK_CTRL*/
#define STK_CTRL_ENABLE		(0u)
#define STK_CTRL_TICKINT	(1u)
#define STK_CTRL_CLKSOURCE	(2u)
#define STK_CTRL_COUNTFLAG	(16u)
/*__________________________________________________________________________________________________________________________________________*/


/*Private Global Variables Definitions*/
static void (* Globptr_vdCallbackFunction)(void) = NULL;
static u8 Glob_u8IntervalFlag = INTERVAL_FLAG_SINGLE_MODE;
/*__________________________________________________________________________________________________________________________________________*/


#endif /*STK_PRIVATE_H*/
