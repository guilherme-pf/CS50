#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <cs50.h>

int main(void)
{
    //test different hash functions
    string word = get_string("Word: ");

    int hash = ((toupper(word[0]) - 'A' + ((toupper(word[0]) - 'A') * 25)) + (toupper(word[1]) - 'A'));
    if (hash < 0)
    {
        hash = 0;
    }
    //printing hash index
    printf("%i\n", hash);
}

