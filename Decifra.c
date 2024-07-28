#include <stdio.h>

unsigned short encontrarPosicaoOriginal(char *, char);

int main()
{
    unsigned short i;
    char cifra[27], original[] = "abcdefghijklmnopqrstuvwxyz";
    char textoCifrado[10100], textoDecifrado[10100];

    scanf("%s", cifra);
    scanf("%s", textoCifrado);

    i = 0;
    while (textoCifrado[i])
    {
        textoDecifrado[i] = original[encontrarPosicaoOriginal(cifra, textoCifrado[i])];
        i++;
    }

    textoDecifrado[i] = '\0';
    printf("%s\n", textoDecifrado);

    return 0;
}

unsigned short encontrarPosicaoOriginal(char *cifra, char letra)
{
    unsigned short i = 0;

    while (cifra[i])
    {
        if (cifra[i] == letra)
            return i;

        i++;
    }

    return 0; // Em caso de letra não encontrada, retorna 0 por padrão
}
