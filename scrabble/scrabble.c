#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// Array of letters of the alphabet
char CHARS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    char chr;
    for (int i = 0; i < strlen(word); i++)
    {
        // store word[i] in a variable to be able use upper function on it
        chr = word[i];
        // turn each char into upper or lower, consitency needed
        chr = toupper(chr);
        // get the ASCII value
        int l = chr;
        // only consider ASCII values that represent uppercase letters
        if (l >= 65 && l <= 90)
        {
            // loop through int CHARS, look for a letter that matches word[i]/chr and remember int CHARS' index
            for (int j = 0; j < strlen(CHARS); j++)
            {
                if (CHARS[j] == chr)
                {
                    // add Points[CHARS' index] to a variable that keeps track of the points -> score += POINTS[chars' index]
                    score += POINTS[j];
                }
            }
        }
    }
    return score;
}
