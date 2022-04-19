#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 // open memory card
 // repeat until end of card:
    // Read 512 byte into a buffer
    // If start of new JPEG
        // If first JPEG
            // make a new JPEG and open it
            // f(write) to the new file
        // Else
            // close the file I've been already writing to
    // Else
        // If already found JPEG
            // keep writing to it
// close any remaining files

}