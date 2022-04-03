#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //mention function declared below
    void createPyramide(int height);

    // prompt for input as long as condition is met
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // create building with n hashtags
    createPyramide(height);
}
void createPyramide(int height)
{
    for (int i = 1; i <= height; i++)
    {
        // for each column print space
        for (int l = height - i; l >= 1; l--)
        {
            printf(" ");
        }
            // for each column print '#'
            for (int j = 1; j <= i; j++)
            {
                printf("#");
            }
            // for each row print double space
            printf("  ");

            // for each column print mirrored '#'
            for (int k = 1; k <= i; k++)
            {
                printf("#");
            }

        // move to next row
            printf("\n");
        }
}


