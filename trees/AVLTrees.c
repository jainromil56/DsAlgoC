#include <stdio.h>
#include <stdlib.h>

// Structure for Tree
struct Node{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
}*root=NULL;

// function for finding height of nodes
int NodeHeight(struct Node *p){
    // height of left subtree - hl , height of right subtree - hr
    int hl,hr;
    // checks p is not NULL and p->lchild is their = if both true take height of left subtree
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}

// Function for finding a balanced factor = height of left subtree - height of right subtree
int BalancedFactor(struct Node *p){
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;

    return hl-hr;
}

// LL-Rotation Function - returns pointer to a node
struct Node *LLRotation(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    // if root is at p, then root will move to new node pl
    if(root==p)
        root=pl;

    return pl;
}

// LR-Rotation Function - returns pointer to a node
struct Node *LRRotation(struct Node *p){
    struct Node *pl=p->lchild;
    struct Node *plr=pl->rchild;

    pl->rchild=plr->lchild;
    pl->lchild=plr->rchild;

    plr->lchild=pl;
    plr->rchild=p;

    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);

    if(root==p)
        root=plr;

    return plr;
}

// RL-Rotation Function - returns pointer to a node
struct Node *RLRotation(struct Node *p){
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    // switch
    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->rchild = pr;
    prl->lchild = p;

    // set height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root == p)
        root = prl;

    return prl;
}

// RR-Rotation Function - returns pointer to a node
struct Node *RRRotation(struct Node *p){
    struct Node *pr = p->rchild;
    struct Node *prr = pr->rchild;
    // switch
    pr->lchild = p;
    p->rchild = p->lchild;

    // set height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prr->height = NodeHeight(prr);

    if (root == p)
        root = pr;

    return pr;
}

// Recursive insert function
struct Node *RInsert(struct Node *p,int key){
    struct Node *t=NULL;

    // for inserting new node
    if(p==NULL){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        // height for single node not 0 take it as 1
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    // for inserting on either left child or right child
    if(key<p->data)
        p->lchild=RInsert(p->lchild,key);
    else if(key>p->data)
        p->rchild=RInsert(p->rchild,key);

    p->height=NodeHeight(p);

    // BalancedFactor(p) == 2 means heavy on LHS,BalancedFactor(p) == -2 means heavy on RHS, 
    if(BalancedFactor(p)==2 && BalancedFactor(p->lchild)==1)
        // perform LL-Rotation
        return LLRotation(p);
    else if(BalancedFactor(p)==2 && BalancedFactor(p->lchild)==-1)
        // preforms LR-Rotation
        return LRRotation(p);
    else if(BalancedFactor(p)==-2 && BalancedFactor(p->rchild)==-1)
        // preforms RR-Rotation
        return RRRotation(p);
    else if(BalancedFactor(p)==2 && BalancedFactor(p->lchild)==1)
        // preforms RL-Rotation
        return RLRotation(p);

    return p;
}

int main(){
// check this programs using printf() or breakpoint in XCODE
    // for RR-Rotation
    // root=RInsert(root,10);
    // RInsert(root,5);
    // RInsert(root,2);

    // for LR-Rotation
    root=RInsert(root,50);
    RInsert(root,10);
    RInsert(root,20);



    return 0;
}