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
    int count = 0;
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
           count += 1;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char chr = text[i];
        char next_chr = text[i + 1];
        // count each word by checking spaces
        if (isspace(next_chr))
        {
            count +=1;
        }
        // count the last word of the sentence
        if (i + 1 == strlen(text))
        {
            count += 1;
        }

    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        char chr = text[i];
        int ascii = chr;
        // count each word by checking spaces
        /// if (ascii == 46 || ascii == 63 || ascii == 33)
        if (chr == '.' || chr == '!' || chr == "?")
        {
            count +=1;
        }
    }
    return count;
}
// count_words
// count_sentences