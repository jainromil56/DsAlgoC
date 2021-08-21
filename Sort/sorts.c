#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble sort function
void Bubble(int A[], int n)
{
    int i, j, flag = 0;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
                flag = 1;
        }
        if (flag == 0)
            break;
    }
}

// Insertion sort function
void InsertionSort(int A[], int n){
    int x,i,j;
    for (i = 1; i < n; i++)
    {
        j=i-1;
        x=A[i];
        while (j>-1 && A[j]>x)
        {
            // for shifting elements
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
    
}

// function for selection sort
void SelectionSort(int A[],int n){
    int i,j,k;
    for (i=0; i<n-1; i++)
    {
        for (j=k=i; j<n; j++)
        {
            if (A[j]<A[k])
                k=j;
        }
        swap(&A[i],&A[k]);
    }
}

// Quick sort - partition function
int Partition(int A[],int l,int h){
    int pivot = A[l];
    int i=l,j=h;

    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if (i<j)
        {
            swap(&A[i],&A[j]);
        }
        
    } while (i<j);
    swap(&A[l],&A[j]);
    return j;
}

// recursive quick sort function
void QuickSort(int A[],int l,int h){
    int j;
    if(l<h){
        j=Partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

// Merge sort function
void Merge(int A[], int l, int mid, int h){
    // l is low, mid is mid and h is high of array A[]
    int i=l, j=mid+1, k=l;
    int B[h+1]; //or B[100]
    while(i<=mid && j<=h){
        if (A[i]<A[j])
        {
            B[k++]=A[i++];
        }else{
            B[k++]=A[j++];
        }
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<=h;j++)
        B[k++]=A[j];

    // for copying all elements from B to A
    for (i=l; i<=h; i++) 
        A[i]=B[i];
}

// Iterative merge sort, n- number of elements in Arrar A[]
void IMergeSort(int A[], int n){
    int p,l,mid,h,i;
    // p for passes and p will be moving by p*2 i.e. 2,4,8...
    for (p=2; p<=n; p=p*2)
    {
        // for merging all list
        for (i=0; i+p-1<n; i=i+p)
        {
            l=i;
            h=i+p-1;
            mid= (l+h)/2;
            Merge(A,l,mid,h);
        }
        if(n-i>p/2){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A, l, mid, n-1);
        }
    }

    // for odd number of elements in array
    if(p/2<n)
        Merge(A,0,p/2-1,n-1);
    
}


// Recursive mergesort 
void MergeSort(int A[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        MergeSort(A,l,mid);
        MergeSort(A,mid+1,h);
        Merge(A,l,mid,h);

    }
}

// returns max value in an array
int findMax(int A[],int n){
    int max=INT_MIN;
    int i;
    for(i=0;i<n;i++){
        if(A[i]>max)
            max=A[i];
    }
    return max;
}

// count sort
void CountSort(int A[],int n){
    int i,j,max,*c;

    max=findMax(A,n);
    // max+1 becoz array starts from 0
    c=(int *)malloc(sizeof(int)*(max+1));

    for(i=0;i<max+1;i++)
        c[i]=0;

    for(i=0;i<n;i++)
        c[A[i]]++;

    i=0;
    j=0;
    while(i<max+1){
        if(c[i]>0){
            A[j++]=i;
            c[i]--;
        }else{
            i++;
        }
    }
}

// Shell Sort
void ShellSort(int A[], int n){
    int gap,i,j,temp;

    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp){
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;

    // count sort
    // CountSort(A,n);
    
    // Shell Sort
    ShellSort(A,n);

    // for Quick sort
    // int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3,INT_MAX}, n = 11, i;
    // QuickSort(A,0,10);

    // Bubble(A, n);

    // calling insertionsort function
    // InsertionSort(A,n);

    // calling selection sort
    // SelectionSort(A,n);

    // Calling ImergeSort
    // IMergeSort(A,n);

    // Calling MergeSort function
    // MergeSort(A,0,n-1);

    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    // https://www.geeksforgeeks.org/power-function-cc/ - check this link for understanding how pow works 
    int a = (int)(pow(10, 1)+0.5);
    printf("%d ",a);

    return 0;
}

