#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt for input as long as condition is met
    int n;
    do{
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    // create building with n hashtags

    // each row
    for (int i = 0; i < n; i++)
    {
        //printf(".");
        // for each column
        for(int x = 0; x < n; x++)
        {
            printf("#");
        }
    // move to next row
        printf("\n");
    }




}