#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


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
    //*p = *c;

    // prints out the address of *c (which is now equal to *p)
    printf("%p\n", c);

    // prints out the address of *p
    printf("%p\n", p);

    // prints out the integer value at the address *c
    printf("%i\n", *c);

    // prints out the integer value at address *p
    printf("%i\n", *p);

    // strings are actually a array of chars with a pointer that points to the first element of the array stored in a variable
    // the compiler adds a \0 to the end of the array to indicate the end of the string/ array of chars

    // creates a pointer to the first elemnt of the char array
    // char* is the data type and is a different data type from char (without the '*')
    // a regular char data type takes 1 byte in memory, for storing a binary representation for an ASCII value that represents a char
    // char* takes 4 or 8 bytes, depending on the system, and they represent the size of the address, which points to the first element in the array 'Hi!"
    char* s = "Hi!";

    // stores the address of the array's second position "i"
    char* str = &s[1];

    // prints the char, or \0 in this case, at index [3] of the array
    printf("%c\n", s[3]);

    // prints the address of index 3 of the array by using the '&' operator directly
    printf("address s[3]: %p\n", &s[3]);

    // uninitialized char variable
    // char* t = NULL;

    // t refers now to the same variable
    // t and s have the same address
    // t = s;

    // printf("%p\n", t);
    printf("address *s: %p\n", s);

    // create a proper copy of a variable by making space in memory first
    // creates memory for whatever is the length of t plus one byte for the Nul character at the end
    // malloc returns a pointer to the memory
    char *x = malloc(strlen(s) + 1);
    // if malloc cannot give you memory it returns NULL
    if (x==NULL)
        {
        printf("error");
        return 1;
        }

    // copies whatever is at address s to x
    strcpy(x, s);

    // make changes to string x to prove *x, *s point to different addresses
    x[0] = tolower(x[0]);

    printf("x: %s\n", x);
    printf("s: %s\n", s);

    free(x);
}