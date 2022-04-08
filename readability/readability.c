#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int grade_calculator(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: \n");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int grade = grade_calculator(letters, words, sentences);
    printf("Grade: %i \n", grade);
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
        if (ascii == 46 || ascii == 63 || ascii == 33)
        {
            count +=1;
        }
    }
    return count;
}

int grade_calculator(letters, words, sentences)
{
    float L = letters/words * 100;
    float S = sentences/words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    float round(float index);
    return index;

}
// count_words
// count_sentences