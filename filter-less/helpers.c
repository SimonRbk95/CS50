#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
            {
                int b = image[i][j].rgbtBlue;
                int r = image[i][j].rgbtRed;
                int g = image[i][j].rgbtGreen;
                int pixel_avg = round((b + r + g)/3);
                


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
