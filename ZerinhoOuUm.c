#include <stdio.h>

int main() {
    short valores[3], indiceUnico;
    unsigned short i, j, numDiferencas;

    while (scanf("%hu %hu %hu", &valores[0], &valores[1], &valores[2]) != EOF) {
        indiceUnico = -1;

        for (i = 0; i < 3; i++) {
            numDiferencas = 0;
            for (j = 0; j < 3; j++) {
                if (valores[i] != valores[j]) {
                    numDiferencas++;
                }
            }

            if (numDiferencas == 2) {
                indiceUnico = i;
            }
        }

        if (indiceUnico == 0) {
            printf("A\n");
        } else if (indiceUnico == 1) {
            printf("B\n");
        } else if (indiceUnico == 2) {
            printf("C\n");
        } else {
            printf("*\n");
        }
    }

    return 0;
}
