#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    char upper[] = {'A', 'B', '!'};
    int ascii = upper[0];
    (printf("ascii: %i\n", ascii));
    char Anew = ascii + 1;
    (printf("new ascii: %c\n", Anew));
    upper[0] = Anew;
    (printf("new array: %s\n", upper));
}