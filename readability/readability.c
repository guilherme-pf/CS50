#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


float count_letters(string text);
float count_words(string text);
float count_sentences(string text);


int main(void)

{
    string text = get_string("Text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float index = round((0.0588 * (letters / words * 100)) - (0.296 * (sentences / words * 100)) - 15.8);

    int index_integer = index;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index_integer);
    }


}

//Defining count_letters, using the isaplha function to count alphabetical characters
float count_letters(string text)
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


//Defining count_words, the number of words is the number of spaces +1, so we count the number of spaces and add +1
float count_words(string text)
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
//Defining count_sentences, it will be a sentence if after (? or ! or .), the next character is a /0 (end of the text) or the second character after (? or ! or .) is a uppercase letter.
float count_sentences(string text)
{
    int sentence_count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if ((text[i] == '?' || text[i] == '!' || text[i] == '.') && ((isupper(text[i + 2]) != 0) || text[i + 1] == '\0'))
        {
            sentence_count += 1;
        }
        else
        {
            sentence_count += 0;
        }

    }

    return sentence_count;
}
