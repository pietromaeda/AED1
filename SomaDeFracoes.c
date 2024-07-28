#include <stdio.h>

int mdc(int a, int b);
void somaFrações(int a, int b, int c, int d, int *numerador, int *denominador);

int main() {
    int a, b, c, d;
    int numerador, denominador;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    somaFrações(a, b, c, d, &numerador, &denominador);
    int divisor = mdc(numerador, denominador);

    printf("%d %d\n", numerador / divisor, denominador / divisor);

    return 0;
}

void somaFrações(int a, int b, int c, int d, int *numerador, int *denominador) {
    *numerador = a * d + c * b;
    *denominador = b * d;
}

int mdc(int a, int b) {
    int resto;

    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }

    return a;
}
