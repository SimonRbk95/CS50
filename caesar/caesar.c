#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid_input(string key);

int main(int argc, string argv[])
{
    valid_input(argv[1]);
    // encrypt_message(argv[1]);
    



}



    // implement the encryption equation
        // lower & upper case letters must remain lower and upper, respectively
        // loop through the alphabet based on the input #.

    // ask for input
    // output the text using the encryption eqution
        // after outputting return 0 to exit main


int encrypt_message(key)
{
    // turn key into an integer
    int key = atoi(key);
    // prompt for user's message
    string text = get_string("Encrypt:  \n");
    // encrypt the message
    for(int index = 0; index < strlen(text); index++)
    {
        if(text)
        {

        }


    }



}









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
    return 0;
}







