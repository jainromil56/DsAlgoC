#include <stdio.h>
#define SIZE 10

// function returns the key where we need to insert,search or delete element in range of 1 to 10
int hash(int key){
    return key%SIZE;
}

// Implementing formulae for Quadratic probing - H`(x)=(H(x)+f(i*i))%10, where f(i)=i^2 or i*i, i=0,1,2...
// probe returns available space to insert key
// H[] - hashtable array
int probe(int H[], int key){
    int index=hash(key);
    int i=0;
    while(H[(index+i*i)%SIZE]!=0)
        i++;
    return (index+i*i)%SIZE;
}

void Insert(int H[], int key){
    int index=hash(key);
    if(H[index]!=0)
        // probe() will return available space to insert key
        index=probe(H,key);
    H[index]=key;
}

int Search(int H[], int key){
    int index=hash(key);
    int i=0;
    // if key not found on index then move and check further
    while(H[(index+i*i)%SIZE]!=key)
        i++;

    return (index+i*i)%SIZE;
}

int main(){
    int HT[10]={0};

    Insert(HT,12); //will insert at index 2 by formulae H`(x)=(H(x)+f(i*i))%10,where i=0,1,2...
    Insert(HT,25); //will insert at index 5
    Insert(HT,35); //will insert at index 6
    Insert(HT,45); //will insert at index 9
    Insert(HT,26); //will insert at index 7

    printf("\nKey found at index %d\n",Search(HT,45));
    return 0;
}