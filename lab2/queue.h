#ifndef     QUEUE
#define     QUEUE

#include "bst.h"

typedef struct queue queue;
typedef struct q_node q_node;

queue*  new_queue();
q_node* new_q_node(bst* t);
void    enqueue(queue* q, bst* t);
bst*    dequeue(queue* q);
void    free_queue(queue* q);

#endif