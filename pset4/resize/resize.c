/**
 * Resizes a BMP pixel by pixel.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    // remember filenames
    float f;
    sscanf(argv[1], "%f", &f);
    char *infile = argv[2];
    char *outfile = argv[3];
    
    // check resize factor
    if (f < 0.00 || f > 100.00)
    {
        printf("Please enter a float value between 0.00 and 100.00:\n");
        scanf("%f", &f);
    }
    
    // open input file 
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
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
    
    // save input image width and height
    int32_t inWidth = bi.biWidth;
    int32_t inHeight = abs(bi.biHeight);
   
    bi.biWidth *= f;
    bi.biHeight *= f;
    
    // determine padding for scanlines
    int padding = (4 - (inWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outpadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + outpadding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr); 

    // create array to save infile pixels
    RGBTRIPLE *array = malloc(inHeight * inWidth * sizeof(RGBTRIPLE));
    
    if (array == NULL)
    {
        printf("error dynamically allocated array is NULL");
        return 1;
    }
    
    // iterate over infile's scanlines and store pixel values in an array
    for (int i = 0; i < inHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j <inWidth; j++)
        {
            fread(&array[i * inWidth + j], sizeof(RGBTRIPLE), 1, inptr);
        }
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }
    
    // iterate over outfile's lines
    for (int i = 0, biHeight = abs(bi.biHeight), row = 0; i < biHeight; i++, row = i / f)
    {
        // iterate over pixels in outfine lines
        for (int j = 0, col = 0; j < bi.biWidth; j++, col = j / f)
        {
            // write RGB triple to outfile using infile pseudo multidimentional array
            fwrite(&array[row * inWidth + col], sizeof(RGBTRIPLE), 1, outptr);
        }
        // add padding
        for (int k = 0; k < outpadding; k++)
        {
            fputc(0x00, outptr);
        }
    }
    // free dynamically allocated memory
    free(array);
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
