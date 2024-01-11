// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    // check the input if single word, if not, print out error and return 1;
    if (argc != 2)
    {
        printf("error.");
        return 1;
    }
    // print out the result
    string output = argv[1];

    string result = replace(output);

    printf("%s\n", result);
}

string replace(string word)
{
    // conver the input into lowercase
    int length = strlen(word);
    char x = word[0];
    for (int i = 0; i < length; i++)
    {
        x = tolower(word[i]);
        // switch the vowel word to number
        switch (x)
        {
            case 'a':
                word[i] = '6';
                break;

            case 'e':
                word[i] = '3';
                break;

            case 'i':
                word[i] = '1';
                break;

            case 'o':
                word[i] = '0';
                break;

            default:
                word[i] = word[i];
                break;
        }
    }

    return word;
}