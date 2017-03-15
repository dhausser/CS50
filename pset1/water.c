#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompts user for input
    printf("Please enter number of minutes in the shower:\n");
    int minutes = get_int();
    
    // Provide users with output
    printf("Minutes: %i\nBottles: %i\n", minutes, minutes*12);
    return 0;
}