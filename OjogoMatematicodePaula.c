#include <stdio.h>
#include <ctype.h>

int main() {
    char caractere;
    short valorA, valorB, resultadoFinal;
    unsigned short quantidadeTestes, indice;

    scanf("%hd", &quantidadeTestes);

    for (indice = 0; indice < quantidadeTestes; indice++) {
        scanf("%hd%c%hd", &valorA, &caractere, &valorB);
        resultadoFinal = 0;

        if (valorA == valorB) {
            resultadoFinal = valorA * valorB;
            printf("%d\n", resultadoFinal);
        } else if (isupper(caractere)) {
            resultadoFinal = valorB - valorA;
            printf("%d\n", resultadoFinal);
        } else if (islower(caractere)) {
            resultadoFinal = valorA + valorB;
            printf("%d\n", resultadoFinal);
        }
    }

    return 0;
}
