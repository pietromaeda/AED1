#include <stdio.h>

void main()
{
    char strNumero[101];
    short numInteiros[101];
    unsigned short i = 0, j = 0;
    float media = 0;

    scanf("%s", strNumero);

    while (strNumero[i])
    {
        numInteiros[j] = 0;
        while (strNumero[i] != '0' && strNumero[i] != '\0')
        {
            numInteiros[j] = numInteiros[j] * 10 + (strNumero[i] - '0');
            i++;
        }
        j++;
        
        if (strNumero[i] == '0')
        {
            i++;
        }
    }

    for (i = 0; i < j; i++)
    {
        media += numInteiros[i];
    }

    printf("%.2f\n", media / j);
}
