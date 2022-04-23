// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // fopen the dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }

    char word_output[LENGTH + 1];
    // read from the file until EOF
    while (fscanf(dict, "%s", word_output) != EOF)
    {
    // loop through the dictionary, scanfing every word
    // for every word
    // create a new node
        // use malloc
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            return false;
        }
        strcpy(new->word, word_output);
        new->next = NULL;

        int index = hash(word_output);
        // set new node's next pointer to the first element in the linked list
        new->next = table[index]->next;
        // hash table's corresponding index's next field points to the new word
        table[index]->next = new;


        // hash the word to determine at which index of the hash table the new node should be inserted into
        // index into the hash table
        // add the new node the linked list at the index
    }



    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
