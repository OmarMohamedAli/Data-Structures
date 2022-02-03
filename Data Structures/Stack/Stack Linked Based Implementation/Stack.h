
/*=========================================== Gaurd ========================================*/

#ifndef STACK_H_
#define STACK_H_ 

/*======================================== Inclusions ======================================*/

#include "Stack_Config.h"

/*==================================== Data Type Structure =================================*/

typedef struct stacknode{
	STACK_ENTRY entry;
	struct stacknode *next;
}StackNode;  

typedef struct stack{
	StackNode *top;
}Stack;  

/*==================================== Function Prototypes =================================*/

//Stack* Create_Stack();
void Stack_Init(Stack *sp);
int is_stack_empty(Stack *sp);
int is_stack_full(Stack *sp);
void push(STACK_ENTRY value, Stack *sp);
void pop(STACK_ENTRY *ep, Stack *sp);
//int peak(STACK_ENTRY *ep, Stack *sp);
int Stack_Size(Stack *sp);
void Clear_Stack(Stack *sp);
void TraverseStack(Stack *sp, void (*fp)(STACK_ENTRY));


#endif