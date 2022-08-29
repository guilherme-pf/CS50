#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int count_letters(string text);

int main(void)

{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    printf("%i\n", letters);

}

//Defining count_letters
int count_letters(string text)
{
    int letter_count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count += 1;
        }
        else
        {
            letter_count += 0;
        }

    }
    return letter_count;
}
