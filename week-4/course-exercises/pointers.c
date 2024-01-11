#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 28;
    int b = 50;
    printf("first time: a is %i, b is %i\n", a, b);
    int *c = &a;
    printf("second time: a is %i, %p, b is %i, %p, c is %p, %p\n", a, &a, b, &b, c, &c);
    *c = 14;
    printf("third time: a is %i, %p, b is %i, %p, c is %p, %p\n", a, &a, b, &b, c, &c);
    c = &b;
    printf("forth time: a is %i, %p, b is %i, %p, c is %p, %p\n", a, &a, b, &b, c, &c);
    *c = 25;
    printf("last time: a is %i, %p, b is %i, %p, c is %p, %p\n", a, &a, b, &b, c, &c);
}