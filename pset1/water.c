/**
 * Meriton IBrahimi
 * Harvard CS50
 * water
 */

#include <stdio.h>
#include <cs50.h>

// I wanted to give functions a shot
int Shwr2bttls(void);

int main(void)
{
    int l = Shwr2bttls();
    printf("That's rougly %i bottles of water!\n", l);
}

int Shwr2bttls(void)
{
    printf("How long, in minutes, does it take you to shower?\n");
    // "l" for shower length
    int l = GetInt();
    return l * 12;
    // 1.5 gallons/min times 128 oz/min divided by 16 oz/watter bottle is 12
}
