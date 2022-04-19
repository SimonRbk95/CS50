#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void)
{


// new type to store a byte of data
typedef uint8_t BYTE;
int block_size = 512;

// pointer to dynamic memory for blocks to be read
BYTE *buffer = malloc(block_size);

printf("size: %lu\n", sizeof(buffer));

}