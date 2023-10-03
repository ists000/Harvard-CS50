#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // asking user for the height of the pyramids
    int height;
    height = get_int("This program could present the mario pyramids, please input a number between 1 and 8. ");

    // check the input if over 8 or less than 1, until the input between 1 and 8
    while (height > 8 || height < 1)
    {
        height = get_int("Please make sure the input number between 1 and 8. Please re-enter.");
    }

    // create the pyramids according to the input number
    for (int a = 1; a <= height; a++)
    {
        for (int b = height; b > a; b--)
        {
            printf(" ");
        }
        for (int c = 1; c <= a; c++)
        {
            printf("#");
        }
        printf("  ");
        for (int d = 1; d <= a; d++)
        {
            printf("#");
        }
        printf("\n");
    }
}