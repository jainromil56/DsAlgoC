//
//  main.c
//  MyFirst
//
//  Created by jromil 51 on 15/07/21.
//

#include <stdio.h>
#include <stdlib.h>

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    int i;
    printf("\n Elements are \n");
    for (i=0; i<arr.length; i++) {
        printf("%d \n", arr.A[i]);
    }
};

void Append(struct Array *arr, int x){
    if (arr->length<arr->size) {
        arr->A[arr->length++]=x;
    }
}

void insert(struct Array *arr,int index,int x){
    if (index>0 && index<=arr->length) {
        for (int i=arr->length; i>index; i--) {
            arr->A[i]=arr->A[i-1]; //shifting all elements forward
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int delete(struct Array *arr, int index){
    int x=0;
    if (index>=0 && index<=arr->length) {
        x=arr->A[index];
    
        for (int i=index; i<arr->length-1; i++) {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

void swap(struct Array *arr, int keyToBegining){
    int temp;
    temp = arr->A[0];
    arr->A[0]=arr->A[keyToBegining];
    arr->A[keyToBegining] = temp;
    
}

int LinearSearch(struct Array *arr,int key){
    for (int i=0; i<arr->length; i++) {
        if (key==arr->A[i]) {
            return i;
        }
    }
    return -1;
}

int BinSearch(struct Array arr,int key){
    int l,h,mid;
    l = 0;
    h = arr.length-1;
    while (l<=h)
    {
        mid=(l+h)/2;
        if (key==arr.A[mid])
        {
            return mid;
        }else if (key<arr.A[mid])
        {
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
        return -1;
}

int Get(struct Array arr,int index){
    if (index>=0 && index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
    
}

int Set(struct Array *arr,int index,int x){
    if (index>=0 && index<arr->length)
    {
        arr->A[index]=x;
    }
    return arr->A[index];
}

int Max(struct Array arr){
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr){
    int Total = 0;
    for (int i = 0; i < arr.length; i++)
    {
        Total += arr.A[i];
    }
    return Total;
}

int Avg(struct Array arr){
    return Sum(arr)/arr.length;
}

int Reverse(struct Array *arr){
    int *B;
    B = (int *)malloc(arr->length*sizeof(int));
    int i,j;
    for (i = arr->length-1,j=0; i>=0; i--,j++)
    {
        B[j] = arr->A[i];
    }
    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void InsertSort(struct Array *arr, int x){
    int i=arr->length-1;
    if (arr->length==arr->size)
    {
        return;
    }
    
    while (arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] =x;
    arr->length++;
}

int isSorted(struct Array arr){
    for (int i = 0; i < arr.length-1; i++)
    {
        if (arr.A[i]>arr.A[i+1])
        {
            return 0;
        }return 1;
        
    }
    
}

// void Swap(struct Array *arr,struct Array *arr1){
//     int temp = arr;
//     arr=arr1;
//     arr1=temp;

// }

// void Rearrange(struct Array *arr){
//     int i=0;
//     int j= arr->length-1;
//     while (arr->A[i]<0)
//     {
//         i++;
//     }
//     while (arr->A[j]>=0)
//     {
//         j--;
//     }
//     if (i<j)
//     {
//         Swap(&arr->A[i],&arr->A[j]);
//     }
    
    
// }

struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;

    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while (i<arr1->length && j<arr2->length)
    {
        if (arr1->A[i]<arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
        }else{
            arr3->A[k++]=arr2->A[j++];
        }
    }
        for (; i < arr1->length; i++)
        {
            arr3->A[k++]=arr1->A[i];
        }
        for (; j < arr2->length; j++)
        {
            arr3->A[k++]=arr2->A[j];
        }
        arr3->length=arr1->length+arr2->length;
        arr3->size=10;
        return arr3;
    
}

void MissingElement(struct Array arr){
    int max = Max(arr);
    struct Array arr1 = {{0},max,max};
    for (int i = 0; i < arr.length; i++)
    {
        arr1.A[arr.A[i]]++;
    }
    for (int j = 0; j <= max; j++)
    {
        if (arr1.A[j]==0)
        {
            printf("missing elements are %d\n",j);
        }
        
    }
}

void CountingDuplicates(struct Array arr){
    struct Array arr1 = {{0},Max(arr),Max(arr)};
    for (int i = 0; i < arr.length; i++)
    {
        arr1.A[arr.A[i]]++;
    }
    for (int j = 0; j < arr1.length; j++)
    {
        if (arr1.A[j]>1)
        {
            printf("%d is repeating %d times\n",j,arr1.A[j]);
        }
        
    }
    
    
    
}

int main() {
    struct Array arr = {{1,2,3,4,5,6},10,6};
    Append(&arr, 13);
    insert(&arr, 2, 10);
    delete(&arr, 1);
    printf("5 is on index %d \n",LinearSearch(&arr, 5));
    swap(&arr, LinearSearch(&arr, 3));
    printf("6 is on index %d\n\n",BinSearch(arr,6));

    printf("Get method %d\n",Get(arr,3));
    printf("Set method %d\n",Set(&arr,2,2));
    printf("Max method %d\n",Max(arr));
    printf("Min method %d\n",Min(arr));
    printf("Sum method %d\n",Sum(arr));
    printf("Avg method %d\n",Avg(arr));

// reversing elements in array
    struct Array arr1 = {{1,2,3,4,6,7,8,9},10,8};
    // Reverse(&arr1);
    InsertSort(&arr1,5 );
    printf("arr1 Array is %d",isSorted(arr1));
    display(arr1);

    struct Array arr2 = {{2,6,10,15,25},10,5};
    struct Array arr3 = {{3,4,7,18,20},10,5};
    struct Array *arr4;
    arr4 = Merge(&arr2, &arr3);
    display(*arr4);

    struct Array arr5 = {{3,4,7,9,10},10,5};
    // printf("arr5 missing elements are %d\n",MissingElement(arr5));
    MissingElement(arr5);

    struct Array arr6 = {{3,4,4,7,9,9,9,10},10,8};
    CountingDuplicates(arr6);

    display(arr);
    return 0;
}
