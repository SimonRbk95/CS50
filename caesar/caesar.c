#include <cs50.h>
#include <stdio.h>
#include <string.h>

int valid_input(string key);

int main(int argc, string argv[])
{
    printf("First Digit: %c\n",argv[1][0]);
    printf("Second Digit: %c\n",argv[1][1]);
    printf("key = %s", argv[1]);
    printf("First ascii convert: %i\n", (int) argv[1][0]);
    printf("Secon ascii convert: %i\n", (int) argv[1][1]);
    valid_input(argv[1]);
}

    // 1 if there is no parameter or more than one return 1 with an error message

int valid_input(string key)
{
    int index = 0;
    // check if
    if(! key)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // check if it is a digit
    while(index < strlen(key))
    {
            // cast parameter into integer to get ascii
            if ((int) key[index] >= 48 && (int) key[index] <= 57)
            {
                index += 1;
                // test
                printf("ascii: %i\n",key[index]);
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
    }
    return 0;
}



    // 2 check if the argument's characters are digits

    // printf("This the key's first index: %c", argv[1][1]);
    // check



    //must take one parameter


    // 3 if not step 2
    // implement the encryption equation
        // lower & upper case letters must remain lower and upper, respectively
        // loop through the alphabet based on the input #.

    // ask for input
    // output the text using the encryption eqution
        // after outputting return 0 to exit main



