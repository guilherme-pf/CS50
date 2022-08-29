#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    // Restrictions to numbers below 1 and above 9

    while (n < 1 || n > 8);

    // For each row

    for (int i = 0; i < n; i++)
    {
        // For each column

        for (int j = 0; j < (2 * n) + 2; j++)
        {
            // Conditions to print a blank space at beggining of each line

            if (i + j < n - 1)
            {
                printf(" ");
            }

            // Conditions to print a blank in the middle of our pyramid

            else if (i < n && j == n)
            {
                printf(" ");
            }

            else if (i < n && j == n + 1)
            {
                printf(" ");
            }

            // Here we print nothing instead of a blank space, so our pyramid doesn't have empty spaces at the end of each line

            else if (i - j < -n - 2)

            {
                printf("");
            }

            else

                // Print a # everywhere else
            {
                printf("#");
            }

        }
        // Next Row
        printf("\n");

    }
}