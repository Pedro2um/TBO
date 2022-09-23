
#include "stack.h"
//#include "bst.h"
struct stack{
        bst** data;
        int  MAX;
        int  top; // -1 if empty
};

stack*    new_stack(int size){
        stack* s = malloc(sizeof(stack));
        if(s == NULL){
                perror("NEW STACK POINTER IS NULL\n");
                exit(1);
        }
        s->data = malloc(size*getsize_bst());
        if(s->data == NULL){
                perror("ARRAY POINTER IS NULL\n");
                exit(1);
        }
        s->MAX = size;
        s->top = -1;
}
void    push(stack* s, bst* data){
        if(s->top + 1 == s->MAX){
                //perror("STACK IS FULL\n");
                //exit(1);
                return;
        }
        s->top += 1;
        s->data[s->top] = data;
}
bst*    top(stack* s){
        //return s->data[s->top];
        if(s->top == -1) return NULL;
        return s->data[s->top];
}
bst*    pop(stack* s){
        if(s->top == -1){
                //perror("STACK IS EMPTY");
                return NULL;
                //exit(1);
        }
        s->top -= 1;
        return s->data[s->top + 1];
}
void    free_stack(stack* s){
        free(s->data);
        free(s);
}

bool    empty_stack(stack* s){
        return s->top == -1;
}

