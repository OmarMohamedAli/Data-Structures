
#ifndef STATIC_LIST_H_
#define STATIC_LIST_H_

#include "List_Config.h"

typedef struct ListNode
{
	LIST_ENTRY entry;
	struct ListNode *next;
}ListNode_t;

typedef struct list
{
	ListNode_t *head;
	u32 size;
}List_t; 

Function_Status_t CreateList(List_t **ptr);
ListState_t ListEmpty(List_t *ptr);
ListState_t ListFull(List_t *ptr);
Function_Status_t ListSize(List_t *ptr, u32 *size_var);
Function_Status_t DestroyList(List_t *ptr);
Function_Status_t TraverseList(List_t *ptr , void(*fun)(LIST_ENTRY));
Function_Status_t InsertList(List_t **ptr , LIST_ENTRY e , s32 pos);
Function_Status_t DeleteList(List_t *ptr , LIST_ENTRY *ep , s32 pos);
Function_Status_t RetrieveList(List_t *ptr , LIST_ENTRY *ep , s32 p);
/*
Function_Status_t ReplaceList(List_t *ptr , LIST_ENTRY e , s32 p);

*/
#endif