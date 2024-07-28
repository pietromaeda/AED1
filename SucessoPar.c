#include <stdio.h>

int main ()
{

    unsigned long numero;

    scanf("%lu", &numero);

    if (numero % 2 == 0)
        printf("%lu\n", numero + 2);
    else
        printf("%lu\n", numero + 1);

    return 0;
}
