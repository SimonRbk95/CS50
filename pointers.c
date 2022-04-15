#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


int main(void)
{
    int a = 2;

    // '&' is the address extraction operator
    // variable declared as '*p' for instance gets assigned the address in memory
    // variable declared as '*p' can also be used to store the value located at its address in a new variable

    // how to create multiple pointers in one line
    int* pa, *pb, *pc;

    // &a gets the address and assigns it to *p
    int* p = &a;

    // b gets assigned the value located at the adress that is assigned to *p
    int b = *p;

    // *c gets assigned the address of variable 'b'
    int* c = &b;

    // overwrites the value stored at *p/ in variable 'b'
    b = 3;

    // stores the value that *c points to in the variable stored at location *p
    *p = *c;

    // prints out the address of *c (which is now equal to *p)
    printf("%p\n", c);

    // prints out the address of *p
    printf("%p\n", p);

    // prints out the integer value at the address *c
    printf("%i\n", *c);

    // prints out the integer value at address *p
    printf("%i\n", *p);

    // strings are actually a array of chars with a pointer that points to the first element of the array stored in a variable
    // the compiler adds a \0 to indicate the end of the string/ array of chars

    // creates a new string so to speak
    char* s = "Hi!";

    // stores the address of the array's second position "i"
    char* str = &s[1];

    // prints the char, or \0 in this case, at index [3] of the array
    printf("%c\n", s[3]);

    // prints the address of index 3 of the array by using the & operator directly
    printf("%p\n", &s[3]);

    // uninitialized char variable
    char* t = NULL;

    printf("%c", *t);
}