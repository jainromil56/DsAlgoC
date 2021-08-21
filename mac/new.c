#include <stdio.h>

int main(){
    int arr[2][10];
    int k,l,m;
    printf("Enter your number \n");
    scanf("%d \n",&k);
    printf("Enter your number \n");
    scanf("%d \n",&l);
    printf("Enter your number \n");
    scanf("%d \n",&m);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr[0][j] = k*(j+1);
            arr[1][j] = l*(j+1);
            arr[2][j] = m*(j+1);
            printf("%d \n",arr[i][j]);
        }    
    }


    
    
    return 0;
}
