
/*=========================================== Gaurd ========================================*/

#ifndef QUEUE_H_
#define QUEUE_H_ 

/*======================================== Inclusions ======================================*/

#include "Queue_Config.h"

/*==================================== Data Type Structure =================================*/

typedef struct queuenode{
	QUEUE_ENTRY entry;
	struct queuenode *next;
	}QueueNode;  
	
typedef struct queue{
	QueueNode *front;
	QueueNode *rear;
	int size;
	}Queue;  

/*==================================== Function Prototypes =================================*/


void Queue_Init(Queue *qp);
int Append(QUEUE_ENTRY e, Queue *qp);
void Serve(QUEUE_ENTRY *ep, Queue *qp);
int Is_Queue_Empty(Queue *qp);
int Is_Queue_Full(Queue *qp);
int Queue_Size(Queue *qp);
void Clear_Queue(Queue *qp);
void Traverse_Queue(Queue *qp, void (*fp)(QUEUE_ENTRY));

#endif