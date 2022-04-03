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

    // for each row
    for (int i = 1; i <= n; i++)
    {
        // for each column
        for(int j = 1; j <= i; j++)
        {
            printf("#");
        }
    // move to next row
        printf("\n");
    }

    for (int i = 0; i < n; i++){

            // for each column
            printf(".");
            for(int j = 0; j < i; j++){

                // each colum print '.'


                printf("#");
            }
        // move to next row
            printf("\n");
        }



}

//for(int l = n - 1; l >= 1; l--){
//                    printf(".");
//                }