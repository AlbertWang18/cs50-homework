#include<stdio.h>
#include<cs50.h>

int main(void)
{
    // TODO: Prompt for start size

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
    
    int n_begin;
    int n_end;
    int year = 0;
    int n_die;
    int n_born;
    
    // start size should greater than or equal to 9
    
    do
    {
        n_begin = get_int("Start size:");
        
    }
    while (n_begin < 9);
    
    int n_this = n_begin;
    
    // end size should greater than start size
    
    do
    {
        n_end = get_int("End size:");
        
    }
    while (n_end < n_begin);
    
    // main program
    
    if (n_begin == n_end)
    {
        printf("Years: 0");
    }
    else
    {
        do
        {
            n_born = n_this / 3;
            n_die = n_this / 4;
            n_this = n_this - n_die + n_born;
            year++;
        
            //printf("%i %i %i %i\n ", year, n_born, n_die, n_this);
        }
        while (n_this < n_end);
    
        printf("Years: %i", year);
    }
   
}