#include <stdio.h>

int main ()
{
    unsigned short diametro, largura, altura, profundidade;

    scanf("%hu", &diametro);
    scanf("%hu %hu %hu", &altura, &largura, &profundidade);

    if (diametro <= altura && diametro <= largura && diametro <= profundidade)
        printf("S\n");
    else
        printf("N\n");
}