#ifndef Queue_h
#define Queue_h
#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

// for initialization/creating of a queue
void create(struct Queue *q, int size){
    q->size = size;
    // q->front = q->rear = -1;
    // for circular queue
    q->front = q->rear = 0;
    q->Q = (struct Node**)malloc(q->size*sizeof(struct Node*));
}

// Inserts element in queue
void enqueue(struct Queue *q,struct Node *x){
    if(q->rear==q->size-1){
        printf("Queue is full\n");
    }else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

// Removes element from queue
struct Node* dequeue(struct Queue *q){
    struct Node* x=NULL;
    if(q->front==q->rear){
        printf("Queue is Empty\n");
    }else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front==q.rear;
}

#endif /* Queue_h */