#include <stdio.h>

typedef struct {
    short valor;
    short frequencia;
} Quantidade;

void ordenar(Quantidade vetor[], unsigned short tamanho);
void quickSort(Quantidade v[], int inicio, int fim);

int main() {
    unsigned short casos, contador;
    short i, j;

    scanf("%hu", &casos);

    Quantidade numeros[casos];

    for (i = 0; i < casos; i++)
        scanf("%hu", &numeros[i].valor);

    for (i = 0; i < casos; i++) {
        contador = 0;
        for (j = 0; j < casos; j++) {
            if (numeros[i].valor == numeros[j].valor)
                contador++;
            numeros[i].frequencia = contador;
        }
    }

    quickSort(numeros, 0, casos - 1);

    for (i = 0; i < casos; i++)
        if (i == 0 || numeros[i - 1].valor != numeros[i].valor)
            printf("%hu aparece %hu vez(es)\n", numeros[i].valor, numeros[i].frequencia);

    return 0;
}

void quickSort(Quantidade v[], int inicio, int fim) {
    Quantidade pivo, temp;
    int i, j;

    if (inicio < fim) {
        i = inicio;
        j = fim;
        pivo = v[(inicio + fim) / 2];

        while (i <= j) {
            while (v[i].valor < pivo.valor)
                i++;
            while (v[j].valor > pivo.valor)
                j--;
            if (i <= j) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
                i++;
                j--;
            }
        }

        quickSort(v, inicio, j);
        quickSort(v, i, fim);
    }
}
