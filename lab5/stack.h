#ifndef STACK
#define STACK

#define     MAX_STACK 48
typedef struct stack stack;
#include "item.h"

stack* stack_init();

void push(stack* p, int a);

int pop(stack* p);

int stack_empty(stack* p);

void stack_finish(stack* p);



#endif