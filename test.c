#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool vote(string name);

int main(int argc, string argv[])
{
    int a = 2;
    int *p = &a;
    int b = *p;
    int *c = &b;
    printf("%p\n", &a);
    printf("%p\n", &b);
}