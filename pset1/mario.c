#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    
    // Prompts user for input of the pyramid's height
    do{
        printf("Please enter height between 1 and 23: \n");
        height = get_int();
    }while(height < 0 || height > 23);
    
    // Builds Mario's pyramid
    for(int i = 0 ; i < height ; i++)
    {
        // Starting from left to right, top to bottom
        for(int j = 0; j <= height + i + 1; j++)
        {
            // Prints the void with spaces
            if(j < height - i - 1)
            {
                printf(" ");
            }
            
            // Prints the middle of the pyramid
            else if(j == height)
            {
                printf("  ");
            }
            
            // Prints the pyramid blocks
            else 
            {
                printf("#");
            }
        }
        
        // Move the the next level
        printf("\n");
    }
    
    // Successfully built the pyramid
    return 0;
}