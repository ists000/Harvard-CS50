#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUMBER_OF_WORDS 143091  // Adjust this according to your needs

int main(void)
{
    FILE *file = fopen("large", "r");
    // Check if the file is opened successfully
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file.\n");
        return 1;
    }

    char word[MAX_WORD_LENGTH];
    char *array[MAX_NUMBER_OF_WORDS];

    int i = 0;
    while (fscanf(file, "%s", word) != EOF && i < MAX_NUMBER_OF_WORDS)
    {
        // Allocate memory for each word and copy it
        array[i] = malloc(strlen(word) + 1);
        strcpy(array[i], word);
        i++;
    }

    // Close the file
    fclose(file);

    // Task 1: Count words with different sums of ASCII values
    int sumCount[MAX_NUMBER_OF_WORDS] = {0};  // Assuming the maximum sum is the maximum possible sum
    for (int j = 0; j < i; j++)
    {
        int wordSum = 0;
        for (int k = 0; array[j][k] != '\0'; k++)
        {
            wordSum += array[j][k];
        }
        sumCount[wordSum]++;
    }

    printf("Words with different sums of ASCII values:\n");
    for (int j = 0; j < MAX_NUMBER_OF_WORDS; j++)
    {
        if (sumCount[j] > 0)
        {
            printf("Sum %d: %d words\n", j, sumCount[j]);
        }
    }

    // Task 2: Count words with different lengths
    int lengthCount[MAX_WORD_LENGTH + 1] = {0};  // Assuming the maximum length is MAX_WORD_LENGTH
    for (int j = 0; j < i; j++)
    {
        int wordLength = strlen(array[j]);
        lengthCount[wordLength]++;
    }

    printf("Words with different lengths:\n");
    for (int j = 0; j <= MAX_WORD_LENGTH; j++)
    {
        if (lengthCount[j] > 0)
        {
            printf("Length %d: %d words\n", j, lengthCount[j]);
        }
    }

    // Free allocated memory
    for (int j = 0; j < i; j++)
    {
        free(array[j]);
    }

    return 0;
}
