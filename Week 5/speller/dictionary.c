// Implements a dictionary's functionality
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int TABLE_HASH = 100000;

// Hash table
node *table[TABLE_HASH];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int index = hash(word);
    node *finder = table[index];
    for (node *temp = finder; temp != NULL; temp = temp->next)
    {
        if(strcasecmp(temp->word,word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    // for this hash get the lengh of the string then we will sum the value of the characters.
    unsigned int hash_len = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        hash_len += tolower(word[i]);
        hash_len = (hash_len * tolower(word[i])) % TABLE_HASH;
    }
    return hash_len;
}

int counter = 0;

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file =fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "error");
        return false;
    }

    char wordlist[LENGTH + 1];
    while (fscanf(file, "%s", wordlist) != EOF)
    {
        //Counter to track nodes
        counter++;
        //allocate memory for each node
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return 1;
        }
        //copy the word to next node
        strcpy(newNode->word, wordlist);
        newNode->next = NULL;

        //point to old list if null
        int index = hash(wordlist);
        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            //next node
            newNode->next = table[index];
            //points to newest node
            table[index] = newNode;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Node counter
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // reminder to self, free the buckets at the end
    node *tmp = NULL;
    node *finder = NULL;
    for (int i = 0; i < TABLE_HASH; i++)
    {
        finder = table[i];
        while (finder != NULL)
        {
           tmp = finder;
            finder = finder->next;
           free(tmp);
        }
    }
    return true;
}