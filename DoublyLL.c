#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL; 

void create(int A[],int n){
    struct Node *t,*last;
    int i;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for (i = 1; i < n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
    
}

void Display(struct Node *p){
    while (p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int Length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    int i;

    // checks if index is valid or not
    if (index<0 || index>Length(p))
    {
        return;
    }

    // for inserting before first node
    if (index==0)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }else{
        // for inserting at any other position
        for (i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=x;

        t->prev=p;
        t->next=p->next;
        if (p->next)
        {
            p->next->prev=t;
        }
        p->next=t;
    }
    
}

int Delete(struct Node *p, int index){
    int x=-1,i;

    if (index<1 || index>Length(p))
    {
        return -1;
    }

    // for deleting first node
    if (index==1)
    {
        first=first->next;
        x=p->data;
        free(p);
        if (first)
        {
            first->prev=NULL;
        }
    }else{
    // for deleting any other index
        for (i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        p->prev->next=p->next;
        // checks if p's next exists or not
        if (p->next)
        {
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
    }
    return x;
}

void Reverse(struct Node *p){ 
    struct Node *q;
    while (p)
    {
        q=p->next;
        p->next=p->prev;
        p->prev=q;
        p=p->prev;
        if (p!=NULL && p->next==NULL)
        {
            first=p;
        }
        
    }
}

void MidNode1(struct Node *p){
    struct Node *q;
    q=p;
    q=q->next;
    while(q!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    printf("Reached at mid on %d \n",p->data);
}


int main(){
    int A[]={10,20,30,40,50};
    create(A,5);

    Insert(first,0,3);
    Delete(first,2);
    Reverse(first);

    printf("\nLength is :%d\n",Length(first));
    MidNode1(first);
    MidNode2(first);

    Display(first);

    return 0;
}