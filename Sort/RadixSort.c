#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int data;
    struct node *next;
};

void insert(struct node **p, int val, int idx)
{
    struct node *temp, *t;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (p[idx] == NULL){
        p[idx] = temp;
    }
    else
    {
        t = p[idx];
        while (t->next != NULL){
            t = t->next;
        }
        t->next = temp;
    }
}

int Delete (struct node **p, int x)
{
    struct node *t=p[x];
   p[x] = p[x]->next;
    int n;
    n = t->data;
    free(t);
    return n;
}

int findMax(int A[], int n)
{
    int max = INT_MIN;
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int getBinindex(int x, int index)
{ 
    // https://www.geeksforgeeks.org/power-function-cc/ - check this link for understanding how pow works 
    return (int)(x / (pow(10, index)+0.5)) % 10;
    // here we will pass , number of passes as index in RedixSort function
}

// counts number of digits in number, ex-256 have 3 digits, 25 has 2 digits
int countdigits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x = x / 10;
        count++;
    }
    return count;
}

void Radixsort(int A[], int n)
{
    int max, npass, index;
    max = findMax(A, n);
    npass = countdigits(max);
    struct node **bins;
    bins = (struct node **)malloc((max + 1) * sizeof(struct node *));
    for (int i = 0; i < 10; i++)
        bins[i] = NULL;
    for (int pass = 0; pass < npass; pass++)
    {
        for (int i = 0; i < n; i++)
        {
            index = getBinindex(A[i],pass);
            insert(bins, A[i], index);
        }
    int i = 0;
    int j = 0;
    while (i < 10)
    {
        while (bins[i] != NULL)
        {
            A[j++] = Delete (bins, i); 
        }
        i++;
    }
    for (i = 0; i < 10; i++){  
        bins[i] = NULL;
    }
 
}
    free(bins);
}
 
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10, i;
    Radixsort(A, n);
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}