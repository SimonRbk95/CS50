#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool vote(string name);

int main(int argc, string argv[])
{
    string name = get_string("Name: \n");
    if (!vote(name))
    {
        printf("Invalid vote\n");
    }
    else
    {
        printf("Great Success!\n");
    }

    // Display winner of election
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // find candidate
    // increment his vote
    // return True for successful ballot
    return true;
}


    int winner_count = 1;
    for (int i = candidate_count - 1; i >= 0; i--)
    {
        if (candidates[i].votes == candidates[i - 1].votes)
        {
            winner_count++;
        }
        else
        {
            for (int j = candidate_count - 1; j > candidate_count - winner_count; j--)
            {
                printf("%s\n", candidates[j].name);
            }
            break;
        }
    }