/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include "helpers.h"

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Maximum amount of hay
 */
#define MAX 65536

void display(int middle, int values[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(i == middle)
        {
            printf("[%i] ", values[i]);
        }
        else
        {
            printf("%i ", values[i]);
        }
    }
    printf("\n");
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    //check that array exists and value to search is included within array boundaries
    if(n < 0)
    {
        printf("error: negative size");
        return false;
    }
    else if(value < values[0] || value > values[n-1])
    {
        // value out of array boundaries
        return false;
    }
    
    //Iterator to the middle if n is odd, else left middle is n is even
    int middle = n / 2 - !(n % 2);
    //display(middle, values, n);

    //Recursive binary search for value in array
    if (n < 2)
    {
        return value == values[middle];
    }
    else if(values[middle] > value) //search left
    {
        return search(value, &values[0], n / 2);
    }
    else if (values[middle] < value) //search right
    {
        return search(value, &values[middle + 1], n / 2); //i - i % 2);
    }
    else
        return 1;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n) sorting algorithm: counting sort
    
    //Initialize counting array with MAX = 65536
    int count[MAX + 1] = {};
    
    // fill counting array
    for(int i = 0; i < n; i++)
    {
        count[values[i]]++;
    }
    
    // sort original array according to counting array
    for(int i = 0, j = 0; i < MAX + 1; i++)
    {
        while(count[i])
        {
            values[j] = i;
            count[i]--;
            j++;
        }
    }
}