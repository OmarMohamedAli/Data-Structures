
#include <stdio.h>
#include <stdlib.h>
#include "Static_List.h"
/*
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
		ptr->head=NULL;
		ReturnValue = RET_OK;
	}
	return ReturnValue;
}

*/
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
		ReturnValue = LIST_NFULL;
		printf("List Not Full \n");
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
		ListNode_t *q;
		while(ptr->head)
		{
			q = ptr->head->next;
			free(ptr->head);
			ptr->head = q;
		}
		ptr->size = 0;
		printf("List is Destroyed\n");
		ReturnValue = RET_OK;
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
			ListNode_t *p = ptr->head;
			while(p)
			{
				(*fun)(p->entry);
				 p = p->next;
			}
			ReturnValue = RET_OK;
	}
	return ReturnValue;	
}



Function_Status_t InsertList(List_t *ptr , LIST_ENTRY e , s32 pos)    
{
	Function_Status_t ReturnValue;
	if(NULL == ptr)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		ListNode_t *p , *q;
		u32 i;
		p = (ListNode_t *)malloc(sizeof(ListNode_t));
		p->entry=e;
		p->next = NULL;
		
		if(0 == pos)
		{
			p->next = ptr->head;
			ptr->head = p;
		}
		else
		{
			for(q=ptr->head, i=0 ; i<pos-1 ; i++)
			{
				q=q->next;
			}
		}
		ptr->size++;
		ReturnValue = RET_OK;
	}
	return ReturnValue;
}



Function_Status_t DeleteList(List_t *ptr , LIST_ENTRY *ep , s32 pos)
{
	
	Function_Status_t ReturnValue;
	if(NULL == ptr || NULL == ep)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	} 
	else
	{
		s32 i;
		ListNode_t *q , *tmp;
		
		if(pos==0 || pos==1)
		{
			*ep = ptr->head->entry;
			tmp = ptr->head->next;
			free(ptr->head);
			ptr->head = tmp;
		}
		else
		{
			for(q=ptr->head, i=0 ; i<pos-1 ; i++)
			{
				q=q->next;
			}
			*ep = q->next->entry;
			tmp = q->next->next;
			free(q->next);
			q->next = tmp;
		}
		ptr->size--;
		ReturnValue = RET_NOK;
	}
	return ReturnValue;
}


Function_Status_t RetrieveList(List_t *ptr , LIST_ENTRY *ep , s32 pos) 
{
	
	Function_Status_t ReturnValue;
	if(NULL == ptr || NULL == ep)
	{
		printf("Error NULL Pointer\n");
		ReturnValue = RET_NOK;
	}
	else
	{
		s32 i;
		ListNode_t *q = ptr->head;
		while(q != NULL)
		{
			if(i == pos)
			{
				*ep = q->entry;
			}
			i++;
			q = q->next;
		}
		ReturnValue = RET_OK;
	}
	return ReturnValue;
}

	/*
	
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



*/


