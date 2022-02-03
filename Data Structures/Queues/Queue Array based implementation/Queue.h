
/*=========================================== Gaurd ========================================*/

#ifndef QUEUE_H_
#define QUEUE_H_ 

/*======================================== Inclusions ======================================*/

#include "Queue_Config.h"

/*==================================== Data Type Structure =================================*/

typedef struct queue{
	int front;
	int rear;
	int size;
	QUEUE_ENTRY entry[MAX_QUEUE_SIZE];
	}Queue;  

/*==================================== Function Prototypes =================================*/


void Queue_Init(Queue *qp);
void Append(QUEUE_ENTRY e, Queue *qp);
void Serve(QUEUE_ENTRY *ep, Queue *qp);
int Is_Queue_Empty(Queue *qp);
int Is_Queue_Full(Queue *qp);
int Queue_Size(Queue *qp);
void Clear_Queue(Queue *qp);
void Traverse_Queue(Queue *qp, void (*fp)(QUEUE_ENTRY));

#endif