#ifndef     QUEUE
#define     QUEUE

#include "bst.h"
#include "stdlib.h"
#include <stdbool.h>
typedef struct queue queue;
typedef struct q_node q_node;

queue*  new_queue();
void    enqueue(queue* q, bst* t);
void    dequeue(queue* q);
bst*    front(queue* q);
bst*    back(queue* q);
void    travel_queue(queue* q);
bool    empty_queue(queue* q);
void    free_queue(queue* q);


#endif