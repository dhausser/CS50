/**
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define ALPHABET 27

/**
 *structure to represent each node in the dictionary trie.
 */
typedef struct node
{
    bool is_word;
    struct node *children[ALPHABET];
}
node;

/**
 * Pointer to the root of the dictionary trie
 */
node *root;

/**
 * Returns newly created node in trie.
 */
node *newnode(void);

/**
 * Unloads trie recursively from memory.  Returns true if successful else false.
 */
void release(node *pt);

/**
 * value to store sife of dictionary
 */
int dictsize;

/**
 * Returns alphabetical index of character
 */
unsigned int alpha_index(char c);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word);

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

#endif // DICTIONARY_H
