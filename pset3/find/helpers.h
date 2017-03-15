/**
 * helpers.h
 *
 * Helper functions for Problem Set 3.
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Maximum amount of hay
 */
#define MAX 65536

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n);

/**
 * Sorts array of n values.
 */
void sort(int values[], int n);

/**
 * Displays array of n values for testing
 */
void display(int middle, int values[], int n);