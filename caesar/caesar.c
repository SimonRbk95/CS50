#include <cs50.h>
#include <stdio.h>
#include <string.h>

int valid_input(string key);

int main(int argc, string argv[])
{
    int key = valid_input(argv[1]);
    (printf("key = %i", key));
}



    // implement the encryption equation
        // lower & upper case letters must remain lower and upper, respectively
        // loop through the alphabet based on the input #.

    // ask for input
    // output the text using the encryption eqution
        // after outputting return 0 to exit main











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
                // check next digit
                index += 1;
            }
            // if it is not a digit exit out
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
    }
    return (int) key;
}







