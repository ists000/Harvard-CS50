#include <cs50.h>
#include <stdio.h>

typedef struct
{
    string name;
    int votes;
}
candidate;      // define a struct type

candidate get_candidate(string prompt);

int main(void)
{
    candidate candidate_array[3];
    for (int i = 0; i < 3; i++)
    {
        candidate_array[i] = get_candidate("Enter a candidate: ");
    }
}

candidate get_candidate(string prompt)
{
    printf("%s\n", prompt);

    candidate c;
    c.name = get_string("Enter a name: ");
    c.votes = get_int("Enter a number of votes: ");
    return c;
}