#include <stdio.h>
#include "Queue.h"


int main()
{
	Queue q;
	QUEUE_ENTRY e;
	Queue_Init(&q);
	Append(5, &q);
	Append(10, &q);
	Append(15, &q);
	Append(20, &q);
	Serve(&e, &q);
	printf("front %d \n",e);
	Serve(&e, &q);
	printf("front %d \n",e);
	Serve(&e, &q);
	printf("front %d \n",e);
	Serve(&e, &q);
	printf("front %d \n",e);
	

    return 0;
}

