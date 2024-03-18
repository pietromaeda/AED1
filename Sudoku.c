#include <stdio.h>

int main()
{
  int x, a, b, temporario, instancia = 0, resposta = 1;
  int mat[9][9], somaLin[9], somaCol[9], somaMat[3][3];

  scanf("%i", &x);
    for(int cont = 0; cont < x; cont++)
    {
      for(a = 0; a < 9; a++)
      {
        for(b = 0; b < 9; b++)
        { 
          scanf("%i", &mat[a][b]);
        }
      }
    for (a = 0; a < 9; a++)
    {
      somaLin[a] = 0;
      somaCol[a] = 0;
      somaMat[a/3][a%3] = 0;
    }
    for (a = 0; a < 9; a++)
    {
      for (b = 0; b < 9; b++)
      {
        temporario = mat[a][b] * mat[a][b];
        somaLin[a]  += temporario;
        somaCol[b] += temporario;
        somaMat[a/3][b/3] += temporario;

        if (a == 8 && somaCol[b] != 285) { break; }
      } 

      if (somaLin[a] != 285) { break; }
    }
    instancia++;
    printf("Instancia %i\n", instancia);
    for (int a = 0; a < 3; a++)
    {
      for (int b = 0; b < 3; b++)
      {
        if (somaMat[a][b] != 285)
        {
          resposta = 0;
        }
      }
    }
    if (resposta == 1)
    {
      printf("SIM\n\n");
    }
    else
    {
      printf("NAO\n\n");
    }
    resposta = 1;
  }
    return 0;
}
