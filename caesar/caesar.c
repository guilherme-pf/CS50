#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Conditions checking if the input on commmand line is valid, argc must be = 2 (./caesar + key) and the second argument must be all digits
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {

        if (isdigit(argv[1][i]))
        {

        }

        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

    }

    // Transforming argv[1] into an integer
    int key = atoi(argv[1]);

    // Getting the input of the plaintext
    string plaintext = get_string("Plaintext: \n");
    printf("ciphertext: ");

    // Looping the plaintext and changing each letter based on the provided, if it is upper or lower case
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 65 + key) % 26 + 65);
        }

        else if (islower(plaintext[i]))
        {
            printf("%c", (plaintext[i] - 97 + key) % 26 + 97);
        }

        // if it is a non alphabetical character then just print the character
        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");
}

