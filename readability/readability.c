#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);

int main(void)
{
    string text = get_string("Text: \n");
    printf("%s \n", text);
    printf("%i \n", count_letters(text));
    printf("%i \n",count_words(text));

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
           letter_count += 1;
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
        char next_chr = text[i + 1];
        if (! isalpha(chr) && ! isspace(next_chr))
        {
            word_count +=1;
        }
        if (! isalpha(chr) && ! isspace(next_chr))

    }
    return word_count;
}

// count_words
// count_sentences