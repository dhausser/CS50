#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int alpha_index(char c)
{
    if(isupper(c))
        return c - 'A';
    else if(islower(c))
        return c - 'a';
    else
    {
        printf("ERROR IN ALPHA INDEX: %c\n", c);
        return 1;
    }
}

char* crack(char* keyword, char* plaintext)
{
    if(plaintext != NULL)
    {
        char* ciphertext;
        for(int i = 0, j = 0, m = strlen(keyword), n = strlen(plaintext); i < n ; i++)
        {
            //Allocate memory for cipher text on first pass of the loop
            if(i == 0)
                ciphertext = (char*)malloc(n);
            
            //Encrypt only if char is a alphabetical letter    
            if(isalpha(plaintext[i]))
            {
                //Preserve case in encryption
                if(isupper(plaintext[i]))
                    ciphertext[i] = 'A' + (alpha_index(plaintext[i]) + alpha_index(keyword[j]))  % 26;
                else if(islower(plaintext[i]))
                    ciphertext[i] = 'a' + (alpha_index(plaintext[i]) + alpha_index(keyword[j]))  % 26;
                else
                    printf("Error: %c is neither uppercase nor lowercase", plaintext[i]);
                
                //Increment key index for keyword    
                if(j < m-1)
                    j++;
                else
                    j = 0;
            }
            else
                ciphertext[i] = plaintext[i];
        }
        return ciphertext;
    }
    return NULL;
}

int main(int argc, string argv[])
{
    //Check if single argument
    if(argc != 2)
    {
        printf("Error: no cipher key provided as argument");
        return 1;
    }
    //Check if argument contains non-alphabetical character
    for(int i = 0; i < strlen(argv[1]); i++)
        if(!isalpha(argv[1][i]))
        {
            printf("Error: argument contains non-alphabetical character");
            return 1;
        }
        
    //Ask user for a plaintext
    printf("plaintext: ");
    string plaintext = get_string();

    //Cipher text using Vigenere
    printf("ciphertext: %s\n", crack(argv[1], plaintext));

    return 0;
}