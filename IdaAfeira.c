#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    float preco;
} Fruta;

bool procuraFruta(const Fruta *feira, const char *nome, unsigned short qtdFrutas, unsigned short *posicao);

int main() {
    unsigned short qtsIdasFeira, qtsProdutos;
    unsigned short qtsProdutosDesejados, quantidadeFrutas;
    char frutaStr[MAX_NOME];
    float somaPreco;

    scanf("%hu", &qtsIdasFeira);

    while (qtsIdasFeira--) {
        scanf("%hu", &qtsProdutos);

        Fruta feira[qtsProdutos];
        for (unsigned short i = 0; i < qtsProdutos; i++) {
            scanf("%s %f", feira[i].nome, &feira[i].preco);
        }

        scanf("%hu", &qtsProdutosDesejados);

        somaPreco = 0;
        for (unsigned short i = 0; i < qtsProdutosDesejados; i++) {
            scanf("%s %hu", frutaStr, &quantidadeFrutas);
            unsigned short posicao;
            if (procuraFruta(feira, frutaStr, qtsProdutos, &posicao)) {
                somaPreco += feira[posicao].preco * quantidadeFrutas;
            }
        }

        printf("R$ %.2f\n", somaPreco);
    }

    return 0;
}

bool procuraFruta(const Fruta *feira, const char *nome, unsigned short qtdFrutas, unsigned short *posicao) {
    for (unsigned short i = 0; i < qtdFrutas; i++) {
        if (strcmp(feira[i].nome, nome) == 0) {
            *posicao = i;
            return true;
        }
    }
    return false;
}
