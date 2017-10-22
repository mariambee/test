/**
 * Meriton Ibrahimi
 * Harvard CS50
 * vigenere
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string vigenere(string keyword, string plaintext);

int main(int argc, string argv[])
{
    // check first condtion
    if (argc != 2)
    {
        printf("One key word please...\n");
        return 1;
    }
    string keyword = argv[1];
    int keylength = strlen(keyword);
    // check second condition
    for (int i = 0; i < keylength; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("One key word please...\n");
            return 1;
        }
    }
    // obtain plaintext
    string plaintext = GetString();
    // get back cyphered text
    string cyphercomplete = vigenere(keyword, plaintext);
    // print cypered text to screen
    printf("%s\n", cyphercomplete);
}

string vigenere(string keyword, string plaintext)
{
    string cyphertext = plaintext;
    int keylength = strlen(keyword);
    int keyindex = 0;
    // loop over plaintext
    for (int i = 0, s = strlen(plaintext); i < s; i++)
    {
        // check for alpha characters in plaintext
        if (isalpha(plaintext[i]))
        {
            // check for lower alpha plaintext
            if (islower(plaintext[i]))
            {
                //check if keyword is alpha lower
                if (islower(keyword[keyindex]))
                {
                    cyphertext[i] = ((plaintext[i] - 'a' + (keyword[keyindex] - 'a')) % 26) + 'a';
                }
                // else keyword is alpha upper
                else
                {
                    cyphertext[i] = ((plaintext[i] - 'a' + (keyword[keyindex] - 'A')) % 26) + 'a';
                }
            }
            // else alpha plaintext must be upper
            else
            {
                // check if keyword is alpha upper
                if (isupper(keyword[keyindex]))
                {
                    cyphertext[i] = ((plaintext[i] - 'A' + (keyword[keyindex] - 'A')) % 26) + 'A';
                }
                // else keyword is alpha lower
                else
                {
                    cyphertext[i] = ((plaintext[i] - 'A' + (keyword[keyindex] - 'a')) % 26) + 'A';
                }
            }
            // index key
            keyindex = keyindex + 1;
            // loop key back if needed
            if (keyindex >= keylength)
            {
                keyindex = 0;
            }
        }
        // else other characters are not alpha and are not cyphered
        else
        {
            cyphertext[i] = plaintext[i];
        }
    }
    // return completed cyphered text to main
    return cyphertext;
}