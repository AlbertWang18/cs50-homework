#include<stdio.h>
#include<cs50.h>

int main(void)
{
    int n;
    
    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8);
    
    // i for height, j for space, k for 
    
    int i, j, k;
    
    for (i = 0; i < n; i++)
    {
        
        //print space
        
        for (j = 0; j < n - 1 - i; j++)
        {
            printf(" ");
        }
        
        //print #
        
        for (k = 0; k <= i; k++)
        {
            printf("#");
        }
        
        printf("\n");
    }
}    