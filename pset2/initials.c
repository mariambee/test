/**
 * Meriton Ibrahimi
 * Harvard CS50
 * initials
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // obtain input from user
    string name = GetString();
    // print the first letter
    printf("%c", toupper(name[0]));
    // loop to look for the next initial
    for (int i = 0, s = strlen(name); i < s; i++)
    {
        if (isspace(name[i]))
        {
            // once space found print and capitalize next character
            printf("%c", toupper(name[i + 1]));
        }
    }
    printf("\n");
} 