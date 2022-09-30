#include "queue.h"
#define     MAX_QUEUE       (int)10000

struct queue{
   bst* arr[MAX_QUEUE];
   int rear;
   int front;
};

queue*  new_queue(){
    queue* q = malloc(sizeof(queue));
    if(q == NULL){
        perror("Q IS NULL");
        exit(1);
    }
    q->rear = 0;
    q->front = 0;
    return q;
}

void    enqueue(queue* q, bst* t){
    if(q->rear == MAX_QUEUE){
        perror("QUEUE IS FULL");
        return;
    }
    q->arr[q->rear] = t;
    q->rear++;
}
void    dequeue(queue* q){
    if(q->rear == q->front) {
        perror("QUEUE IS EMPTY");
        return;
    }
    //shift elements
    for (int i = 0; i < q->rear - 1; i++) {
        q->arr[i] = q->arr[i + 1];
    }
    q->rear--;
}
bst*    front(queue* q){
    if(q->front == q->rear) return NULL;
    return q->arr[q->front];
}
bst*    back(queue* q){
    if(q->front == q->rear) return NULL;
    return q->arr[q->rear];
}
bool    empty_queue(queue* q){
   if(q->front == q->rear) return true;
   return false;
}

void    travel_queue(queue* q){
   for(int i = 0; i < q->rear; i++){
        print(q->arr[i]);
   }
}

void    free_queue(queue* q){

   free(q);
}