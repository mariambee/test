/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <cs50.h>
#define BUFFERSIZE 512

int main(void)
{
    // open infile
    FILE* infile = fopen("card.raw", "r");
    // check for NULL
    if (infile == NULL)
    {
        printf("Could not open card.raw");
        return 1;
    }
    // set buffer
    unsigned char buffer[BUFFERSIZE];
    // intilaize outfile 
    FILE* outfile = NULL;
    // set file counter and name
    int filecounter = 0;
    char filename[8];
    // loop over inflie until its end
    while (fread(&buffer, sizeof(buffer), 1, infile) == 1)
    {
        // find JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && 
           buffer[3] >= 0xe0 && buffer[3] <= 0xef)
        {
            // if there is an outfile open, close it
            if (filecounter > 0)
            {
                fclose(outfile);
            }
            // write to a new outfile
            sprintf(filename, "%03d.jpg", filecounter);
            outfile = fopen(filename, "w");
            fwrite(&buffer, BUFFERSIZE, 1, outfile);
            filecounter++;
        }
        // if new JPEG signature not found write into current JPEG outfile
        else if (filecounter > 0)
        {
            fwrite(&buffer, BUFFERSIZE, 1, outfile);
        }
    }
    fclose(outfile);
    fclose(infile);
    return 0;
}