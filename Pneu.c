#include <stdio.h>

int main() {
    short pressaoMeta, pressaoAtual;

    scanf("%hd %hd", &pressaoMeta, &pressaoAtual);

    printf("%hd\n", pressaoMeta - pressaoAtual);

    return 0;
}
