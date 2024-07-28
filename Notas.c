#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100100

typedef struct {
    unsigned nota;
    unsigned posicao;
} Notas;

int compara(const void *a, const void *b);

int main()
{
    unsigned i, n, tmp;
    Notas notas[MAXSIZE] = {0};

    scanf("%u", &n);

    while (n--)
    {
        scanf("%u", &tmp);
        notas[tmp].nota++;
        notas[tmp].posicao = tmp;
    }

    qsort(notas, MAXSIZE, sizeof(Notas), compara);
    printf("%u\n", notas[0].posicao);

    return 0;
}

int compara(const void *a, const void *b)
{
    Notas *notaA = (Notas *)a;
    Notas *notaB = (Notas *)b;

    if (notaA->nota == notaB->nota)
        return (notaB->posicao - notaA->posicao);

    return (notaB->nota - notaA->nota);
}
