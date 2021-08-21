#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

// dont focus on how create logic is working for now
void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for ( i = 1; i < n; i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void create2(int A[], int n){
    int i;
    struct Node *t, *last;
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];
    second->next=NULL;
    last=second;

    for ( i = 1; i < n; i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }   
}

int count(struct Node *p){
    int l=0;
    while (p)
    {
        l++;
        p=p->next;
    }
    return l;
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;

    if (index<0 || index>count(p))
    {
        return;
    }
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    if (index==0)
    {
        t->next=first;
        first=t;
    }else{
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
        
    }
    
}

void InsertLast(int x){
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node)); 
    t->data=x;
    t->next=NULL;
    if (first==NULL)
    {
        first=last=t;
    }else{
        last->next=t;
        last=t;
    }
    
}

void SortedInsert(struct Node *p, int x){
    struct Node *t,*q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    // if their is no element at all
    if (first==NULL)
    {
        first=t;
    }else{
        while (p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        // if x is the smallest element and p is staying on first only then we need to insert element on first only 
        if(p==first){
            t->next=first;
            first=t;
        }else{
            t->next=q->next;
            q->next=t;
        }
        
        
    }
    
}

void Display(struct Node *p){
    while (p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int Delete(struct Node *p, int index){
    struct Node *q=NULL;
    int x=-1,i;

    if (index<1 || index>count(p))
    {
        return -1;
    }
    if (index==1)
    {
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;
    }else{
        for (i = 0; i < index-1; i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

int isSorted(struct Node *p){
    int x=INT_MIN;
    while (p!=NULL)
    {
        if (p->data<x)
        {
            // returns 0 if not sorted
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    // returns 1 if sorted
    return 1;
}

void RemoveDuplicate(struct Node *p){
    struct Node *q=first->next;
    while (q!=NULL)
    {
        if (p->data!=q->data)
        {
            p=q;
            q=q->next;
        }else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
        
    }
    
}

// Reverse linked list using array
void ReverseUsingArray(struct Node *p){
    int *A,i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void ReverseUsingPointers(struct Node *p){
    struct Node *q=NULL,*r=NULL;
    while (p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q; 
}

void ReverseUsingRecursion(struct Node *q,struct Node *p){
    if(p!=NULL){
        ReverseUsingRecursion(p,p->next);
        p->next=q;
    }else{
        first=q;
    }
}

void Concat(struct Node *p, struct Node *q){
    third=p;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    q=NULL;
    
}

void Merge(struct Node *p,struct Node *q){
    struct Node *Last;
    if(p->data<q->data){
        third=Last=p;
        p=p->next;
        Last->next=NULL;
    }else{
        third=Last=q;
        q=q->next;
        Last->next=NULL;
    }
    while (p!=NULL && q!=NULL)
    {
        if (p->data<q->data)
        {
            Last->next=p;
            Last=p;
            p=p->next;
            Last->next=NULL;
        }else{
            Last->next=q;
            Last=q;
            q=q->next;
            Last->next=NULL;
        }
    }
    if (p!=NULL)
    {
        Last->next=p;
    }else{
        Last->next=q;
    }
}

// Checking whether linked list have a loop or not
int isLoop(struct Node *f){
    struct Node *p,*q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    } while (p && q && p!=q);
    return p==q?1:0;
    
}

int main(){
    int A[]={10,20,30,40,50};
    // int B[]={11,25,35,45,55};
    create(A,5); 
    // create2(B,5);

    //To make loop
    struct Node *t1,*t2;
    // t1 will point on 30
    t1=first->next->next; 
    // t2 will point on 50
    t2=first->next->next->next->next;
    // t2 from 50 will be pointing on t1 30
    t2->next=t1; 

    // Calling isLoop to check whether its a loop or not
    printf("%d\n",isLoop(first));

// all uses one array only
    // //calling delete/ uses create 
    // printf("Deleted Element %d\n",Delete(first,2));

    // // Calling isSorted to check if LinkedList is sorted or not
    // printf("%d\n",isSorted(first));

    // // Calling RemoveDuplicate - removes duplicate element in list // requires create function
    // RemoveDuplicate(first);

    // // Calling ReversUsingArray - Reverses nodes using arrays
    // ReverseUsingArray(first);

    // // Calling ReverseUsingPointers - Which reverse the pointers to reverse the linked list
    // ReverseUsingPointers(first);

    // // Calling ReverseUsingRecursion - which uses recursion to reverse Linked List
    // ReverseUsingRecursion(NULL,first);

    // // Calling Sorted insert //uses create //also create sorted linked list without create function
    // SortedInsert(first,55);
    // SortedInsert(first,25);

    // // calling Insert to make new array
    // Insert(first,0,10);
    // Insert(first,1,5); 
    // Insert(first,2,3); 
    // Insert(first,3,2); 

    // // Calling InsertLast to create new array - Inserts element on last
    // InsertLast(2);
    // InsertLast(3);
    // InsertLast(4);

// Uses 2 array
    // // Concat lists - Joins 2 list
    // Concat(first,second);

    // Calling Merge - Merges two sorted array in sorted array
    Merge(first,second);

    Display(first);
    printf("\n\n");
    Display(second);
    printf("\n\n");
    Display(third);
    return 0;
}