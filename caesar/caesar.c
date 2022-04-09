#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid_input(string key);
int encrypt_message( string key);

int main(int argc, string argv[])
{
    valid_input(argv[1]);
    string cipher = encrypt_message(argv[1]);
    printf("Ciphertext:  %s\n", cipher);
    return 0;

}


    // implement the encryption equation
        // lower & upper case letters must remain lower and upper, respectively
        // loop through the alphabet based on the input #.

    // ask for input
    // output the text using the encryption eqution
        // after outputting return 0 to exit main


string encrypt_message(string key)
{
    // turn key into an integer
    int k = atoi(key);
    // prompt for user's message
    string plaintext = get_string("Plaintext:  \n");
    // encrypt the message
    char ciphertext[] = {};


    for(int index = 0; index < strlen(text); index++)
    {
        // get the ascii value of each character in plaintext
        int l = plaintext[index];
        // check if l is uppercase
        if (l >= 65 && l <= 90)
        {
            // rotate letter by: (p + key)%26
             l = (l + k) % 26;
            // convert new ascii value to letter
            char l_cipher = l;
            // replace the current letter in plaintext
            plaintext[index] = l_cipher;
        }
        // check if l is lowercase
        else if (l >= 97 && l <= 122)
        {
            // rotate letter by: (p + key)%26
             l = (l + k) % 26;
            // convert new ascii value to letter
            char l_cipher = l;
            // replace the current letter in plaintext
            plaintext[index] = l_cipher;
        }
    }
return p;
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







