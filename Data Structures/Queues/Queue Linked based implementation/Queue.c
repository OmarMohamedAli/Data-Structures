#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
/*================================================================================*/
void Queue_Init(Queue *qp)
{
	qp->front = NULL ;
	qp->rear  = NULL;
	qp->size  = 0 ;
}


int Append(QUEUE_ENTRY value, Queue *qp)
{
	QueueNode *np = (QueueNode*)malloc(sizeof(QueueNode));
	if(!np)
		return -3;
	else
	{
		np->next = NULL;
		np->entry = value;
		if(!qp->rear)
			qp->front = np;
		else
			qp->rear->next = np;
		qp->rear = np;
		qp->size++;
	}
}

void Serve(QUEUE_ENTRY *ep, Queue *qp)
{
	QueueNode *np = qp->front;
	*ep = np->entry;
	qp->front = np->next;
	free(np);
	if(!qp->front)
		qp->rear = NULL;
	qp->size--;
}

int Is_Queue_Empty(Queue *qp)
{
	return !qp->size;
}

int Is_Queue_Full(Queue *qp)
{
	return -1;
}

int Queue_Size(Queue *qp)
{
	return qp->size;
}

void Clear_Queue(Queue *qp)
{
	while(qp->front)
	{
		qp->rear = qp->front->next;
		free(qp->front);
		qp->front = qp->rear;
	}
	qp->size = 0;
}

void Traverse_Queue(Queue *qp, void (*fp)(QUEUE_ENTRY))
{
	int pos, s;
	for(QueueNode *np = qp->front ; np ; np=np->next)
	{
		(*fp)(np->entry);
		
	}
}