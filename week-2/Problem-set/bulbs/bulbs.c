#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string input = get_string("Messages: ");

    // identify the letter and make it turn to dec
    int length = strlen(input);

    int array[] = {0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < length; i++)
    {
        int dec_letter = input[i];

        for (int j = 7; j >= 0; j--)
        {
            array[j] = (dec_letter % 2);
            dec_letter /= 2;
        }
        for (int k = 0; k < 8; k++)
        {
            print_bulb(array[k]);
        }
        printf("\n");
    }
    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
