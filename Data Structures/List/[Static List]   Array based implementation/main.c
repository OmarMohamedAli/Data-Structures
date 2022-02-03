
#include <stdio.h>
#include "Static_List.h"

void main()
{
	List_t MyList;
	CreateList(&MyList);
	
	InsertList(&MyList,5, 0);
	InsertList(&MyList,10, 1);
	InsertList(&MyList,15, 2);
	InsertList(&MyList,20, 4);
	InsertList(&MyList,25, 5);
	
	u32 size;
	ListSize(&MyList, &size);
	printf("size = %d \n",size);
	
	
}