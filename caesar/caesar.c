#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int index = 0;
    if(! argv[1])
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    while(index < strlen(argv[1]))
    {
            // get ASCII value
            int ascii = argv[1][index];
            // check if it is a digit
            if (argv[1][index] >= 48 && argv[1][index] <= 57)
            {
                index += 1;
                printf("ascii: %i",argv[1][index]);
            }
        }
    }

    // 1 if there is no parameter or more than one return 1 with an error message





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
  


}