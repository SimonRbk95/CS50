#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{

// new type to store a byte of data
typedef uint8_t BYTE;
int block_size = 512;

// pointer to dynamic memory for blocks to be read
BYTE *buffer = malloc(block_size);

// open memory card
FILE *raw_file = fopen(argv[1], "rb");

// write to
FILE *img = NULL;

// keep track of files created
int JPEG_COUNTER = 0;

// repeat until end of block:
while (fread(buffer, sizeof(BYTE), block_size, raw_file) != 0)
{
    // If start of new JPEG
    if (buffer[0] == 0xff
        && buffer[1] == 0xd8
        && buffer[2] == 0xff
        && (buffer[3] & 0xf0) == 0xe0)
    {
        // count the number of images
        JPEG_COUNTER++;

        // check if file opened
        if (img != NULL)
        {
            // close file
            fclose(img);

        // make a new JPEG and keep track of it
        char filename[8];
        sprintf(filename, "%03i.jpg", JPEG_COUNTER);

        // open the file with write privileges
        img = fopen(filename, "w");

        // write the current block to it
        fwrite(buffer, block_size, 1, img);
        }
    }
    else
    {
        fwrite(buffer, block_size, 1, img);
    }
}
free(buffer);
fclose(img);
fclose(raw_file);
}