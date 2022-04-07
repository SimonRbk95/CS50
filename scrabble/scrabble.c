#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// Array of letters of the alphabet
int CHARS[]={A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

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
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // return the score for each player's word
    // Ignore non-letter characters
    // Handle both upper & lowe case letters

    // loop through string
    int i = 0;
    for (letter = word[i]; n = strlen(word); n++)
    {
        // turn each char into upper or lower, consitency needed
        toupper.(word[i]);
        // ignore non-letter characters by turning each char into its int value
        char c = word[i];
        if (c >= 65 && <= 90)
        {
            

        }


    }
    // compare each char's int value its ASCII value in alphabetical order starting at 65 through 90, inclusive
    // either count or use algebra to determine which char corresponds to what score
    // remember the score of each char
    // add each char's score to compute the total score
    // return the score
}
