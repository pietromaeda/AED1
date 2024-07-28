#include <stdio.h>
#include <stdbool.h>

char obterAlternativa(unsigned short);

int main() {
    unsigned char respostas[6];
    unsigned short quantidadeQuestoes, indice;
    unsigned short contagem, posicaoUnica;
    bool unicaAlternativa;

    while (true) {
        scanf("%hu", &quantidadeQuestoes);

        if (quantidadeQuestoes == 0)
            break;

        while (quantidadeQuestoes--) {
            for (indice = 0; indice < 5; indice++)
                scanf("%hhd", &respostas[indice]);

            unicaAlternativa = true;
            contagem = 0;
            for (indice = 0; indice < 5; indice++) {
                if (respostas[indice] <= 127) {
                    contagem++;
                    if (contagem == 1 && unicaAlternativa) {
                        unicaAlternativa = false;
                        posicaoUnica = indice;
                    }
                }
            }

            if (contagem == 0)
                printf("*\n");
            else if (contagem == 1)
                printf("%c\n", obterAlternativa(posicaoUnica));
            else
                printf("*\n");
        }
    }

    return 0;
}

char obterAlternativa(unsigned short posicao) {
    switch (posicao) {
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
        case 4:
            return 'E';
        default:
            return '*'; // Para lidar com valores inesperados
    }
}
