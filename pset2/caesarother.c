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
    if (argc == 2)
    {
        int k = atoi(argv[1]);
        string phrase = GetString();
        for (int i = 0, s = strlen(phrase); i < s; i++)
        {
            if (isalpha(phrase[i]))
            {
                if (islower(phrase[i]))
                {
                    printf("%c", (((phrase[i] - 'a' + k)) % 26) + 'a');
                }
                if (isupper(phrase[i]))
                {
                    printf("%c", (((phrase[i] - 'A' + k)) % 26) + 'A');
                }
            }
            else
            {
                printf("%c", phrase[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Try again...Provide one, and only one, number...\n");
        return 1;
    }
}