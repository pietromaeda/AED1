#include <stdio.h>

int main ()
{
    unsigned a, b;
    while (scanf("%u %u", &a, &b), a && b)
        printf("%d\n", 2 * a - b);

    return 0;
}
