#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Condition argc must be = 2 (./substitution + key)

    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Condition all characters must be alphabetical

    for (int i = 0, len = strlen(key); i < len; i++)
    {

        if (isalpha(key[i]))
        {

        }

        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

    }

    // Condition for the user to inout a 26 character key

    if (strlen(key) != 26)

    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Condition for unique letters, nested loop to check if argv[j] is == to argv[i]

    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            if ((key[i]) == key[j])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    // Getting the input of the plaintext

    string plaintext = get_string("Plaintext: \n");

    // Since the input of plaintext can contain uppercase and lower case letters we can convert all the plaintext to uppercase

    for (int i = 0; i < strlen(key); i++)
    {
        if (islower(key[i]))
        {
            key[i] = key[i] - 32;
        }
    }

    printf("ciphertext: ");

    // Logic to turn the plain text to ciphertext

    for (int i = 0; i < strlen(plaintext); i++)
    {
        // If it is a uppercase letter then we must subtract 65 (ascii A) to get the letter position on the key
        if (isupper(plaintext[i]))
        {
            int letter = plaintext[i] - 65;
            printf("%c", key[letter]);
        }

        // The only difference if it is an lowercase letter is that we must add 32 (difference between the uppercase and lowercase in the ascii table)
        else if (islower(plaintext[i]))
        {
            int letter = plaintext[i] - 97;
            printf("%c", key[letter] + 32);
        }
        // If the character is not a letter, we just print the character
        else
        {
            printf("%c", plaintext[i]);
        }

    }
    printf("\n");
}
