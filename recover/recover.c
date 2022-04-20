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
// int block_size = 512;

// pointer to dynamic memory for blocks to be read
BYTE *buffer = malloc(512);

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
int found = 0;

char filename[8];

// repeat until end of block:
while (fread(buffer, sizeof(BYTE), 512, raw_file))
{
    // If start of new JPEG
    if (buffer[0] == 0xff
        && buffer[1] == 0xd8
        && buffer[2] == 0xff
        && (buffer[3] & 0xf0) == 0xe0)
    {
        // make a new JPEG and keep track of it
        sprintf(filename, "%03i.jpg", JPEG_COUNTER);
        // open the file with write privileges
        img = fopen(filename, "w");
        JPEG_COUNTER++;
    }

    if (img != NULL)
    {
        fwrite(buffer, 512, 1, img);
    }
}
free(buffer);
fclose(img);
fclose(raw_file);
}