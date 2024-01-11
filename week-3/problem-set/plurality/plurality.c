#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

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
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // use bubble sort, from large to small;
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < (candidate_count - i - 1); j++)
        {
            if (candidates[j].votes < candidates[j + 1].votes)
            {
                candidate buffer = candidates[j];
                candidates[j] = candidates[j + 1];
                candidates[j + 1] = buffer;
            }
        }
    }

    // if the first one greater than the second one, the first one is the biggest, print out the first one.
    if (candidates[0].votes > candidates[1].votes)
    {
        printf("%s\n", candidates[0].name);
    }
    // if there are some equal data, check how many equal data and print them out.
    else
    {
        int check_count = 0;
        for (int k = 0; k < candidate_count; k++)
        {
            if (candidates[0].votes == candidates[k].votes)
            {
                check_count += 1;
            }
        }
        for (int l = 0; l < check_count; l++)
        {
            printf("%s\n", candidates[l].name);
        }
    }

    return;
}