#include <stdio.h>
#include <stdlib.h>

// function for inserting element in heap
void Insert(int A[],int n){
    int i=n,temp;
    temp=A[i];
    while (i>1 && temp>A[i/2])
    {
        A[i]=A[i/2];
        i=i/2;
    }
    // temp value gets stored where i pointer stops
    A[i]=temp;
}

// Delete function for heap
int Delete(int A[], int n){
    int x,i,j,val,temp;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;
    i=1;
    // left child
    j=i*2;

    // continues untill last index of heap
    while(j<n-1){
        if(A[j+1]>A[j])
            j=j+1;

        if(A[i]<A[j]){
            // swaps elements
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;

            i=j;
            j=2*j;
        }else{ 
            break; 
        }
    }
    // copy deleted element in freespace i.e. last
    return val;
}

int main(){
    int A[] = {0,10,20,30,25,5,40,35};
    int i;
    for (i = 2; i <= 7; i++)
        Insert(A,i);
    
    for(i=7;i>1;i--)
        printf("Deleted value is %d\n",Delete(A, i));
    
    for (i = 1; i <= 7; i++)
        printf("%d ", A[i]);
    printf("\n");

    return 0;
}