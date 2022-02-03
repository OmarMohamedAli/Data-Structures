
#ifndef Error_States_H_
#define Error_States_H_


#include "std_types.h"


typedef enum 
{
	LIST_EMPTY,
	LIST_NEMPTY,
	LIST_FULL,
	LIST_NFULL
}ListState_t;


typedef enum
{
	RET_OK,
	RET_NOK,
	RET_NULL_PTR,
	RET_OUT_OF_RANGE
}Function_Status_t;







#endif