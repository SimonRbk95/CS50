#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    char digits[] = "123456789";
    char key[] = (int) argv[1];

    printf("This the key's first index: %c", key[1]);
    
    //must take one parameter
    // 1 if there is no parameter or more than one return 1 with an error message
    // 2 check if the argument's characters are digits
    // 3 if not step 2
    // implement the encryption equation
        // lower & upper case letters must remain lower and upper, respectively
        // loop through the alphabet based on the input #.

    // ask for input
    // output the text using the encryption eqution
        // after outputting return 0 to exit main
    int a = (int) argv[1] + 2;


}