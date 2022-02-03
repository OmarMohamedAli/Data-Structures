
#include <stdio.h>
#include "Static_List.h"

Function_Status_t CreateList(List_t *ptr)
{
	Function_Status_t ReturnValue;
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		ptr->size=0;
		ReturnValue = RET_OK;
	}
	return ReturnValue;
}


ListState_t ListEmpty(List_t *ptr)
{
	ListState_t ReturnValue;
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
	}
	else
	{
		if( 0 == ptr->size)
		{
			ReturnValue = LIST_EMPTY;
			printf("List Empty \n");
		}
		else
		{
			ReturnValue = LIST_NEMPTY;
			printf("List Not Empty \n");
		}
	}
	return ReturnValue;
}


ListState_t ListFull(List_t *ptr)
{
	ListState_t ReturnValue;
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
	}
	else
	{
		if( MAX_LIST_SIZE == ptr->size)
		{
			ReturnValue = LIST_FULL;
			printf("List Full \n");
		}
		else
		{
			ReturnValue = LIST_NFULL;
			printf("List Not Full \n");
		}
	}
	return ReturnValue;
}

Function_Status_t ListSize(List_t *ptr, u32 *size_ptr)
{
	Function_Status_t ReturnValue;
	if(NULL == ptr || NULL == size_ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		*size_ptr = ptr->size;
		ReturnValue = RET_OK;
	}
	return ReturnValue;
}


Function_Status_t DestroyList(List_t *ptr)
{
	Function_Status_t ReturnValue;
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		ptr->size = 0;
		ReturnValue = RET_OK;
	}
	return ReturnValue;
	
}

Function_Status_t InsertList(List_t *ptr , LIST_ENTRY e , s32 p)     // problem (with->s32 [work]) and  (with->u32 [runtime error]) why!!!!!!!
{
	Function_Status_t ReturnValue;
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		if((p >= 0) && (p <= (ptr->size)))
		{
			s32 counter=0;
			for(counter = (ptr->size)-1 ; counter>=p ; counter--)
			{
				ptr->entry[counter+1] = ptr->entry[counter];
			
			}
			ptr->entry[p] = e;
			ptr->size++;
			ReturnValue = RET_OK;
		}
		else
		{
			printf("Error position Out of Renge\n");
			ReturnValue = RET_OUT_OF_RANGE;
		}
	}
	return ReturnValue;
}


Function_Status_t DeleteList(List_t *ptr , LIST_ENTRY *ep , s32 p)
{
	
	Function_Status_t ReturnValue;
	if(NULL == ptr || NULL == ep)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	} 
	else
	{
		if((p >= 0) && (p <= (ptr->size-1)))
		{
			s32 counter =0;
			*ep = ptr->entry[p];
			
			for(counter = p+1 ; counter<=ptr->size-1 ; counter++)
			{
				ptr->entry[counter-1] = ptr->entry[counter]; 
			}
			ptr->size--;
			ReturnValue = RET_OK;
		}
		else
		{
			printf("Error position Out of Renge\n");
			ReturnValue = RET_OUT_OF_RANGE;
		}
	}
	return ReturnValue;
}



Function_Status_t RetrieveList(List_t *ptr , LIST_ENTRY *ep , s32 p) 
{
	Function_Status_t ReturnValue;
	if(NULL == ptr || NULL == ep)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		if((p >= 0) && (p <= (ptr->size)))
		{
			*ep = ptr->entry[p];
			ReturnValue = RET_OK;
		}
		else
		{
			printf("Error position Out of Renge\n");
			ReturnValue = RET_OUT_OF_RANGE;
		}
	}
	return ReturnValue;
}
	
	
Function_Status_t ReplaceList(List_t *ptr , LIST_ENTRY e , s32 p)
{
	Function_Status_t ReturnValue;
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		if((p >= 0) && (p <= (ptr->size-1)))
		{
			ptr->entry[p] = e;
			ReturnValue = RET_OK;
		}
		else
		{
			printf("Error position Out of Renge\n");
			ReturnValue = RET_OUT_OF_RANGE;
		}
	}
	return ReturnValue;	
} 

Function_Status_t TraverseList(List_t *ptr , void(*fun)(LIST_ENTRY))
{
	Function_Status_t ReturnValue;
	if(NULL == ptr || NULL == fun)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
			u32 counter;
			for(counter=0 ; counter<ptr->size ; counter++)
			{
				(*fun)(ptr->entry[counter]);
			}
			ReturnValue = RET_OK;
	}
	return ReturnValue;	
}





