/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    
    // convert input scale to a number
    int nfactor = atoi(argv[1]);
    
    // nfactor conditions
    if (nfactor < 1 || nfactor > 100)
    {
        printf("Scaling factor must be >1 and <100");
        return 1;
    }
    
    // remember file names
    char* infile = argv[2];
    char* outfile = argv[3];
    
    // open input file & condition
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }
    
    // open output file & condition
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }
    
    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    // determine original variables
    int oldpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int oldbiWidth = bi.biWidth;
    int oldbiHeight = abs(bi.biHeight);
    
    // determine new variables
    bi.biWidth *= nfactor;
    bi.biHeight *= nfactor;
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    // change headerfiles
    bi.biSizeImage = ((bi.biWidth * sizeof(RGBTRIPLE)) + padding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over height
    for (int i = 0; i < oldbiHeight; i++)
    {
        // vertical copy nfactor times
        for (int j = 0; j < nfactor; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < oldbiWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // horizontal copy nfactor times
                for (int l = 0; l < nfactor; l++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
    
            // add padding
            for (int m = 0; m < padding; m++)
            {
                fputc(0x00, outptr);
            }
            
            // move file pointer back to beggining of row
            fseek(inptr, -(oldbiWidth * sizeof(RGBTRIPLE)), SEEK_CUR);
        }
        // move file pointer forward to next row
        fseek(inptr, (oldbiWidth * sizeof(RGBTRIPLE)) + oldpadding, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
