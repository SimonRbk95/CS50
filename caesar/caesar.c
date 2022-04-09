#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    string digits = "123456789";
    int index = 0;

    while(index < strlen(argv[1]))
    {
        for (int i = 0; int i < 9; i++)
        {
            if (argv[1][index] == i)
            {
                index += 1;
            }
        }
    }

    // 1 if there is no parameter or more than one return 1 with an error message
    if(! argv[1])
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }




    else if ()
    {
    // 2 check if the argument's characters are digits

    printf("This the key's first index: %c", argv[1][1]);
    // check
    }


    //must take one parameter


    // 3 if not step 2
    // implement the encryption equation
        // lower & upper case letters must remain lower and upper, respectively
        // loop through the alphabet based on the input #.

    // ask for input
    // output the text using the encryption eqution
        // after outputting return 0 to exit main
    int a = (int) argv[1] + 2;


}