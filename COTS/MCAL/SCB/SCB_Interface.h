/************************************************************************/
/* SWC  	    : SCB Driver											*/
/* Author	    : Ali Azmy												*/
/* Version	    : V0.0													*/
/* Description  : SWC for System Control Block							*/
/************************************************************************/


#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H


/*Types Definitions*/
	/*Priority Grouping Type*/
typedef enum
{
	SCB_G16_SG01,		/*16 Group(s) and 01 Subgroup(s) in each*/
	SCB_G08_SG02,		/*08 Group(s) and 02 Subgroup(s) in each*/
	SCB_G04_SG04,		/*04 Group(s) and 04 Subgroup(s) in each*/
	SCB_G02_SG08,		/*02 Group(s) and 08 Subgroup(s) in each*/
	SCB_G01_SG16		/*01 Group(s) and 16 Subgroup(s) in each*/
}PriorityGrouping_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Public Functions Declarations*/
/* 
 * Func. Name	: SCB_vdSetNvicPriorityStructure
 * Description	: This function allows the user to control the priority grouping for the exception model
 * I/p Argument	: Copy_enmPriorityGrouping
 */
void SCB_vdConfigPriorityGrouping(PriorityGrouping_type Copy_enmPriorityGrouping);
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SCB_INTERFACE_H*/
