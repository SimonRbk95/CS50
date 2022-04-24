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
const unsigned int N = 26;

// Hash table
node *table[N];

// global variable that counts the number of words in the dictionary
int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    node *cursor;
    int index = hash(word);
    cursor = table[index];
    while (true)
    {
        if (cursor == NULL)
        {
            return false;
        }
        else if (strcasecmp(word, cursor->word) == 0)
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
    // add the first three letters' alphabetic index to create 76 distinct sums/ index
    // int x = toupper(word[0] -'A');
    // int y = toupper(word[1] - 'A');
    // int z = toupper(word[2] - 'A');
    // int index = x + y + z;
    // return (index % 76);
    return toupper(word[0] -'A');

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
            // hash table's corresponding index's next field points to the new node
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
    // TODO
    node *cursor;
    node *tmp;
    for (int i = 0; i < N; i++)
    {
        while (cursor != NULL)
        {
            cursor = table[i];
            tmp = cursor;
            cursor = table[i]->next;
            free(tmp);
        }
    }
    return true;
}
