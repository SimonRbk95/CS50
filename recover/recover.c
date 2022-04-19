#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{

if (argc != 2)
{
    printf("Usage: ./recover Filename");
    return 1;
}

// new type to store a byte of data
typedef uint8_t BYTE;
int block_size = 512;

// pointer to dynamic memory for blocks to be read
BYTE *buffer = malloc(sizeof(BYTE) * block_size);

// open memory card
FILE *raw_file = fopen(argv[1], "r");

if(raw_file == NULL)
{
    printf("File cannot be opened!");
    return 1;
}

// write to
FILE *img = NULL;

// keep track of files created
int JPEG_COUNTER = 0;

char filename[8];

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
        // if first image
        if(JPEG_COUNTER == 1)
        {
            // make a new JPEG and keep track of it
            sprintf(filename, "%03i.jpg", 0);
            // open the file with write privileges
            img = fopen(filename, "w");
            // write the current block to it
            fwrite(buffer, block_size, 1, img);
            // printf("sizeof(buffer)= %i", sizeof(buffer));
        }
        else
        {
            // close previous image
            fclose(img);
            // make a new JPEG and keep track of it
            sprintf(filename, "%03i.jpg", JPEG_COUNTER - 1);
            img = fopen(filename, "w");
            fwrite(buffer, block_size, 1, img);
        }
    }
    if (img != NULL)
    {
        fwrite(buffer, sizeof(buffer), 1, img);
    }
}
free(buffer);
fclose(img);
fclose(raw_file);
}