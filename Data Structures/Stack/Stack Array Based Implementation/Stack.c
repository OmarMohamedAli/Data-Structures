#include <stdio.h>
#include "Stack.h"
/*================================================================================*/
void Stack_Init(Stack *sp)
{
	sp->top = -1;
}
/*================================================================================*/
int is_stack_full(Stack *sp)
{
    if(sp->top == (MAX_STACK_SIZE-1))
        return 0;
    else
        return -1;
}

/*================================================================================*/

int is_stack_empty(Stack *sp)
{
    if(sp->top == -1)
        return 0;  // Stack Underflow
    else
        return -2;
}

/*================================================================================*/

int push(STACK_ENTRY value, Stack *sp)
{
    if(!is_stack_full(sp))
        return -1;
    else
    {
        sp->top++;
        sp->entry[sp->top]=value;
		return 0;
    }
}
 
 /*================================================================================*/

int pop(STACK_ENTRY *ep, Stack *sp)
{
    if(!is_stack_empty(sp))
        return -2;
    else
		*ep = sp->entry[sp->top];
	    sp->top--;
        return 0;
}

/*================================================================================*/
int peak(STACK_ENTRY *ep, Stack *sp)
{
    if(!is_stack_empty(sp))
        return -2;
    else
        *ep = sp->entry[sp->top];
		return 0;
}

/*================================================================================*/
int Stack_Size(Stack *sp)
{
	return (sp->top)+1;
}

/*================================================================================*/
void Clear_Stack(Stack *sp)
{
	sp->top = -1;
}

/*================================================================================*/
void TraverseStack(Stack *sp, void (*fp)(STACK_ENTRY))
{
	for(int i=sp->top; i>=0; i--)
        {
            (*fp)(sp->entry[i]);
        }
	
}
