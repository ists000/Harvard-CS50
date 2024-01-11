#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m;
    int* a;
    int* b = malloc(sizeof(int));
    a = &m;
    printf("a is %i, m is %i", a, &m);
}