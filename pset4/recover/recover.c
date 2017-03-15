//
//  recover.c
//  recover
//
//  Created by Davy Hausser on 05/02/2017.
//  Copyright © 2017 Davy Hausser. All rights reserved.
//

#include <stdio.h>
#include <stdint.h>
typedef uint8_t  BYTE;

int main(int argc, const char * argv[]) {
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }
    
    // remember filenames
    const char *infile = argv[1];
    
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }
    
    BYTE buffer[512] = {};
    FILE *outptr = NULL;
    char filename [7] = {};
    int filenum = 0;
    
    while (fread(&buffer, 512 * sizeof(BYTE), 1, inptr))
    {
        // check start of a new jpeg
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename,"%03i.jpg", filenum);
            outptr = fopen(filename, "w");
            filenum++;
        }
        
        // continue writing already found jpeg
        if (outptr != NULL)
        {
            fwrite(&buffer, 512 * sizeof(BYTE), 1, outptr);
        }
    }
    
    fclose(inptr);
    
    fclose(outptr);

    return 0;
}
