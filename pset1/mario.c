/**
 * Meriton IBrahimi
 * Harvard CS50
 * mario
 */

// done after hours of thought and playing with the code

#include <stdio.h>
#include <cs50.h>

int Getheight(void);

int main(void)
{
    int h = Getheight();
    // "r" for row
    for (int r = 1; r <= h; r++)
    // start from r=1 to correspond to pyramid height
    {
        for (int s = h - 1; s >= r; s--)
        // "s" for spaces
        // begin with spaces since they appear first in r=1
        // spaces decress down the pyramid
        // you need h-1 spaces in r=1
        {
            printf(" ");
        }
        for (int i = 0; i <= r; i++)
        // 'i" for hashes
        // hashes increase down the pyramid
        // two hashes for r=1 so two reiterations needed
        {
            printf("#");
        }
        printf("\n");
        // start a new row after placing spaces and then hashes
    }
}

int Getheight(void)
{
    // "h" for height
    int h;
    // loop for valid height
    do
    {
        printf("Give me the height of a pyramid up to 23...\n");
        h = GetInt();
    }
    while (h < 0 || h > 23);
    return h;
}