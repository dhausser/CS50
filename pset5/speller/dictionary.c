/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

#include "dictionary.h"

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // Create traversel pointer set to root of dictiorary trie
    node *pt = root;
    
    
    for(int i = 0, index; word[i] != '\0'; i++)
    {
        // Find alphabetical index for each letter in word
        index = alpha_index(word[i]);
        
        // Move to the next letter if it exists in dictionray
        if(pt->children[index] != NULL)
        {
            pt = pt->children[index];
        }
        else
        {
            return false;
        }
    }
    // Verify that the sequence of characters is a word in dictionary
    return pt->is_word;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // Open dictionary file to read
    FILE *fp = fopen(dictionary, "r");
    if (fp == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    
    // Allocate memory for the root of the dictionary
    root = newnode();
    
    // Create traversel pointer set to root of dictiorary trie
    node *pt = root;
    
    // Word variable declaration of iteration in while loop
    char word[LENGTH];
    
    // Initialization of dictionary size variable
    dictsize = 0;
    
    // Read dictionary entirewords using fscanf
    while(fscanf(fp, "%s", word) != EOF)
    {
        // 
        for(int i = 0, index; word[i] != '\0'; i++)
        {
            index = alpha_index(word[i]);
            
            // Check if letter already exists
            if(pt->children[index] == NULL)
            {
                pt->children[index] = newnode();
            }
            
            // Move pointer to next letter
            pt = pt->children[index];
        }
        // Once at the last letter is reached add word to dictionary
        dictsize++;
        pt->is_word = true;
        pt = root;
    }
    fclose(fp);
    return dictsize;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictsize;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    release(root);
    free(root);
    root = NULL;
    return !root;
}

/**
 * Recursively iterates over all node in dictionary tries and free memory from bottom to top
 */
void release(node *pt)
{
    // Iterates over all children nodes
    for(int i = 0; i < ALPHABET; i++)
    {
        // Release memory for each used node
        if(pt->children[i] != NULL)
        {
            // Recursively move to the lowest possible node
            release(pt->children[i]);
            
            // Free the lowest node
            free(pt->children[i]);
            
            // Reinitialize the child pointer to NULL to avoid double free of memory
            pt->children[i] = NULL;
        }
    }
}

/**
 * Returns alphabetical index of character
 */
unsigned int alpha_index(char c)
{
    if(isalpha(c))
    {
        return (tolower(c) - 'a');
    }
    else
    {
        return ALPHABET-1;
    }
}

/**
 * Returns newly created node in trie.
 */
node *newnode(void)
{
    //node *pt = (node *)calloc(1, sizeof(node));
    node *pt = (node *)malloc(sizeof(node));
    pt->is_word = false;
    for(int i = 0; i < ALPHABET; i++)
    {
        pt->children[i] = NULL;
    }
    return pt;
}