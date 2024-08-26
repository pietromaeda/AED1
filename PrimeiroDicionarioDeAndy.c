#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char palavra[201];
} Palavra;

bool existeNaLista(char *, Palavra *, unsigned int);
void ordenarPalavras(Palavra *, int);
void ordenarPalavrasRecursivo(Palavra *, int, int);

int main() {
    unsigned int numPalavras = 0;
    char entrada[201], palavraTemp[201];
    Palavra listaPalavras[5050];

    memset(listaPalavras, 0, sizeof(listaPalavras));

    while (scanf(" %[^\n]", entrada) != EOF) {
        unsigned int i = 0, j = 0;

        while (entrada[i]) {
            while (isalpha(entrada[i])) {
                palavraTemp[j++] = tolower(entrada[i++]);
            }

            if (entrada[i] == '\0') {
                palavraTemp[j] = '\0';

                if (!existeNaLista(palavraTemp, listaPalavras, numPalavras)) {
                    strcpy(listaPalavras[numPalavras++].palavra, palavraTemp);
                }

                j = 0;
                memset(palavraTemp, 0, sizeof(palavraTemp));
                break;
            }

            palavraTemp[j] = '\0';

            while (!isalpha(entrada[i])) {
                i++;
                if (entrada[i] == '\0')
                    break;
            }

            if (!existeNaLista(palavraTemp, listaPalavras, numPalavras)) {
                strcpy(listaPalavras[numPalavras++].palavra, palavraTemp);
            }

            j = 0;
            memset(palavraTemp, 0, sizeof(palavraTemp));
        }

        memset(entrada, 0, sizeof(entrada));
    }

    ordenarPalavras(listaPalavras, numPalavras);

    for (unsigned int i = 0; i < numPalavras; i++) {
        if (strlen(listaPalavras[i].palavra) > 0) {
            printf("%s\n", listaPalavras[i].palavra);
        }
    }

    return 0;
}

bool existeNaLista(char *str, Palavra *lista, unsigned int tamanho) {
    for (unsigned int i = 0; i < tamanho; i++) {
        if (strcmp(lista[i].palavra, str) == 0)
            return true;
    }
    return false;
}

void ordenarPalavrasRecursivo(Palavra *lista, int inicio, int fim) {
    if (inicio < fim) {
        Palavra pivo = lista[(inicio + fim) / 2];
        int i = inicio, j = fim;

        while (i <= j) {
            while (strcmp(lista[i].palavra, pivo.palavra) < 0) i++;
            while (strcmp(lista[j].palavra, pivo.palavra) > 0) j--;

            if (i <= j) {
                Palavra temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
                i++;
                j--;
            }
        }

        ordenarPalavrasRecursivo(lista, inicio, j);
        ordenarPalavrasRecursivo(lista, i, fim);
    }
}

void ordenarPalavras(Palavra *lista, int tamanho) {
    ordenarPalavrasRecursivo(lista, 0, tamanho - 1);
}
