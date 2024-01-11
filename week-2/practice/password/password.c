// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// create a function to check the password
bool valid(string password)
{
    // set the bool result firstly
    bool check_lower_case = false;
    bool check_upper_case = false;
    bool check_number = false;
    bool check_symbol = false;

    // set the length
    int length = strlen(password);

    // do the loop to check if the input match the lowercase, uppercase, number and symbol
    for (int i = 0; i < length; i++)
    {
        if (islower(password[i]))
        {
            check_lower_case = true;
        }
        if (isupper(password[i]))
        {
            check_upper_case = true;
        }
        if (isdigit(password[i]))
        {
            check_number = true;
        }
        if (!isalnum(password[i]))
        {
            check_symbol = true;
        }
    }

    // check if they all true, if they are all true, return true
    if (check_lower_case == true && check_upper_case == true && check_number == true && check_symbol == true)
    {
        return true;
    }

    // if not, return false
    return false;
}
