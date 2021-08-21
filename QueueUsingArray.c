#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

// for initialization/creating of a queue
void create(struct Queue *q, int size){
    q->size = size;
    // q->front = q->rear = -1;
    // for circular queue
    q->front = q->rear = 0;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

// Inserts element in queue
void enqueue(struct Queue *q,int x){
    if(q->rear==q->size-1){
        printf("Queue is full\n");
    }else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

// Inserts element in circular queue
void Cenqueue(struct Queue *q,int x){
    if((q->rear+1)%q->size == q->front){
        printf("Queue is full\n");
    }else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}

// Removes element from queue
int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear){
        printf("Queue is Empty\n");
    }else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}


// Removes element from Circular queue
int Cdequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear){
        printf("Queue is Empty\n");
    }else{
        // move front pointer for deleting element
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}

// Displays queue
void Display(struct Queue q){
    int i;
    for (i=q.front+1; i<=q.rear; i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
    
}

// Displays circular queue
void CDisplay(struct Queue q){
    // as where front is pointing is emptied
    int i=q.front+1;
    do
    {
        printf("%d ",q.Q[i]);
        // for incrementng i in circular array
        i=(i+1)%q.size;
    } while (i!=(q.rear+1)%q.size);
    
    printf("\n");
    
}

int main()
{
    struct Queue q;
    create(&q,5);
    
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    Display(q);
    printf("%d \n",dequeue(&q));
    Display(q);
    
    
    // for circulat queue
    struct Queue c;
    create(&c,5);

    Cenqueue(&c,10);
    Cenqueue(&c,20);
    Cenqueue(&c,30);
    Cenqueue(&c,40);
    CDisplay(c);
    printf("%d \n",Cdequeue(&c));
    CDisplay(c);

    return 0;
}