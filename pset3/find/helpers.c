/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
#include <stdio.h>
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // set min and max
    int min = 0;
    int max = n - 1;
    // set loop to keep dividing the list until condtion reached
    while (min <= max)
    {
        // find mid
        int mid = (min + max) / 2;
        if (values[mid] == value)
        {
            // found value
            return true;
        }
        else if (values[mid] < value)
        {
            // look in right half
            min = mid + 1;
        }
        else if (values[mid] > value)
        {
            // look in left half
            max = mid - 1;
        }
    }
    // value not in the list
    return false;
}

/*  
    linear search 
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
        return true;
    }
    return false;
*/ 

/**
 * Sorts array of n values.
 */
// selection sort
void sort(int values[], int n)
{
    // begin loop through the list
    for (int i = 0; i < n; i++)
    {
        // set initial min for loop through list each time
        int min = i;
        // declare variable of next value in list
        int next;
        // loop over the other values in the list
        for (next = i + 1; next < n; next++)
        {
            // check if there is a new min
            if (values[next] < values[min])
            {
                min = next;
            }
        }
        // swap if a new min is found
        if (min != i)
        {
            int temp = values[next];
            values[next] = values[i];
            values[i] = temp;
        }
    }
    return;
}
