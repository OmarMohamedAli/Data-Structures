#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
/*================================================================================*/
void Queue_Init(Queue *qp)
{
	qp->front = 0 ;
	qp->rear  = -1;
	qp->size  = 0 ;
}


void Append(QUEUE_ENTRY value, Queue *qp)
{
	if(qp->rear == MAX_QUEUE_SIZE-1)
		qp->rear=0;
	else
		qp->rear++;
	qp->entry[qp->rear]=value;
	qp->size++;
}

void Serve(QUEUE_ENTRY *ep, Queue *qp)
{
	*ep = qp->entry[qp->front];
	if(qp->front == MAX_QUEUE_SIZE-1)
		qp->front=0;
	else
		qp->front++;
	qp->size--;
}

int Is_Queue_Empty(Queue *qp)
{
	return !qp->size;
}

int Is_Queue_Full(Queue *qp)
{
	return (qp->size == MAX_QUEUE_SIZE);
}

int Queue_Size(Queue *qp)
{
	return qp->size;
}

void Clear_Queue(Queue *qp)
{
	qp->front = 0 ;
	qp->rear  = -1;
	qp->size  = 0 ;
}

void Traverse_Queue(Queue *qp, void (*fp)(QUEUE_ENTRY))
{
	int pos, s;
	for(pos = qp->front, s=0  ; s<qp->size ; s++)
	{
		(*fp)(qp->entry[pos]);
		pos = (pos+1)%MAX_QUEUE_SIZE;
	}
}