#include "helpers.h"
#include "math.h"
#include "cs50.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            {
                // float variables for easier calculation and rounding precision
                float b, r, g;
                b = image[i][j].rgbtBlue;
                r = image[i][j].rgbtRed;
                g = image[i][j].rgbtGreen;
                // get the adequate shade of grey
                int avg = round((b + r + g)/3);
                if (avg > 255)
                {
                    avg = 255;
                }
                // turn the pixel grey
                image[i][j].rgbtBlue = avg;
                image[i][j].rgbtRed = avg;
                image[i][j].rgbtGreen = avg;
            }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float b, r, g;
    int sepiaRed, sepiaGreen, sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            {
                // float variables for easier calculation and rounding precision
                b = image[i][j].rgbtBlue;
                r = image[i][j].rgbtRed;
                g = image[i][j].rgbtGreen;
                // get sepia color
                sepiaRed = round(0.393 * r + 0.769 * g + 0.189 * b);
                sepiaGreen = round(0.349 * r + 0.686 * g + 0.168 * b);
                sepiaBlue = round(0.272 * r + 0.534 * g + 0.131 * b);
                if (sepiaRed > 255)
                {
                    sepiaRed = 255;
                }
                if (sepiaGreen > 255)
                {
                    sepiaGreen = 255;
                }
                if (sepiaBlue > 255)
                {
                    sepiaBlue = 255;
                }
                // turn pixel sepia
                image[i][j].rgbtBlue = sepiaBlue;
                image[i][j].rgbtRed = sepiaRed;
                image[i][j].rgbtGreen = sepiaGreen;
            }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
            {
                // find out size of array
                int len = sizeof(image[i].rgbtBlue);
                // create dynamic memory for the swap
                int *tempBlue = malloc(len);
                int *tempRed = malloc(len);
                int *tempGreen = malloc(len);
                // check if memory is available
                if (tempBlue == NULL)
                {
                    printf("mallocError");
                    return 1;
                }
                // if the number of pixels in a row is even
                if (len % 2 == 0)
                {
                    // get the first and outter pixel
                    for (int a = 0, int middle = (len/2 - 1), a > middle; )
                // swap all of them
                }
                // pixel in the middle stays the same
                else
                {
                    for (int a = 0, int middle = (len/2 - .5); a < middle; a++)
                    {
                        for (int c = len -1; c > middle; c--)
                        {
                            //
                            tempRed = image[i][c];
                            tempGreen = image[i][c - 1];
                            tempBlue = image[i][c - 2];
                            image[i][j].rgbtBlue = ;
                            image[i][j].rgbtRed = sepiaRed;
                            image[i][j].rgbtGreen = sepiaGreen;

                        }
                    }


                }


            }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
