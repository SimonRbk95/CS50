#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        // ! means a False will be considered True, triggering the  if condition
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // find candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            // successfull ballot
            return true;
        }
    }
    // if not found
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // search the highest number in the candidates.votes array
    // bubble sort
    int swap_counter = 1;
    while (swap_counter > 0)
    {
        swap_counter = 0;
        // loop over candidates considering the last index is -1 the count and we are looking one further
        for (int i = 0; i <= candidate_count - 2; i++)
        {
            if (candidates[i].votes > candidates[i + 1].votes)
            {
                swap_counter++;
                // temporary storage for array item to be swapped
                int temp_vote = candidates[i].votes;
                string temp_name = candidates[i].name;
                // swap array elements
                candidates[i].votes = candidates[i + 1].votes;
                candidates[i + 1].votes = temp_vote;
                candidates[i].name = candidates[i + 1].name;
                candidates[i + 1].name = temp_name;
            }
        }
    }
    // determine winner, searching from highest to lowest
    for (int i = candidate_count - 1; i >= 0; i--)
    {
        if (candidates[i].votes > candidates[i - 1].votes)
        {
            printf("%s\n", candidates[i].name);
            break;
        }
        else if (candidates[i].votes == candidates[i - 1].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}