/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// seems to maximize speed (consist <.07s) while minimizing memory allocation
#define BUCKETSIZE 8500

// create node struct
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

// create hashtable
node* hashtable[BUCKETSIZE];

// initialize size of dictionary to 0 globaly to be used by load and size
int dictionarysize = 0;

// hashfunction: djb2 http://www.cse.yorku.ca/~oz/hash.html#djb2
unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;
    // note: the two () were needed to silence compiler (tf Karl)
    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + tolower(c);
    }
    return hash % BUCKETSIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // find the bucket the given word should be in
    int bucket = hash((unsigned char*) word);
    // check if the hashtable bucket is empty
    if (hashtable[bucket] == NULL)
    {
        // bucket empty, so given word is not in the dictionary
        return false;
    }
    // create crawler to traverse linked list
    node* crawler = hashtable[bucket];
    // compare word given to stored dictionary words in linked list
    while (crawler != NULL)
    {
        if ((strcasecmp(crawler->word, word) == 0))
        {
            return true;
        }
        // move along linked list
        crawler = crawler->next;
    }
    // word not found, it is miisspelled
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open file
    FILE* infile = fopen(dictionary, "r");
    // check for NULL
    if (infile == NULL)
    {
        return false;
    }
    // create buffer to store each word
    char buffer[LENGTH + 1];
    // scan file and load words into hashtable
    while (fscanf(infile, "%s", buffer) != EOF)
    {
        // allocate memmory for each word
        node* newword = malloc(sizeof(node));
        // check for NULL
        if (newword == NULL)
        {
            return false;
        }
        // store new word into allocated memory
        strcpy(newword->word, buffer);
        // get the bucket in which the word is stored from hash
        int bucket = hash((unsigned char*) &buffer);
        // insert word into the bucket
        newword->next = hashtable[bucket];
        hashtable[bucket] = newword;
        // increment dictionary size
        dictionarysize++;
    }
    fclose(infile);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (dictionarysize > 0)
    {
        return dictionarysize;
    }
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // start going through hashtable to free nodes
    for (int bucket = 0; bucket < BUCKETSIZE; bucket++)
    {
        // if bucket not empty free the word-nodes
        while (hashtable[bucket] != NULL)
        {
            // set crawler to the first dictionary word-node in linked list
            node* crawler = hashtable[bucket];
            // set hashtable to the next dictionary word
            hashtable[bucket] = crawler->next;
            // free the word-node traversed over
            free(crawler);
        }
    }
    return true;
}
