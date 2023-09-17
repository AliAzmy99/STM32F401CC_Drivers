/************************************************************************/
/* SWC			: Seven Segment Driver									*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for Seven Segment Display							*/
/************************************************************************/


#ifndef SSEG_INTERFACE_H
#define SSEG_INTERFACE_H


/*Types Definitions*/
	/*Dot State Type*/
typedef enum
{
	SSEG_DOT_OFF,
	SSEG_DOT_ON
}DotState_type;

	/*Seven Segment Polarity Type*/
typedef enum
{
	SSEG_COMM_CATHODE,
	SSEG_COMM_ANODE
}Polarity_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Types Definitions*/
	/*Seven Segment Configuration Structure*/
typedef struct{
	PortId_type enmSegPortId;
		/*The port the seven segment is connected to*/
	PinId_type enmSegFirstPinId;
		/*The first pin that the seven segment is connected to*/
	Polarity_type enmPolarity;
		/*Polarity of seven segment*/
	PortId_type enmCommPortId;
		/*The port the seven segment common is connected to. Note: Set it to GPIO_NOT_A_PORT if the common is not connected to the mcu*/
	PinId_type enmCommPinId;
		/*The pin the seven segment common is connected to. Note: Set it to GPIO_NOT_A_PIN if the common is not connected to the mcu*/
}SsegConfig_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: SSEG_vdInit
 * Description	: This function allows the user to initialize the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 */
void SSEG_vdInit(const SsegConfig_type* Inprt_strctSsegConfig);

/* 
 * Func. Name	: SSEG_vdDisplayNumber
 * Description	: This function allows the user to display a number on the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_u8Number				Options: 0 -> 9
 * I/p Argument	: Copy_u8DotState			Options: DOT_OFF, DOT_ON
 */
void SSEG_vdDisplayNumber(const SsegConfig_type* Inprt_strctSsegConfig, u8 Copy_u8Number, u8 Copy_u8DotState);

/* 
 * Func. Name	: SSEG_vdClear
 * Description	: This function allows the user to clear the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 */
void SSEG_vdClear(const SsegConfig_type* Inprt_strctSsegConfig);

/* 
 * Func. Name	: SSEG_vdEnable
 * Description	: This function allows the user to enable or disable the seven segment display
 * I/p Argument	: Inprt_strctSsegConfig
 * I/p Argument	: Copy_enmEnable
 */
void SSEG_vdEnable(const SsegConfig_type* Inprt_strctSsegConfig, Enable_type Copy_enmEnable);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SSEG_INTERFACE_H*/
