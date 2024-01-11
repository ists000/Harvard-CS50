#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? ");

    if (c == 'y' || c == 'Y')  //single quote for char. || means or.
    {
        printf("Agreed.\n");   // double quote for string.
    }
    else if (c == 'n' || c == 'N')
    {
        printf("Not agree.\n");
    }
}