#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct Lista {
    No *inicio;
    No *fim;
} Lista;

void adicionar_na_hash(Lista *, const int);
unsigned int tamanho_hash;

int main() {
    unsigned int n;
    int num_elementos, valor, i;

    scanf("%u", &n);

    while (n--) {
        scanf("%u %d", &tamanho_hash, &num_elementos);

        Lista hash[tamanho_hash];
        for (i = 0; i < tamanho_hash; ++i) {
            hash[i].inicio = NULL;
            hash[i].fim = NULL;
        }

        for (i = 0; i < num_elementos; ++i) {
            scanf("%d", &valor);
            adicionar_na_hash(hash, valor);
        }

        for (i = 0; i < tamanho_hash; ++i) {
            printf("%d -> ", i);
            No *atual = hash[i].inicio;
            while (atual) {
                printf("%d -> ", atual->valor);
                atual = atual->prox;
            }
            printf("\\\n");
        }

        if (n)
            printf("\n");
    }

    return 0;
}

void adicionar_na_hash(Lista *hash, const int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo)
        exit(1);

    int indice = valor % tamanho_hash;

    novo->valor = valor;
    novo->prox = NULL;

    if (hash[indice].fim) {
        hash[indice].fim->prox = novo;
    } else {
        hash[indice].inicio = novo;
    }

    hash[indice].fim = novo;
}
