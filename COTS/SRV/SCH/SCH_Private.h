/************************************************************************/
/* SWC			: SCH Driver											*/
/* Author		: Ali Azmy												*/
/* Version		: V0.0													*/
/* Description	: SWC for scheduler										*/
/************************************************************************/


#ifndef SCH_PRIVATE_H
#define SCH_PRIVATE_H


/*Private Macros*/

/*__________________________________________________________________________________________________________________________________________*/

/*Types Definitions*/
	/*Task Structure*/
typedef struct{
	u8 u8Priority;
		/*description							Options: */
	u32 u32Periodicity;
		/*description							Options: */
	u8 u8FirstDelay;
		/*description							Options: */
	void (* vdTaskFunction)(void);
		/*description							Options: */
}SchTask_type;
/*__________________________________________________________________________________________________________________________________________*/


/*Private Global Variables Definitions*/
static SchTask_type Glob_strctTaskArray[MAX_NO_TASKS];
/*__________________________________________________________________________________________________________________________________________*/


#endif /*SCH_PRIVATE_H*/
