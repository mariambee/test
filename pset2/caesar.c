/**
 * Meriton Ibrahimi
 * Harvard CS50
 * caesar
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    // check for only one command-line argument
    if (argc != 2)
    {
        printf("Try again...Provide one, and only one, positive number...\n");
        return 1;
    }
    int k = atoi(argv[1]);
    // check for non-negative integer
    if (k < 0)
    {
        printf("Try again...Provide one, and only one, positive number...\n");
        return 1;
    }
    string phrase = GetString();
    // loop to encrypt phrase
    for (int i = 0, s = strlen(phrase); i < s; i++)
    {
        //check if character is alpha
        if (isalpha(phrase[i]))
        {
            // check if character is alpha lower
            if (islower(phrase[i]))
            {
                printf("%c", (((phrase[i] - 'a' + k)) % 26) + 'a');
            }
            // else character is alpha upper
            else
            {
                printf("%c", (((phrase[i] - 'A' + k)) % 26) + 'A');
            }
        }
        // else character is not alpha, so print it as is
        else
        {
            printf("%c", phrase[i]);
        }
    }        
    printf("\n");
    return 0;
}