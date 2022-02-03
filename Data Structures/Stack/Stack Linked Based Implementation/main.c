#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void display(STACK_ENTRY e);

int main()
{
	Stack s;
	STACK_ENTRY e;
	Stack_Init(&s);
	printf("%d\n",is_stack_empty(&s));
    push(5, &s);
    push(10, &s);
    printf("%d\n",is_stack_empty(&s));
    push(15, &s);
    printf("%d\n",is_stack_empty(&s));
    //peak(&e, &s);
	printf("before pop :%d\n",e);
	pop(&e, &s);
	printf("after pop :%d\n",e);
	printf("stack size :%d\n",Stack_Size(&s));
	//Clear_Stack(&s);
	printf("stack size :%d\n",Stack_Size(&s));
	TraverseStack(&s, &display);
	
    return 0;
}


void display(STACK_ENTRY e){
    printf("e is :%d \n",e);
}