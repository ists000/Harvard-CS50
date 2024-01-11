/* #include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    printf("%li\n", x + y);
}
*/
// 32 bits
// 0000000000000000000000000000000
// 1111111111111111111111111111111 = 4294967295
// the max in c is 2147483648
// the min in c is -2147483648
// integer overflow
// just like when use binary indicate 8, if it's only have 3bits, it will overflow.
/*
format code
%c
%f
%i
%li
%s
*/
// use long could get to 9223372036854775807

// truncation
/*
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    float z = x / y;
    printf("%f\n", z);
}
*/

// type casting
/*

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    float z = (float) x / (float) y;
    printf("%f\n", z);
}
*/

// floating-point imprecision
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    double z = (double) x / (double) y;
    printf("%.20f\n", z);   //%.20f to indicate to see that I want to see 20 digits.
}