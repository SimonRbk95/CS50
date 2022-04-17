#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
            {
                // float variables for easier calculation and rounding precision
                float b = image[i][j].rgbtBlue;
                float r = image[i][j].rgbtRed;
                float g = image[i][j].rgbtGreen;
                // get the adequate shade of grey
                int avg = round((b + r + g)/3);
                // 
                if (avg > 255)
                {
                    avg = 255;
                }
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
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
