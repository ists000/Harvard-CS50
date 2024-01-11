#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get size of grid
    int n;
    do
    {
        n = get_int(" Size: ");
    }
    while (n < 1);

    // Print grid of bricks
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
    /* another way
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get size of grid
    int n = get_size();

    // print grid of bricks
    print_grid(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}
    */

// if don't know what to do, do the presudocode
