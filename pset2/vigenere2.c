/**
 * Meriton Ibrahimi
 * Harvard CS50
 * vigenere
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check fist condtion
    if (argc != 2)
    {
        printf("One key word please...\n");
        return 1;
    }
    else
    {
        int keylength = strlen(argv[1]);
        string keyword = argv[1];
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
        int keyindex = 0;
        // run cypher
        for (int i = 0, s = strlen(plaintext); i < s; i++)
        {
            // check for alpha characters in plaintext
            if (isalpha(plaintext[i]))
            {
                // check for lower alpha
                if (islower(plaintext[i]))
                {
                    if (islower(keyword[keyindex]))
                    {
                        printf("%c", ((plaintext[i] - 97 + (keyword[keyindex] - 97)) % 26) + 97);
                    }
                    // else keyword is alpha upper
                    else
                    {
                        printf("%c", ((plaintext[i] - 97 + (keyword[keyindex] - 65)) % 26) + 97);
                    }
                }
                // else alpha must be upper
                else
                {
                    if (isupper(keyword[keyindex]))
                    {
                        printf("%c", ((plaintext[i] - 65 + (keyword[keyindex] - 65)) % 26) + 65);
                    }
                    // else keyword is alpha lower
                    else
                    {
                        printf("%c", ((plaintext[i] - 65 + (keyword[keyindex] - 97)) % 26) + 65);
                    }
                }
                // index key
                keyindex = keyindex + 1;
                if (keyindex >= keylength)
                {
                    keyindex = 0;
                }
            }
            // since alphas checked, print other characters unchanged
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        // return 0 to end program
        return 0;
    }
}