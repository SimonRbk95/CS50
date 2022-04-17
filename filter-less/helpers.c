#include "helpers.h"
#include "math.h"

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
                int sepiaRed = round(.393 * r + .769 * g + .189 * b);
                int sepiaGreen = round(.349 * r + .686 * g + .168 * b);
                int sepiaBlue = round(.272 * r + .534 * g + .131 * b);
                if (sepiaRed > 255)
                {
                    sepiaRed = 255;
                }
                if (sepiaGreen > 255)
                {
                    sepiaGreen = 255;
                }
                if(sepiaBlue)
                {
                    sepiaBlue = 255;
                }
                // turn the pixel grey
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
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
