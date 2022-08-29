#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //converting every RGB value in every pixel to float, finding the average and turning into an integer
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float Red = image[i][j].rgbtRed;
            float Green = image[i][j].rgbtGreen;
            float Blue = image[i][j].rgbtBlue;

            int avrg = round((Red + Green + Blue) / 3);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avrg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //converting every RGB value in every pixel to float, defining original RGB and then applying the sepia formula (including the conditions if the red/green/blue factor is > 255, then use 255) to everypixel.
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            int sepiared = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);

            if (sepiared > 255)
            {
                image[i][j].rgbtRed = 255;
            }

            else
            {
                image[i][j].rgbtRed = sepiared;
            }

            int sepiagreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);


            if (sepiagreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }

            else
            {
                image[i][j].rgbtGreen = sepiagreen;
            }

            int sepiablue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            if (sepiablue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepiablue;
            }

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // The main differecen for this loop is that we must stop the loop when we reach halfaway trough the picture, otherwise we would swap back all the pixel we'd just swap
        for (int j = 0; j < width / 2; j++)
        {
            // since we must swap 2 pixels here, we must use a temp variable to store one of the pixel as we make the swap
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // We must create a temporary image of the same size of pixels to store all the new calculated pixels, so we dont affect the calculation of the other pixels
    RGBTRIPLE tempimg[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempimg [i][j] = image[i][j];
        }
    }
    //
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Creat 4 variables, 3 representing the total os Red/Green/Blue that we will use for the average value and 1 that will be the divisor of the average
            int tred = 0;
            int tblue = 0;
            int tgreen = 0;
            float divisor = 0.00;

            // If we think the image as a matrix where the the first pixel is in the location (0,0), the pixel left the first one would be (0, -1), here we are looping through the image and all the pixels around the image.
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    int locationA = i + a;
                    int locationB = j + b;

                    //Here are the conditions to the pixel to be a invalid pixel, based on his location, remembering that the first pixel on the first row of the image is located on (0, 0)
                    if (locationA < 0 || locationA > (height - 1) || locationB < 0 || locationB > (width - 1))
                    {
                        continue;
                    }
                    // If the pixel is valid add to the total (red/green/blue) the value of each atributte
                    tred = tred + image[locationA][locationB].rgbtRed;
                    tgreen = tgreen + image[locationA][locationB].rgbtGreen;
                    tblue = tblue + image[locationA][locationB].rgbtBlue;

                    //Also if the pixel is valid add one to the divisor
                    divisor++;
                }
                //calculationg the averages of the total RGB values from the pixels around the image[i][j] pixel
                tempimg[i][j].rgbtRed = round(tred / divisor);
                tempimg[i][j].rgbtGreen = round(tgreen / divisor);
                tempimg[i][j].rgbtBlue = round(tblue / divisor);
            }
        }
    }

    // Saving all the new pixels to the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = tempimg[i][j].rgbtRed;
            image[i][j].rgbtBlue = tempimg[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tempimg[i][j].rgbtGreen;
        }
    }

    return;
}
