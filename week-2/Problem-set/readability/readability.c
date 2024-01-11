#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string input_text = get_string("Text: ");

    int count_text_letter = count_letters(input_text);

    int count_text_word = count_words(input_text);

    int count_text_sentence = count_sentences(input_text);

    double L = count_text_letter * 100.0 / count_text_word;
    double S = count_text_sentence * 100.0 / count_text_word;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int length = strlen(text);
    int count_letter = 0;

    for (int i = 0; i < length; i++)
    {
        char a = text[i];
        if (isalpha(a))
        {
            count_letter += 1;
        }
        else
        {
            count_letter += 0;
        }
    }

    return count_letter;
}

int count_words(string text)
{
    int length = strlen(text);
    int count_word = 1;

    for (int j = 0; j < length; j++)
    {
        char b = text[j];
        if (isblank(b))
        {
            count_word += 1;
        }
        else
        {
            count_word += 0;
        }
    }

    return count_word;
}

int count_sentences(string text)
{
    int length = strlen(text);
    int count_sentence = 0;

    for (int k = 0; k < length; k++)
    {
        char c = text[k];
        if (c == '.')
        {
            count_sentence += 1;
        }
        else if (c == '?')
        {
            count_sentence += 1;
        }
        else if (c == '!')
        {
            count_sentence += 1;
        }
        else
        {
            count_sentence += 0;
        }
    }

    return count_sentence;
}