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

//conditionals
//input a space after if
// if condition
if (x < y)
{
    printf("x is less than y\n");
}

// if, else condition, a two-way fork in the road
if (x < y)
{
    printf("x is less than y\n");
}
else
{
    printf("x is not less than y\n");
}

// if, else if, else if condition, a three-way fork in the road
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else if (x == y)   // in code C, = means assignment, == means equal.
{
    printf("x is equal to y\n");
}

// simplify! if, else if, else condition, a three-way fork in the road
if (x < y)
{
    printf("x is less than y\n");
}
else if (x > y)
{
    printf("x is greater than y\n");
}
else
{
    printf("x is equal to y\n");
}

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

// variable
// set counter to 0:     int counter = 0;
// change counter by 1:  counter = counter + 1; or counter += 1; counter ++; means + 1; counter--; means - 1;
// int or string is only need to be added at the first time or claim it.
// don't need to add int or string before an existing variable.

// loops
// while loop
/* repeat 3
    say meow */
/*
int counter = 3;
while (counter > 0)
{
    printf("meow\n");
    counter = counter - 1;
}
*/
// same as
/*
int i = 3;
while (i > 0)
{
    printf("meow\n");
    i -= 1;
}
*/
// another way
/*
int i = 3;
while (i > 0)
{
    printf("meow\n");
    i--;
}
*/
// another way
/*
int i = 1;
while (i <= 3)
{
    printf("meow\n");
    i++;
}
*/
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 30)
    {
        printf("meow\n");
        i++;
    }
}

// for loop
/*
for (int i = 0; i < 3; i++)
{
    printf("meow\n");
}
*/

#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        printf("meow\n");
    }
}

//forever block, do the following forever
/*
while (ture)
{
    printf("meow\n");
}
*/
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    while (true)
    {
        printf("meow\n");
    }
}

// GUI
// CLI command-line interface
/*
cd: change directory
cp: copy a file
ls: list
mkdir: make a directory, create a new folder at the command line instead of with the button.
mv: moving or rename
rm: remove
rmdir: remove directory
...
*/