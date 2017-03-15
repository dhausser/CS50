#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height = 0;
    do{
        printf("Please enter height between 1 and 23: \n");
        height = get_int();
    }while(height < 0 || height > 23);
    
    for(int i = 0 ; i < height ; i++)
    {
        for(int j = 0; j <= height + i + 1; j++)
        {
            if(j < height - i - 1)
                printf(" ");
            else if(j == height)
                printf("  ");
            else 
                printf("#");
        }
        printf("\n");
    }
    return 0;
}