#include <stdio.h>
#include <stdbool.h>

int main() {
    unsigned char jogada;
    unsigned short vitoriasMary = 0, vitoriasJohn = 0, numCasos;

    while (true) {
        scanf("%hu", &numCasos);

        if (numCasos == 0)
            break;

        vitoriasMary = vitoriasJohn = 0;

        for (unsigned short i = 0; i < numCasos; i++) {
            scanf("%hhd", &jogada);

            if (jogada == 0)
                vitoriasMary++;
            else
                vitoriasJohn++;
        }

        printf("Mary won %hu times and John won %hu times\n", vitoriasMary, vitoriasJohn);
    }

    return 0;
}
