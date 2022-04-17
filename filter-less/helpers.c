#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (i = 0; i < height; i++)
    {
        for(j = 0; j < width; j++)
            {
                float b = image[i][j].rgbtBlue;
                float r = image[i][j].rgbtRed;
                float g = image[i][j].rgbtGreen;
                int avg = round((b + r + g)/3);
                if (avg > 255)
                {
                    avg = 255;
                }
                



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
