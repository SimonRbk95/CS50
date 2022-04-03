#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Mention function declared below
    void createPyramide(int height);

    // Prompt for input as long as condition is met
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Create pyramide with hashtags
    createPyramide(height);
}
void createPyramide(int height)
{
    for (int i = 1; i <= height; i++)
    {
        // For each column print whitespace
        for (int l = height - i; l >= 1; l--)
        {
            printf(" ");
        }
            // For each column print '#'
            for (int j = 1; j <= i; j++)
            {
                printf("#");
            }
            // For each row print whitespace
            printf("  ");
            // For each column print mirrored '#'
            for (int k = 1; k <= i; k++)
            {
                printf("#");
            }
            // Move to next row
            printf("\n");
    }
}
