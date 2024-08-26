#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    unsigned short numCasos, numPessoas;
    char idiomaAtual[21], idiomaAnterior[21];
    bool misturado;

    scanf("%hu", &numCasos);

    while (numCasos--) {
        scanf("%hu", &numPessoas);

        scanf(" %s", idiomaAnterior);
        misturado = false;

        for (unsigned short i = 1; i < numPessoas; i++) {
            scanf(" %s", idiomaAtual);

            if (strcmp(idiomaAtual, idiomaAnterior) != 0) {
                misturado = true;
            }

            strcpy(idiomaAnterior, idiomaAtual);
        }

        if (misturado) {
            printf("ingles\n");
        } else {
            printf("%s\n", idiomaAnterior);
        }
    }

    return 0;
}
