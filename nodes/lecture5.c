#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main (void)
{
    //list of size
    node *list = NULL;

    //add a number to list
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n -> number = 1;
    n -> next = NULL;

    //update list to new node

    list = n;

    //add a number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }

    n -> number = 2;
    n -> next = NULL;
    list -> next = n;

    // add a number to list
    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list -> next); // we should free the next list first, and then list, because we use list to get no next list
        free(list);
        return 1;
    }

    n -> number =3;
    n -> next = NULL;
    list -> next -> next = n;

    //print numbers: with linked list we can't use que normal print syntax printf("%i\n", list[i])
    for (node *tmp = list; tmp != NULL; tmp = tmp -> next)
    {
        printf("%i\n", tmp -> number);
    }

    // free list
    while (list != NULL)
    {
        node *tmp = list -> next;
        free(list);
        list = tmp;
    }

    return 0;

}