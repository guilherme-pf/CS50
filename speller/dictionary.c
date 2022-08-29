// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 10000;
int word_count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int hash_number = hash(word);
    //creating crusor variable
    node *cursor = table[hash_number];

    //looping until the end of the linked list
    while (cursor != NULL)
    {
        //comparing and checking if the words are the same
        if (strcasecmp(cursor-> word, word) == 0)
        {
            return true;
        }
        // if not the same move to next node
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function: Improved, but no so much

    int hash = ((toupper(word[0]) - 'A' + ((toupper(word[0]) - 'A') * 25)) + (toupper(word[1]) - 'A'));
    if (hash < 0)
    {
        hash = 0;
    }
    return hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //Opening dictionary
    FILE *DictionaryFile = fopen(dictionary, "r");

    if (DictionaryFile == NULL)
    {
        return false;
    }

    //Reading dictionary one at a time
    char string[LENGTH + 1];
    while (fscanf(DictionaryFile, "%s", string) != EOF)
    {
        //Creating a new node
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            return false;
        }
        //inserting word into node
        strcpy(tmp->word, string);

        //Hash function
        int hash_number = hash(string);

        //check if the head is pointing to null
        if (table[hash_number] == NULL)
        {
            //pointing tmp to null
            tmp -> next = NULL;
        }
        else
        {
            //Otherwise, point tmp to the first node of the linked list
            tmp -> next = table[hash_number];
        }
        //point the header to tmp
        table[hash_number] = tmp;

        //adding +1 to word_count everytime it loads a word
        word_count += 1;
    }
    //close file
    fclose(DictionaryFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

//defining the function free_node
void free_node(node *n)
{
    //using recursion we define a base case and free(n) when we reach the base case, thats when n-> next = NULL
    if (n->next != NULL)
    {
        free_node(n->next);
    }
    free(n);
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            free_node(table[i]);
        }
    }
    return true;
}
