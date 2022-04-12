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
    return false;
}
