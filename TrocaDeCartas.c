#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTOS 100101

typedef struct {
    _Bool possuiAlice;
    _Bool possuiBeatriz;
} Cartao;

Cartao cartoes[MAX_ELEMENTOS];

int main(void) {
    unsigned int indice, valor;
    unsigned int totalAlice, totalBeatriz;

    while (scanf("%u %u", &totalAlice, &totalBeatriz), totalAlice) {
        memset(cartoes, 0, sizeof(cartoes));

        for (indice = 0; indice < totalAlice; ++indice) {
            scanf("%u", &valor);
            cartoes[valor].possuiAlice = 1;
        }

        for (indice = 0; indice < totalBeatriz; ++indice) {
            scanf("%u", &valor);
            cartoes[valor].possuiBeatriz = 1;
        }

        totalAlice = totalBeatriz = 0;
        for (indice = 0; indice < MAX_ELEMENTOS; ++indice) {
            if (cartoes[indice].possuiAlice && !cartoes[indice].possuiBeatriz) {
                ++totalAlice;
            }
            if (!cartoes[indice].possuiAlice && cartoes[indice].possuiBeatriz) {
                ++totalBeatriz;
            }
        }

        printf("%u\n", totalBeatriz > totalAlice ? totalAlice : totalBeatriz);
    }

    return 0;
}
