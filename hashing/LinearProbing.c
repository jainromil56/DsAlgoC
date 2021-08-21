#include <stdio.h>
#define SIZE 10

// Note - 
    // To implement Quadratic probing just chane i to i*i everywhere

// function returns the key where we need to insert,search or delete element in range of 1 to 10
int hash(int key){
    return key%SIZE;
}

// Implementing formulae for linear probing - H`(x)=(H(x)+f(i))%10, where i=0,1,2...
// probe returns available space to insert key
// H[] - hashtable array
int probe(int H[], int key){
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=0)
        i++;
    return (index+i)%SIZE;
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
    // To implement Quadratic probing just chane i to i*i everywhere
    while(H[(index+i)%SIZE]!=key)
        i++;

    return (index+i)%SIZE;
}

int main(){
    int HT[10]={0};

    Insert(HT,12); //will insert at index 2 by formulae h(x)=h(x)%10 or H`(x)=(H(x)+f(i))%10, where i=0,1,2...
    Insert(HT,25); //will insert at index 5
    Insert(HT,35); //will insert at index 6
    Insert(HT,26); //will insert at index 7

    printf("\nKey found at index %d\n",Search(HT,35));
    return 0;
}