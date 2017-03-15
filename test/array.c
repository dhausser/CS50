/**
 * Dynamic array.
 */
       
#include <stdio.h>
#include <stdlib.h>
#include "bmp.h"

int main()
{
    int width = 16;
    int height = 16;
    int *array = (int *) malloc(width * height * sizeof(int));
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            array[i * height + j] = i * width + j;
            printf("%3i ", array[i * height + j]);
        }
        printf("\n");
    }
    
    free(array);
    
    return 0;
}