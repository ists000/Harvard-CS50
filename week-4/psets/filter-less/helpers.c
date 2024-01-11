#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg_grayscale;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg_grayscale = round((double) (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = avg_grayscale;
            image[i][j].rgbtGreen = avg_grayscale;
            image[i][j].rgbtRed = avg_grayscale;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int a_sepiaRed;
    int a_sepiaGreen;
    int a_sepiaBlue;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            a_sepiaRed =
                round((double) (0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue));
            a_sepiaGreen =
                round((double) (0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue));
            a_sepiaBlue =
                round((round) (0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue));

            if (a_sepiaRed > 255)
            {
                a_sepiaRed = 255;
            }
            if (a_sepiaGreen > 255)
            {
                a_sepiaGreen = 255;
            }
            if (a_sepiaBlue > 255)
            {
                a_sepiaBlue = 255;
            }

            image[i][j].rgbtRed = a_sepiaRed;
            image[i][j].rgbtGreen = a_sepiaGreen;
            image[i][j].rgbtBlue = a_sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
    int half_width = width / 2;
    int n = width - 1;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < half_width; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][n - j];
            image[i][n - j] = buffer;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int amount_red = 0;
            int amount_green = 0;
            int amount_blue = 0;
            float count = 0.0;

            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int n_i = i + di;
                    int n_j = j + dj;

                    if (n_i >= 0 && n_i < height && n_j >= 0 && n_j < width)
                    {
                        amount_red += image[n_i][n_j].rgbtRed;
                        amount_green += image[n_i][n_j].rgbtGreen;
                        amount_blue += image[n_i][n_j].rgbtBlue;
                        count++;
                    }
                }
            }

            int avg_red, avg_green, avg_blue;

            buffer_image[i][j].rgbtRed = round(amount_red / count);
            buffer_image[i][j].rgbtGreen = round(amount_green / count);
            buffer_image[i][j].rgbtBlue = round(amount_blue / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = buffer_image[i][j];
        }
    }

    return;
}
