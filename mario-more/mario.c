#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt for input as long as condition is met
    int height;
    do{
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // create building with n hashtags

    // for each row
    for (int i = 1; i <= height; i++)
    {
        // for each column
        for(int j = 1; j <= i; j++)
        {
            printf("#");
        }
    // move to next row
        printf("\n");
    }

    for (int i = 1; i < height; i++){

            // for each column print '.'
            for (int l = height - i; l >= 1; l--){
                printf("");
            }
            // for each column print '#'
            for(int j = 1; j <= i; j++){
                printf("#");
            }
        // move to next row
            printf("\n");
        }



}

//for(int l = n - 1; l >= 1; l--){
//                    printf(".");
//                }