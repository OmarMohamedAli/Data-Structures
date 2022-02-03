
/*=========================================== Gaurd ========================================*/

#ifndef STACK_H_
#define STACK_H_ 

/*======================================== Inclusions ======================================*/

#include "Stack_Config.h"

/*==================================== Data Type Structure =================================*/

typedef struct{
	STACK_ENTRY entry[MAX_STACK_SIZE];
	int top;
}Stack;  

/*==================================== Function Prototypes =================================*/

//Stack* Create_Stack();
void Stack_Init(Stack *sp);
int is_stack_empty(Stack *sp);
int is_stack_full(Stack *sp);
int push(STACK_ENTRY value, Stack *sp);
int pop(STACK_ENTRY *ep, Stack *sp);
int peak(STACK_ENTRY *ep, Stack *sp);
int Stack_Size(Stack *sp);
void Clear_Stack(Stack *sp);
void TraverseStack(Stack *sp, void (*fp)(STACK_ENTRY));


#endif