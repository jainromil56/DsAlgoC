#include <stdio.h>
#include <stdlib.h>

struct Node{
    int col;
    int val;
    struct Node *next;
};



void Display(struct Node *m){
    int i,j;
    for (i = 1; i <= m->n ; i++)
    {
        for (j = 1; j <= m->n ; j++)
        {
            if (i>=j)
            {
                printf("%d",m->A[i]);
            }else{
                printf("0");
            }
            printf("\n");
        }
        
    }
    
}



int main(){
    int i,j,x;
    printf("Enter Dimension\n");
    scanf("%d",&m->n);
    m->A=(int *)malloc(m->n*sizeof(int));
    printf("Enter all elements");
    for (i = 1; i <= m->n; i++)
    {
        for (j = 1; j <= m->n; j++)
        {
            scanf("%d",&x);
            set(&m,i,j,x);
        }
        
    }
    printf("\n\n");
    Display(m);
    return 0;
}