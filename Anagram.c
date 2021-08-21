#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Anagram is a sets of string with equal and same number of characters
    char A[] = "decimal";
    char B[] = "medical";
    int i;
    int H[26]={0};
    
    for (i = 0; A[i]!='\0'; i++)
    {
        H[A[i]-97]+=1;
    }
    for (i = 0; B[i]!='\0'; i++)
    {
        H[B[i]-97]-=1;
        if (H[B[i]-97]<0)
        {
            printf("Not an anagram\n");
            break;
        }
        
    }
    if (B[i]=='\0')
    {
        printf("Its Anagram\n");
    }
    
    return 0;
}