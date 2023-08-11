#ifndef STD_TYPES_H
#define STD_TYPES_H


/*Type Definitions*/
	/*Redefining Types for Portability and Conciseness*/
typedef unsigned char			u8;
typedef signed char				s8;

typedef unsigned short int		u16;
typedef signed short int		s16;

typedef unsigned long int		u32;
typedef signed long int			s32;

typedef unsigned long long int	u64;
typedef signed long long int	s64;

typedef float					f32;
typedef double					f64;
typedef long double				f128;

	/*Defining Different Error Types*/
typedef enum
{
	NO_ERROR,
	INVALID_PARAMETERS,
	INVALID_CONFIGS,
	NULL_POINTER_PASSED,
	FEATURE_NOT_ENABLED,
}ErrorStatus;
/*__________________________________________________________________________________________________________________________________________*/


#endif	/*STD_TYPES_H*/
