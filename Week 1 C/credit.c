#include <cs50.h>
#include <stdio.h>
int main(void)
{
    // set the varilable
    long card;
    // check the number if greater than 0, if not, keep asking to input
    do
    {
        card = get_long("Please enter the card number: ");
    }
    while (card <= 0);

    // read the input, and do the calculation, Multiply every other digit by 2, starting with the number’s second-to-last digit, and
    // then add those products’ digits together.
    int a, b, c, d, e, f, g, h;
    a = ((card % 100) / 10) * 2;
    b = ((card % 10000) / 1000) * 2;
    c = ((card % 1000000) / 100000) * 2;
    d = ((card % 100000000) / 10000000) * 2;
    e = ((card % 10000000000) / 1000000000) * 2;
    f = ((card % 1000000000000) / 100000000000) * 2;
    g = ((card % 100000000000000) / 10000000000000) * 2;
    h = ((card % 10000000000000000) / 1000000000000000) * 2;
    // because there might be exist two digits number, so have to separate them
    a = (a % 100) / 10 + (a % 10);
    b = (b % 100) / 10 + (b % 10);
    c = (c % 100) / 10 + (c % 10);
    d = (d % 100) / 10 + (d % 10);
    e = (e % 100) / 10 + (e % 10);
    f = (f % 100) / 10 + (f % 10);
    g = (g % 100) / 10 + (g % 10);
    h = (h % 100) / 10 + (h % 10);
    int sum1 = a + b + c + d + e + f + g + h;
    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    int i, j, k, l, m, n, o, p; // 1234567890123456
    i = card % 10;
    j = (card % 1000) / 100;
    k = (card % 100000) / 10000;
    l = (card % 10000000) / 1000000;
    m = (card % 1000000000) / 100000000;
    n = (card % 100000000000) / 10000000000;
    o = (card % 10000000000000) / 1000000000000;
    p = (card % 1000000000000000) / 100000000000000;
    int sum2 = i + j + k + l + m + n + o + p;
    int sumtotal = sum1 + sum2;
    // If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if ((sumtotal % 10) != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // check the card company and the first digit if the Visa, Amex or mastercard
    long visa = card;
    long amex = card;
    long mastercard = card;
    // to check the length of the number
    int length = 0;
    while (card > 0)
    {
        card = card / 10;
        length++;
    }
    // to check if the card belongs to Visa 13/16 digits and start with 4
    while (visa >= 10)
    {
        visa = visa / 10;
    }
    if ((length == 13 || length == 16) && visa == 4)
    {
        printf("VISA\n");
        return 0;
    }
    // to check if the card belongs to Amex 15 digits and start with 34/37
    while (amex >= 100000000000000)
    {
        amex = amex / 10000000000000;
    }
    if (length == 15 && (amex == 34 || amex == 37))
    {
        printf("AMEX\n");
        return 0;
    }
    // to check if the card belongs to mastercard 16 digits and start with 51/52/53/54/55
    while (mastercard >= 1000000000000000)
    {
        mastercard = mastercard / 100000000000000;
    }
    if (length == 16 && (mastercard == 51 || mastercard == 52 || mastercard == 53 || mastercard == 54 || mastercard == 55))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    else
    {
        printf("INVALID\n");
    }
}
