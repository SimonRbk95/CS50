#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int valid_input(string key);
string encrypt_message( string key);

int main(int argc, string argv[])
{
    valid_input(argv[1]);
    string cipher = encrypt_message(argv[1]);
    printf("Ciphertext:  %s\n", cipher);
}

string encrypt_message(string key)
{
    // turn key into an integer
    int k = atoi(key);
    // prompt for user's message
    string plaintext = get_string("Plaintext:  \n");
    // replace each char of plaintext
    for(int index = 0; index < strlen(plaintext); index++)
    {
        // get the ascii value of each character in plaintext
        int l = plaintext[index];
        // test
        printf("current ascii: %i\n", l);
        // check if l is uppercase
        if (l >= 65 && l <= 90)
        {
            // rotate letter by: (p + key)%26
            int rotation_value = (l + k) % 26;
            // keep track of alphabet starting at A
            int count = l - 65;
            // increase the count to rotate through the alphabet
            for (int n = rotation_value; n > 0; n--)
                if(count < 25)
                {
                    count++;

                }
                else
                {
                    count = 0;
                }
            // update the ascii value of rotated letter
            l = count + 65;
            printf("l = %i\n", l);
            // convert new ascii value to letter
            char cipher = l;
            printf("-> new letter: %c\n", cipher);
            // replace the current letter in plaintext
            plaintext[index] = cipher;
        }

        // check if l is lowercase
        else if (l >= 97 && l <= 122)
        {
            // keep track of alphabet starting at A
            int count = l - 65;
            // increase the count to rotate through the alphabet
            for (int n = rotation_value; n > 0; n--)
                if(count < 25)
                {
                    count++;
                }
                else
                {
                    count = 0;
                }
            // update the ascii value of rotated letter
            l = count + 65;
            printf("l = %i\n", l);
            // convert new ascii value to letter
            char cipher = l;
            printf("-> new letter: %c\n", cipher);
            // replace the current letter in plaintext
            plaintext[index] = cipher;
        }
    }
return plaintext;
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
