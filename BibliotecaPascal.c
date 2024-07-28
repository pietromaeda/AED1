#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main ()
{

    int linhas, colunas, i, j;

    while (scanf("%d %d", &colunas, &linhas), linhas)
    {

        char matrix[linhas][colunas];

        for (i = 0; i < linhas; ++i)
            for (j = 0; j < colunas; ++j)
                scanf(" %c", &matrix[i][j]);

        bool is = false;
        for (j = 0; j < colunas; ++j)
        {

            int cont = 0;
            for (i = 0; i < linhas; ++i)
                if (matrix[i][j] == '1')
                    cont++;
            
            if (cont == linhas)
            {
                is = true;
                break;
            }

        }

        printf("%s\n", is ? "yes" : "no");

    }

    return 0;

}
