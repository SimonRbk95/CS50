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
            // increment candidates' vote
            // test
            // printf("true");
            candidates[i].votes++;
            // successfull ballot
            return true;
        }
        //test
        // printf("name = %s\n", name);
        // printf("candidates[%i].name = %s\n", i, candidates[i].name);
    }
    // if not found return false
    //test
    printf("false\n");
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // search the highest number in the candidates.votes array
    // sort the array lowest to highest
    // bubble sort
    // set swap counter to non-zero value
    printf("Candidate Count: %i\n", candidate_count);
    printf("Before the swap:\n");
    printf("array index 0: %i\n", candidates[0].votes);
    printf("array index 1: %i\n", candidates[1].votes);
    printf("array index 2: %i\n", candidates[2].votes);

    int swap_counter = 1;
    while (swap_counter > 0)
    {
        swap_counter = 0;
        // loop over candidates considering the last index is -1 the count and we are looking one further
        for (int i = 0; i <= candidate_count - 2; i++)
        {
            if (candidates[i].votes > candidates[i + 1].votes)
            {
                swap_counter +=1;
                // temporary storage for array item to be swapped
                int temp_vote = candidates[i].votes;
                int temp_name = candidates[i].names;
                // swap array elements
                candidates[i].votes = candidates[i + 1].votes;
                candidates[i + 1].votes = temp_vote;
            }
        }
    }
    printf("\narray index 0: %i\n", candidates[0].votes);
    printf("array index 1: %i\n", candidates[1].votes);
    printf("array index 2: %i\n", candidates[2].votes);
    printf("\narray index 0: %i\n", candidates[0].names);
    printf("array index 1: %i\n", candidates[1].names);
    printf("array index 2: %i\n", candidates[2].names);

    // determine winner, searching from highest to lowest
    for (int i = candidate_count - 1; i >= 0; i--)
    {
        if (candidates[i].votes > candidates[i - 1].votes)
        {
            printf("%s\n", candidates[i].name);
        }
        else if (candidates[i].votes == candidates[i - 1].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

}