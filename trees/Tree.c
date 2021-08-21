#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node *root=NULL;

// function for creating a tree
void Tcreate(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);

    printf("Enter root value ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isEmpty(q)){
        p=dequeue(&q);

        // for left child of p
        printf("enter left child of %d ",p->data);
        scanf("%d",&x);
        if (x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }

        // for right child of p
        printf("enter right child of %d ",p->data);
        scanf("%d",&x);
        if (x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
        
    }
}

// for displaying elements of tree we have preorder traversal function
void preorder(struct Node *p){
    if(p){
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ",p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ",p->data);
    }
}

int main(){
    Tcreate();
    preorder(root);
    printf("\nPost Order ");
    Postorder(root);
    return 0;
}