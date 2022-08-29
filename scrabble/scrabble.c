#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if (score1 > score2)
    {
        printf("Player 1 wins\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins \n");
    }
    else
    {
        printf("tie \n");
    }

}
// Defining the fucntion compute_score
int compute_score(string word)
{
    int score = 0;

// Using a for loop to get the lenght of the word, after that using the index of the input word to get the letter, and then getting the score by subtracting the letter 'A' or 65 (ASCII),and adding to the score, for example, is the first letter is A, the index on the points array would 65 - 65 = 0, adding 1 point to the score
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }

    }
    return score;
}
