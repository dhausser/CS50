#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int alpha_index(char c);
char *crack(char *key);

int main(int argc, char* argv[])
{
    //Check if single argument
    if(argc != 2)
    {
        printf("error: missing command-line argument");
        return 1;
    }
    
    //Check if argument contains non-alphabetical character
    if(argv[1] != NULL)
    {
        for(int i = 0; i < strlen(argv[1]); i++)
            if(!isalpha(argv[1][i]))
            {
                printf("error: argument contains non-alphabetical character");
                return 1;
            }
    }
    
    //Crack password
    printf("\npassword: %s\n", crack("50.jPgLzVirkc"));
    //printf("password: %s\n", crack("50YHuxoCN9Jkc"));
    //printf("password: %s\n", crack("50QvlJWn2qJGE"));
    //printf("password: %s\n", crack("50CPlMDLT06yY"));
    //printf("password: %s\n", crack("50WUNAFdX/yjA"));
    //printf("password: %s\n", crack("50fkUxYHbnXGw"));
    //printf("password: %s\n", crack("50C6B0oz0HWzo"));
    //printf("password: %s\n", crack("50nq4RV/NVU0I"));
    //printf("password: %s\n", crack("50vtwu4ujL.Dk"));
    //printf("password: %s\n", crack("50i2t3sOSAZtk"));
    //printf("password: %s\n", crack(argv[1]));
    
    printf("%s\n", crypt("rofl", "50"));
}

char *crack(char *hash)
{
    char *key = malloc(sizeof(char)*(strlen(hash)+1));
    char salt[2];
    for(int i = 0 ; i < strlen(hash) ; i++)
    {
        if(i < 2)
            salt[i] = hash[i];
        else
        {
            key[i] = hash[i];
            //printf("%c\n", hash[i]);
            printf("%c", key[i]);
        }
    }
    //key[strlen(hash)] = '\0';
    printf("%s", key);
    return key;
}

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