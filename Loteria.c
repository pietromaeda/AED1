#include <stdio.h>

int main() {

    unsigned short jogador[6], sorteados[6];
    unsigned short i, j, acertos = 0;

    for (i = 0; i < 6; i++)
        scanf("%hu", &jogador[i]);

    for (i = 0; i < 6; i++)
        scanf("%hu", &sorteados[i]);

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            if (jogador[i] == sorteados[j]) {
                acertos++;
                break;
            }
        }
    }

    switch (acertos) {
        case 3:
            printf("terno\n");
            break;
        case 4:
            printf("quadra\n");
            break;
        case 5:
            printf("quina\n");
            break;
        case 6:
            printf("sena\n");
            break;
        default:
            printf("azar\n");
            break;
    }

    return 0;
}
