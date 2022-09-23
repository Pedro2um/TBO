#ifndef         STACK
#define         STACK
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "bst.h"
typedef struct stack stack;

stack*  new_stack(int size);
void    push(stack* s, bst* data);
bst*    top(stack* s);
bst*    pop(stack* s);
void    free_stack(stack* s);
bool    empty_stack(stack* s);

#endif