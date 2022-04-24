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
 FILE *open_dictionary = fopen(dictionary,"r");
    if (open_dictionary == NULL)
    {
        return false;
    }
    char Dword[LENGTH + 1];
    while(fscanf(open_dictionary,"%s", Dword) != EOF)
    {
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return false;
        }
        strcpy(newNode -> word, Dword);
        newNode -> next = NULL;
        int index = hash(Dword);

        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            newNode -> next = table[index];
            table[index] = newNode;
        }
        Count_size++;
    }
    fclose(open_dictionary);
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
        node* cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        free(cursor);
    }

    return true;
}