// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    uint8_t *header = malloc(sizeof(uint8_t)*HEADER_SIZE);
    if (arr1 == NULL);
        {
            printf("no memory for you");
            return 1;
        }
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header,HEADER_SIZE, 1, output);

    free(arr1);

    uint16_t *buffer = malloc(sizeof(uint16_t));
    if (buffer == NULL);
        {
            printf("no memory for you");
            return 1;
        }
    // loop that reads and writes to another file
    while (fread(buffer, sizeof(uint16_t), 1, input))
    {
        
    }


    // TODO: Read samples from input file and write updated data to output file
    // read sample data, 2-bytes at a time, might require loop
    // store it in a temp variable int16_t data type
    // change temp
    //

    // Close files
    fclose(input);
    fclose(output);
}
