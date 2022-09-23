#include "queue.h"

struct q_node{
    bst* data;
    q_node* next;
    q_node* prev;
};

struct queue{
    q_node* first;  //comeco da fila
    q_node* last;   //final da fila
};

q_node* new_q_node(bst* t){
    q_node* n = malloc(sizeof(q_node));
    if(n == NULL){
        perror("N IS NULL");
        exit(1);
    }
    n->data = t;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

queue*  new_queue(){
    queue* q = malloc(sizeof(queue));
    if(q == NULL){
        perror("Q IS NULL");
        exit(1);
    }
    q->first = NULL;
    q->last = NULL;
}
void    enqueue(queue* q, bst* t){
    if(q->first == NULL){
        q->last = q->first = new_q_node(t);
    }
    else{

        q_node* temp = q->last;
        q_node* n = new_q_node(t);
        q->last = n;
        n->next = temp;
        q->last = n;

    }
    return;
}
static  bst* getdata_q_node(q_node* q){
    return q->data;
}
bst*    dequeue(queue* q){
    if(q->first == NULL){
        return NULL;
    }
    else{
        q_node* temp = q->first;
        q->first = temp->prev;

        bst* a = getdata_q_node(temp);
        free(temp);
        return a;
    }
}
void    free_queue(queue* q){
    q_node* curr = q->last;
    while(curr != NULL){
        q_node* temp = curr;
        curr = curr->next;
        free(temp);
    }
}