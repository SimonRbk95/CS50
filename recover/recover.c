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
FILE *raw_file = fopen(argv[1], "r");
// repeat until end of block:
while (fread(buffer, 1, block_size, raw_file) == block_size)
{
// If start of new JPEG
    if (buffer[0] == 0xff
        && buffer[1] == 0xd8
        && buffer[2] == 0xff
        && (buffer[3] & 0xf0) == 0xe0)
    {
        // make a new JPEG and keep track of it
        sprintf(filename, "%03i.jpg", 2);
        FILE *img = fopen(filename, "w");
        fwrite(buffer,  );
    }
    // If first JPEG
        // make a new JPEG and open it
        // f(write) to the new file
    // Else
        // close the file I've been already writing to
// Else
    // If already found JPEG
        // keep writing to it
}


// close any remaining files

}