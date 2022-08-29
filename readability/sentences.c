#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


int count_sentences(string text);

int main(void)

{
    string text = get_string("Text: ");
    int sentences = count_sentences(text);
    printf("%i\n", sentences);

}

//Defining count_sentences
int count_sentences(string text)
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
