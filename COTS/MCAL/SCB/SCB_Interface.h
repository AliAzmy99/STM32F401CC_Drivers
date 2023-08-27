/************************************************************************/
/* SWC  	    : SCB Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Control Block							*/
/************************************************************************/


#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H


/*Public Macros*/
	/*Group and Subgroup ID Options*/
#define SCB_G16_SG01	(0u)		/*16 Group(s) and 01 Subgroup(s) in each*/
#define SCB_G08_SG02	(1u)		/*08 Group(s) and 02 Subgroup(s) in each*/
#define SCB_G04_SG04	(2u)		/*04 Group(s) and 04 Subgroup(s) in each*/
#define SCB_G02_SG08	(3u)		/*02 Group(s) and 08 Subgroup(s) in each*/
#define SCB_G01_SG16	(4u)		/*01 Group(s) and 16 Subgroup(s) in each*/
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: SCB_errSetNvicPriorityStructure
 * Description	: This function allows the user to choose the number of priority groups and subgroups the for the NVIC
 * I/p Argument	: Copy_u8PriorityStructure		Options: SCB_G16_SG01, SCB_G08_SG02, SCB_G04_SG04, SCB_G02_SG08, SCB_G01_SG16
 * Return		: Error status of function
 */
ErrorStatus SCB_errSetNvicPriorityStructure(u8 Copy_u8PriorityStructure);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SCB_INTERFACE_H*/
