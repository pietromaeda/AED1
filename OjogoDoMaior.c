#include <stdio.h>

int main() {
    unsigned short quantidadeCasos, valorA, valorB;
    unsigned short pontosEquipeA = 0, pontosEquipeB = 0;

    while (1) {
        scanf("%hu", &quantidadeCasos);

        if (quantidadeCasos == 0) {
            break;
        }

        while (quantidadeCasos--) {
            scanf("%hu %hu", &valorA, &valorB);

            if (valorA > valorB) {
                pontosEquipeA++;
            } else if (valorB > valorA) {
                pontosEquipeB++;
            }
        }

        printf("%hu %hu\n", pontosEquipeA, pontosEquipeB);
        pontosEquipeA = 0;
        pontosEquipeB = 0;
    }

    return 0;
}
