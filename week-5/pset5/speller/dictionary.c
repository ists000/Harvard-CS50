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
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 383;

// set a counter
int counter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // set cursor to point to first node in linked list
    int index = hash(word);
    node *cursor = table[index];

    // traverse linked list, looking for the word(strcasecmp)
    while (cursor != NULL)
    {
        // if word is fount, return true
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // move to next node
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
// Hashes word to a number using the hash function from "Algorithms in C" by Robert Sedgewick (Page 233)
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int h;
    for (h = 0; *word != '\0'; word++)
        h = (64 * h + tolower(*word)) % 383;
    return h;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // open dictionary file
    FILE *file = fopen(dictionary, "r");
    // to check if return value is NULL
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH + 1];

    // read strings from file one at a time
    while (fscanf(file, "%s", word) != EOF)
    {
        // create a new node for each word
        node *new_node = malloc(sizeof(node));
        // to check if return value is NULL
        if (new_node == NULL)
        {
            return false;
        }
        // copy word into node using strcpy (copy one location to another location)
        strcpy(new_node->word, word);
        // hash word to obtain a hash value, function takes a string and returns an index
        int index = hash(new_node->word);
        // insert node into hash table at that location
        new_node->next = table[index];
        table[index] = new_node;
        counter++;
    }
    // close the file
    fclose(file);
    // return ture
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
