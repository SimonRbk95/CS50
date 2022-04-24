// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
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
// maximum number of distinct sums of the alphabetical indices with itself
const unsigned int N = 1100;

// Hash table
node *table[N];

// global variable that counts the number of words in the dictionary
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *cursor = table[index];
    while (true)
    {
        if (cursor == NULL)
        {
            return false;
        }
        else if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // add all the letters in the word
    // only consider distinct sums
    unsigned int index = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        index += toupper(word[i]) - 'A';
    }
    return (index % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // fopen the dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }
    char word_output[LENGTH + 1];
    // read from the file until EOF
    while (fscanf(dict, "%s", word_output) != EOF)
    {
        // loop through the dictionary, scanfing every word
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            return false;
        }
        strcpy(new->word, word_output);
        new->next = NULL;
        // get the index based on the hash function
        int index = hash(word_output);

        // if it is the first word
        if (table[index] == NULL)
        {
            table[index] = new;
        }
        else
        {
            // set new node's next pointer to the first element in the linked list
            new->next = table[index];
            // make the new node the first element at table[index]
            table[index] = new;
        }
        word_count++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        // set cursor to current bucket
        node* cursor = table[i];
        while (cursor != NULL)
        {
            // store current bucket as a temporary pointer
            node *tmp = cursor;
            // traverse to next bucket
            cursor = cursor->next;
            // free current bucket
            free(tmp);
        }
        // free last item in linked list
        free(cursor);
    }
    return true;
}