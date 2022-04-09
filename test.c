#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    char upper[] = {'A', ' ', 'B', '!'};
    printf("%s\n", upper);
    char A = 'A';
    int ascii = A;
    (printf("ascii: %i\n", ascii));
    char Anew = ascii + 1;
    (printf("new ascii: %c\n", Anew));
    upper[0] = Anew;
    (printf("new array: %s\n", upper));
}