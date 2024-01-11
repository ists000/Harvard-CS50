#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_number;

    do
    {
        start_number = get_int("Start size: ");
    }
    while (start_number < 9);

    // TODO: Prompt for end size
    int end_number;

    do
    {
        end_number = get_int("End size: ");
    }
    while (start_number > end_number);

    // TODO: Calculate number of years until we reach threshold
    int n = 0;
    int total = start_number;

    if (start_number == end_number)
    {
        printf("Years: 0");
    }
    else
    {
        do
        {
            int born = total / 3;
            int pass = total / 4;
            total = total + born - pass;
            n++;
        }
        while (total < end_number);
    }

    // TODO: Print number of years
    printf("Years: %i\n", n);
}