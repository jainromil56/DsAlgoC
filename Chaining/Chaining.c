#include <stdio.h>
#include <stdlib.h>
#include "chains.h"

int hash(int key){
    return key%10;
}

// *H[] array of pointer to a linked list
void Insert(struct Node *H[], int key){
    int index=hash(key);
    SortedInsert(&H[index],key);
}

int main(){

    struct Node *HT[10];
    struct Node *temp;
    int i;

    for(i=0;i<10;i++)
        HT[i]=NULL;

    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,42);

    // as search() returns a node structure so we need temp pointer
    // search for 22,12 or 42 , if you search 21 it won't get found
    temp=Search(HT[hash(22)],22);
    printf("%d ",temp->data);

    return 0;
}