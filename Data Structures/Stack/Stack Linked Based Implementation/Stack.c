#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
/*================================================================================*/
void Stack_Init(Stack *sp)
{
	sp->top = NULL;
}

/*================================================================================*/
void push(STACK_ENTRY value, Stack *sp)
{
    StackNode *np = (StackNode*)malloc(sizeof(StackNode));
	np->entry = value;
	np->next = sp->top;
	sp->top = np;
}

/*================================================================================*/
void pop(STACK_ENTRY *ep, Stack *sp)
{
    *ep = sp->top->entry;
    StackNode *np;
    np = sp->top;
    sp->top = sp->top->next;
    free(np);
}

/*================================================================================*/
int is_stack_empty(Stack *sp)
{
    if(sp->top == NULL)
        return 0;  // Stack Underflow
    else
        return -2;
}

/*================================================================================*/
int is_stack_full(Stack *sp)
{
    return -1;
}

/*================================================================================*/
void Clear_Stack(Stack *sp)
{
    StackNode *np = sp->top;
    StackNode *nq = sp->top;
    while(np)
    {
        np = np->next;
        free(nq);
        nq=np;
    }
	sp->top = NULL;
}

/********** another Implementation to Clear_Stack Function ****************************

void Clear_Stack(Stack *sp)
{
    StackNode *np = sp->top;
    while(np)
    {
        np = np->next;
        free(sp->top);
        sp->top = np;
    }
}*/

/*================================================================================*/
void TraverseStack(Stack *sp, void (*fp)(STACK_ENTRY))
{
    StackNode *np = sp->top;
	while(np)
        {
            (*fp)(np->entry);
            np = np->next;
        }
}

/********** another Implementation to TraverseStack Function ****************************
void TraverseStack(Stack *sp, void (*fp)(STACK_ENTRY))
{
    for(StackNode *np = sp->top ; np ; np=np->next)
    {
        (*fp)(np->entry);
    }
}*/

/*================================================================================*/
int Stack_Size(Stack *sp)
{
	int x;
	StackNode *np = sp->top;
	for(x=0 ; np ; np=np->next)
        x++;
	return x;
}
