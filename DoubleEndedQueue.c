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
void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

// Displays queue
void Display(struct Queue q){
    int i;
    // here if we do i<=q.rear then it will also show empty index's adress 
    for (i=q.front; i!=q.rear; i++)
    {
        printf("%d ",q.Q[i]);
    }
    printf("\n");
    
}

// for inserting from front 
void InsertFromFront(struct Queue *q, int x)
{
    if (q->rear == q->size)
    {
        printf("Queue is Full\n");
    }else if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->Q[q->rear] = x;
        q->rear = q->rear + 1;
    }else{
        q->Q[q->front-1] = x;
        q->front = q->front - 1;
    }
}

// for deleting from front
void DeleteFromFront(struct Queue *q)
{
    // Checks for empty array
    if (q->rear == -1 && q->front == -1 || q->front == q->rear)
    {
        printf("Queue is Empty\n");
        q->front = -1;
        q->rear = -1;
    }else{
        printf("%d has been deleted from queue\n", q->Q[q->front]);
        q->front = q->front + 1;
    }
}

// for Inserting from rear
void InsertFromRear(struct Queue *q, int x)
{
    if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->Q[q->rear] = x;
        q->rear = q->rear + 1;
    }
    else if (q->rear == q->size)
    {
        printf("Queue is Full\n");
    }
    else
    {
        // first assign value to x and then move rear pointer
        q->Q[q->rear] = x;
        q->rear = q->rear + 1;
    }
}

// for deleting from rear
void DeleteFromRear(struct Queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        printf("Queue is Empty");
    }else
    {
        if (q->rear <= q->front)
        {
            printf("Queue is Empty");
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            printf("%d has been deleted from queue\n", q->Q[q->rear-1]);
            q->rear = q->rear - 1;
            // q->size = q->size - 1;
        }
    }
}

int main()
{
    struct Queue q;
    create(&q,10);

    printf("Inserted from front\n");
    InsertFromFront(&q,1);
    InsertFromFront(&q,2);
    InsertFromFront(&q,3);
    InsertFromFront(&q,4);
    Display(q);
    
    printf("Deleted from front\n");
    DeleteFromFront(&q);
    DeleteFromFront(&q);
    Display(q);

    printf("Inserted from Rear\n");
    InsertFromRear(&q,5);
    InsertFromRear(&q,6);
    InsertFromRear(&q,7);
    InsertFromRear(&q,8);
    Display(q);

    printf("Deleted from Rear\n");
    DeleteFromRear(&q);
    DeleteFromRear(&q);
    Display(q);

    // why I can't insert from front
    InsertFromFront(&q,1);
    InsertFromFront(&q,2);
    InsertFromFront(&q,3);
    InsertFromFront(&q,4);
    InsertFromFront(&q,5);
    printf("Inserted 1,2,3,4,5 from front\n");
    Display(q);

    return 0;
}