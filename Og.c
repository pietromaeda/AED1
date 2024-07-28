#include <stdio.h>

int main() {
    unsigned char valorDireita, valorEsquerda;

    while (1) {
        scanf("%hhd %hhd", &valorDireita, &valorEsquerda);

        if (valorDireita == 0 && valorEsquerda == 0) {
            break;
        }

        printf("%hhd\n", valorDireita + valorEsquerda);
    }

    return 0;
}
