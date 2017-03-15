#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(void)
{
    //Ask user for a name
    string full_name = get_string();
    
    //Check is full_name is a string
    if(full_name != NULL)
    {
        //Iterate over the character of full_name one at a time
        for(int i = 0, n = strlen(full_name); i < n; i++)
        {
            // Output uppercase letter for each initials in full name
            if(isalpha(full_name[i]) && !isalpha(full_name[i-1]))
                printf("%c", toupper(full_name[i]) );
        }
    }
    printf("\n");
}