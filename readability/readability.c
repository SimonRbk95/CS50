#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string text);

int main(void)
{
    string text = getstring("Text: \n");
    printf("%s", text);
    // printf(count_letter(text));

}

int count_letters(string text)
{
    int letter_count = 0;
    // loop through the text's letters
    for (int i = 0; i < strlen(text); i++)
    {
        // store text[i] in a variable to use upper function on it
        char chr = text[i];
        // turn each char into uppercased letters
        chr = toupper(chr);
        // get the ASCII value
        int l = chr;
        // only consider ASCII values that represent uppercase letters
        if (l >= 65 && l <= 90)
        {
           int letter_count += 1;
        }
    }
    return letter_count;
}

int count_words(string text)
{
    int word_count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char chr = text[i];
        if (!= int isalpha(char chr))
        {
            word_count +=1;
        }

    }
}

// count_words
// count_sentences