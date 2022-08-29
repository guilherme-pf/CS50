#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int count_words(string text);

int main(void)

{
    string text = get_string("Text: ");
    int words = count_words(text);
    printf("%i\n", words);

}

//Defining count_words
int count_words(string text)
{
    int space_count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            space_count += 1;
        }
        else
        {
            space_count += 0;
        }

    }

    int word_count = space_count + 1;

    return word_count;
}
