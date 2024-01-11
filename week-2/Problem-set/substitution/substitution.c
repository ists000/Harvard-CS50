#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_input(string text);
char substitute(char p, string k);

int main(int argc, string argv[])
{
    // 1. make sure only input one commend line. if not, show the error and return 1
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // 2. check the number of argv length
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // 3. make sure the commend line input 26 alphabets and not repeat
    if (!check_input(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // 4. output plaintext:
    string plain_text = get_string("plaintext: ");
    // 5. output ciphertext:
    printf("ciphertext: ");

    int length_plain = strlen(plain_text);
    for (int l = 0; l < length_plain; l++)
    {
        char result = substitute(plain_text[l], argv[1]);
        printf("%c", result);
    }
    // 6. output a new line and return 0
    printf("\n");
    return 0;
}

// 3. make sure the commend line input 26 alphabets and not repeat
bool check_input(string text)
{
    // check if all inputs are alphabets
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(text[i]))
        {
            return false;
        }
    }

    // check if there is any repeat alphabet
    int check_array[26] = {0};
    char check_c;
    int check_index;

    for (int j = 0; j < 26; j++)
    {
        check_c = tolower(text[j]);
        check_index = check_c - 'a';

        if (check_array[check_index] == 1)
        {
            return false;
        }
        else
        {
            check_array[check_index] = 1;
        }
    }
    return true;
}

char substitute(char p, string k)
{
    int index;
    char c;
    // calculate the letter p belong to which place in 26 words
    if (islower(p))
    {
        index = p - 97;
        c = tolower(k[index]);
        return c;
    }
    else if (isupper(p))
    {
        index = p - 65;
        c = toupper(k[index]);
        return c;
    }
    else
    {
        return p;
    }
}