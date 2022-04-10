#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid_input(int argc, string key);
string encrypt_message( string key);

int main(int argc, string argv[])
{
    valid_input(argc, argv[1]);
    string cipher = encrypt_message(argv[1]);
    printf("Ciphertext: %s\n", cipher);
}

string encrypt_message(string key)
{
    // turn key into an integer
    int k = atoi(key);
    // prompt for user's message
    string plaintext = get_string("Plaintext:  ");
    // replace each char of plaintext
    for(int index = 0; index < strlen(plaintext); index++)
    {
        // get the ascii value of each character in plaintext
        int l = plaintext[index];
        // check if l is uppercase
        if (l >= 65 && l <= 90)
        {
            // keep track of alphabet starting at A
            int count = l - 65;
            int new_l = (count + k) % 26;
            l = new_l + 65;
            // convert new ascii value to letter
            char cipher = l;
            // replace the current letter in plaintext
            plaintext[index] = cipher;
        }

        // check if l is lowercase
        else if (l >= 97 && l <= 122)
        {
            // keep track of alphabet starting at A = 0
            int count = l - 97;
            // get rotated letter
            char cipher = rotate(count);
            // the value to which the letter in the alphabet should be rotated
            // int new_l = (count + k) % 26;
            // update the ascii value of rotated letter
            // l = new_l + 97;
            // turn ascii int value back to char
            //char cipher = l;
            // replace the current letter in plaintext
            plaintext[index] = cipher;
        }
    }
return plaintext;
}

int valid_input(int argc, string key)
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        exit(1);
    }
    // string key = argv[1];
    int index = 0;
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
                exit(1);
            }
    }
    return 0;
}

char rotate(int letter)
{
    // the value to which the letter in the alphabet should be rotated
    int new_l = (letter + k) % 26;
    // update the ascii value of rotated letter
    int cipher = new_l + 97;
    // return the char of new ascii value
    return (char) cipher;
}