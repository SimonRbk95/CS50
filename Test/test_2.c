#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

int main (void){
    char *word = "string";
    unsigned int x = toupper(word[0] -'A');
    printf("%i\n", x);
}
