#include <stdio.h>

#define MAXSIZE 110

int main()
{
    short saldo, i, teste;
    unsigned short n, a, b;

    teste = 0;
    while (scanf("%hu", &n), n)
    {
        saldo = 0;
        printf("Teste %d\n", ++teste);
        for (i = 0; i < n; ++i)
        {
            scanf("%hu %hu", &a, &b);
            saldo += a;
            saldo -= b;
            printf("%hd\n", saldo);
        }
        printf("\n");
    }

    return 0;
}
