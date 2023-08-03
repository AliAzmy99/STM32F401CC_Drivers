/************************************************************************/
/* SWC  	    : GPIO Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.1													*/
/* Description  : SWC for General-Purpose I/Os 							*/
/************************************************************************/


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/*Public Macros*/
	/*Port ID Options*/
#define GPIO_PORT_A		(0u)
#define GPIO_PORT_B		(1u)
#define GPIO_PORT_C		(2u)

	/*Pin ID Options*/
#define GPIO_PIN_0		(0u)
#define GPIO_PIN_1		(1u)
#define GPIO_PIN_2		(2u)
#define GPIO_PIN_3		(3u)
#define GPIO_PIN_4		(4u)
#define GPIO_PIN_5		(5u)
#define GPIO_PIN_6		(6u)
#define GPIO_PIN_7		(7u)
#define GPIO_PIN_8		(8u)
#define GPIO_PIN_9		(9u)
#define GPIO_PIN_10		(10u)
#define GPIO_PIN_11		(11u)
#define GPIO_PIN_12		(12u)
#define GPIO_PIN_13		(13u)
#define GPIO_PIN_14		(14u)
#define GPIO_PIN_15		(15u)

	/*Mode ID Options*/
#define GPIO_Mode_INPUT		(0u)
#define GPIO_Mode_OUTPUT	(1u)
#define GPIO_Mode_ALT_FUN	(2u)
#define GPIO_MODE_ANALOG	(3u)

	/*Output Type ID Options*/
#define GPIO_OUTPUT_TYPE_PP		(0u)	/*Output push-pull*/
#define GPIO_OUTPUT_TYPE_OD		(1u)	/*Output open-drain*/

	/*Output Speed ID Options*/
#define GPIO_OUTPUT_SPEED_L		(0u)	/*Low speed*/
#define GPIO_OUTPUT_SPEED_M		(1u)	/*Medium speed*/
#define GPIO_OUTPUT_SPEED_H		(2u)	/*High speed*/
#define GPIO_OUTPUT_SPEED_VH	(3u)	/*Very High speed*/

	/*Pull Type ID Options*/
#define GPIO_NO_PULL		(0u)	/*No pull (floating)*/
#define GPIO_PULL_UP		(1u)	/*Pull-up*/
#define GPIO_PULL_DOWN		(2u)	/*Pull-down*/

	/*Value ID Options*/
#define GPIO_VALUE_L		(0u)	/*Low*/
#define GPIO_VALUE_H		(1u)	/*High*/

	/*Action ID Options*/
#define GPIO_SET		(0u)	/*Set*/
#define GPIO_RST		(1u)	/*Reset*/
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
ErrorStatus GPIO_errSetPinMode(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinMode);
ErrorStatus GPIO_errSetPinOutputType(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinType);
ErrorStatus GPIO_errSetPinOutputSpeed(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinSpeed);
ErrorStatus GPIO_errSetPinValue(u8 Copy_u8PortId, u8 Copy_u8PinId, u8 Copy_u8PinValue);

/*__________________________________________________________________________________________________________________________________________*/


#endif /*GPIO_INTERFACE_H*/
