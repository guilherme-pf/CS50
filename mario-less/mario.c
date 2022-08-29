#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Width: ");
    }
    // Restrictions to numbers below 1 and above 9

    while (n < 1 || n > 8);

    // For each row

    for (int i = 0; i < n; i++)
    {
        // For each column

        for (int j = 0; j < n; j++)
        {
            // Condition to print a blank space instead of a #, you can think of each position on the structure n x n, as a combination of i and j positions, for example the first #, would be (0,0), the sum of i + j would be 0, so you must only print a # on the positions where the sum of i and j are bigger than (n -1).

            if (i + j < n - 1)
            {
                printf(" ");
            }
            else

                // Print a #
            {
                printf("#");
            }


        }
        // Next Row
        printf("\n");

    }

}