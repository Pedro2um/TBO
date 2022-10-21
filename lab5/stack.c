

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
struct stack{
	int s[MAX_STACK+1];
	int top_ptr;
};

stack* stack_init(){
	stack* n = calloc(1, sizeof(stack));
	if(n==NULL) exit(1);
	n->top_ptr = -1;
}

void push(stack* p, int a){
	if(p->top_ptr + 1 <= MAX_STACK) {	
		p->top_ptr++;
		p->s[p->top_ptr] = a;
	}
	else {
		perror("ERROR, STACK IS FULL!");
		exit(1);
	}
}

int pop(stack* p){
	if(p->top_ptr >= 0){
		p->top_ptr--;	
		return p->s[p->top_ptr+1];
	}
	else{ 
		perror("ERROR, STACK IS EMPTY!");
		exit(1);
	}
}

int stack_empty(stack* p){
	if(p->top_ptr == -1) return 1;
	return 0;	
}

void stack_finish(stack* p){
	p->top_ptr = -1;
}

