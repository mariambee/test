/**
 * Meriton IBrahimi
 * Harvard CS50
 * greedy
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    printf("Howdy, how much change do I owe ya...\n");
    // "f" for float amount of change owed
    float f;
    // loop to get a change value > 0
    do
    {
        printf("$");
        f = GetFloat();
    }
    while (f < 0);
    // convert to cents
    f = f * 100;
    // "i" for integer amount of change owed
    // round to nearest cent
    int i = round(f);
    // "c" for counter
    int c = 0;
    // break down the amount
    while (i >= 25)
    {
        i = i - 25;
        c = c + 1;
    }
    while (i >= 10)
    {
        i = i - 10;
        c = c + 1;
    }
    while (i >= 5)
    {
        i = i - 05;
        c = c + 1;
    }
    while (i >= 1)
    {
        i = i - 1;
        c = c + 1;
    }
    printf("%i\n", c);
}