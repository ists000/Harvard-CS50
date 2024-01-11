#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool only_digits(string text);
char rotate(char p, int k);

int main(int argc, string argv[])
{
    // 1. make sure only one commend line or the commend line only contain digits when input. if not, print out the error messgage and return 1.
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 3. convert argv[1] from string to int
    int key = atoi(argv[1]);

    // 4. prompt the text from user.
    string plain_text = get_string("plaintext: ");

    // 6. use function to transfer the text to secret text
    int length_plaintext = strlen(plain_text);
    char result;

    printf("ciphertext: ");     // print out the title

    // use function
    for (int j = 0; j < length_plaintext; j++)
    {
        result = rotate(plain_text[j], key);
        printf("%c", result);
    }
    printf("\n");

    return 0;
}

// 2. make sure only digits are inputted into commend line.
bool only_digits(string text)
{
    int length_text = strlen(text);
    for (int i = 0; i < length_text; i++)
    {
        if (!isdigit(text[i]))
        {
            return false;
        }
    }
    return true;
}

// 5. a function which could convert the input to secret output
char rotate(char p, int k)
{
    char c, s;
    // if the char is lowercase, a-z=97-122 -97
    if (islower(p))
    {
        c = ((p - 97) + k) % 26;
        s = c + 97;
        return s;
    }
    // if the char is uppercase, A-Z=65-90 -65
    else if (isupper(p))
    {
        c = ((p - 65) + k) % 26;
        s = c + 65;
        return s;
    }
    // if the char is space or symbol, print out directly.
    else
    {
        return p;
    }
}