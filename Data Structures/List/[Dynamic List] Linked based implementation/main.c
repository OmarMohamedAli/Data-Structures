
#include <stdio.h>
#include <stdlib.h>
#include "Static_List.h"

void main()
{
	s32 value;
	List_t *ListPtr = (List_t *)malloc(sizeof(List_t));
	ListPtr -> size = 0;
	ListPtr -> head = NULL;
	//CreateList(stptr);
	
	InsertList(ListPtr,5, 0);
	RetrieveList(ListPtr,&value, 0);
	printf("Retrive value0 = %d \n",value);
	
	InsertList(ListPtr,10, 1);
	RetrieveList(ListPtr ,&value, 1);
	printf("Retrive value1 = %d \n",value);
	
	InsertList(ListPtr,15, 2);
	RetrieveList(ListPtr,&value, 2);
	printf("Retrive value2 = %d \n",value);
	/*
	InsertList(stptr,20, 3);
	//RetrieveList(stptr ,&value, 2);
	printf("Retrive value2 = %d \n",value);
	
	s32 size;
	ListSize(stptr, &size);
	printf("size = %d \n",size);
	*/
	/*
	InsertList(&MyList,15, 2);
	//RetrieveList(&MyList ,&value, 2);
	printf("Retrive value2 = %d \n",value);
	
	//InsertList(&MyList,20, 3);
	
	ListEmpty(&MyList);
	
	ListFull(&MyList);
	
	u32 size;
	ListSize(&MyList, &size);
	printf("size = %d \n",size);
	
	//DeleteList(&MyList ,&value ,2);
	//printf("value = %d \n",value);
	
	//DestroyList(&MyList);
	
	ListSize(&MyList, &size);
	printf("size = %d \n",size);
	*/
	
	
	
	/*
	InsertList(&MyList,5, 0);
	InsertList(&MyList,10, 1);
	InsertList(&MyList,15, 2);
	InsertList(&MyList,20, 4);
	InsertList(&MyList,25, 5);
	
	u32 size;
	ListSize(&MyList, &size);
	printf("size = %d \n",size);
	*/
	
}