#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    //prompt part
    
    float dollars;
    
    do
    {
        dollars = get_float("Change owed:");
        if (dollars < 0)
        {
            printf("Change owed: foo\n");
        }
    }
    while (dollars < 0);
    
    //turn dollars to cents to avoid impersion of float
    
    int cents = round(dollars * 100);
    
    int n_quar = 0;
    int n_dime = 0;
    int n_nickel = 0;
    int n_penny = 0;
    
    // Each cycle subtracts one of the largest parts and adds one to the corresponding number of coins
    
    do
    {
        if (cents >= 25)
        {
            n_quar++;
            cents = cents - 25;
        }
        else if (cents >= 10)
        {
            n_dime++;
            cents = cents - 10;
        }
        else if (cents >= 5)
        {
            n_nickel++;
            cents = cents - 5;
        }
        else if (cents >= 1)
        {
            n_penny++;
            cents = cents - 1;
        }
        
    }
    while (cents != 0);
    
    int number = n_quar + n_dime + n_nickel + n_penny;
    printf("%i\n", number);
}