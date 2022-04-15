#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool vote(string name);

int main(int argc, string argv[])
{
    int a = 2;
    // &a gets the address and assigns it to *p
    int *p = &a;

    // b gets assigned the value located at the adress that is assigned to *p
    int b = *p;

    // *c gets assigned the address of b
    int *c = &b;

    // prints out the integer value at the address *c
    printf("%i\n", *c);

    //prints out the integer value at address *p
    printf("%i\n", *p);
}