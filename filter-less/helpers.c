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
    // !!!! width is already the length of the array's index
    // so width/2 if width is even
    // each pixel is represented by 8 bits, so swap 24 bits
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width/2); j++)
            {
                // find out size of array
                // create dynamic memory for the swap
                int tempRed = image[i][j].rgbtRed;
                int tempGreen = image[i][j].rgbtGreen;
                int tempBlue = image[i][j].rgbtBlue;
                // if the number of pixels in a row is even
                if (width % 2 == 0)
                {
                    // start from the last pixel and swap them with the counterparts starting from the beginning
                    image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
                    image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                    image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;

                    image[i][width - j - 1].rgbtRed = tempRed;
                    image[i][width - j - 1].rgbtGreen = tempGreen;
                    image[i][width - j - 1].rgbtBlue = tempBlue;
                }
                // in case width is odd
                else
                {
                    // skip the pixel in the middle
                    if (j != (width + 1) / 2)
                    {
                    image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
                    image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                    image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;

                    image[i][width - j - 1].rgbtRed = tempRed;
                    image[i][width - j - 1].rgbtGreen = tempGreen;
                    image[i][width - j - 1].rgbtBlue = tempBlue;
                    }
                }
            }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    // change the pixel based on the algorithm
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_Red, total_Blue, total_Green;
            total_Red = total_Blue = total_Green = 0;
            float counter = 0.00;

            //Get the neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //check if the neighbouring pixels are valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    //Get the image value
                    total_Red += image[currentX][currentY].rgbtRed;
                    total_Green += image[currentX][currentY].rgbtGreen;
                    total_Blue += image[currentX][currentY].rgbtBlue;

                    counter++;
                }

                //do the average of neigbhouring pexels
                copy[i][j].rgbtRed = round(total_Red / counter);
                copy[i][j].rgbtGreen = round(total_Green / counter);
                copy[i][j].rgbtBlue = round(total_Blue / counter);
            }
        }

    }

    //copy the blurred image to the original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = copy[i][j].rgbtRed;
            image[i][j].rgbtGreen = copy[i][j].rgbtGreen;
            image[i][j].rgbtBlue = copy[i][j].rgbtBlue;
        }
    }
    return;
 }

