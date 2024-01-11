#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main() {
    int number = get_int("Number: "); // You can change this to any positive integer you want to test.
    int steps = collatz(number);
    printf("Number of steps for %d is %d\n", number, steps);

    return 0;
}

int collatz(int n) {
    if (n == 1) {
        return 0;
    } else if ((n % 2) == 0) {
        return 1 + collatz(n / 2);
    } else {
        return 1 + collatz(3 * n + 1);
    }
}
