#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

char* caesar(int k, string plaintext)
{
    if(plaintext != NULL)
    {
        int n = strlen(plaintext);
        char* ciphertext = (char*)malloc(n);
        
        
        for(int i = 0 ; i < n ; i++)
        {
            // Modifies each letter of plain text with its cipher
            ciphertext[i] = plaintext[i];
            
            // Keeping the case of the letter
            if(isalpha(plaintext[i]))
            {
                if(isupper(plaintext[i]))
                    ciphertext[i] = 'A' + (plaintext[i] - 'A' + k)  % 26;
                else if(islower(plaintext[i]))
                    ciphertext[i] = 'a' + (plaintext[i] - 'a' + k)  % 26;
                else
                    printf("Error: %c is neither uppercase nor lowercase", plaintext[i]);
            }
        }
        return ciphertext;
    }
    return NULL;
}

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Error, no cipher key provided as argument");
        return 1;
    }
    int k = atoi(argv[1]);
    
    //Ask user for a plaintext
    printf("plaintext: ");
    string plaintext = get_string();

    //Cipher text using Caesar
    printf("ciphertext: %s\n", caesar(k, plaintext));

    return 0;
}