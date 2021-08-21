#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ArraySize(int *A){
    return sizeof(A)/sizeof(int);
}

int main()
{
    int A[5] = {1,2,3,4,5};
    int size = ArraySize(A);
    printf("%d",sizeof(A)/sizeof(int));
    // int k = 2;
    // int *ptr = &k;
    // printf("The address of variable k is %u \n",&k);
    // printf("The value of variable k is %u \n",*ptr);
     return 0;
}