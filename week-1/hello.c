// functions

#include <cs50.h>
#include <stdio.h>        //indicate the function will be used in the following step

int main(void)
{
    string first = get_string("What's your first name? "); //must take the type of data in the first. Use " " to indicate the string which want to output. Don't forget the semicolon;
    string last = get_string("What's your last name? ");  // in code C, = means assignment, == means equal.
    printf("Hello, %s %s!\n", first, last); //use printf to indicate print out the result. in the (), use " " to indicate the string wanna be print out. If there has exist data, must use %s or other mark, and then, use comma to separate the value.
}
// use parentheses for printf and get_string