#include <stdio.h>

int main ()
{

    unsigned short i, j, k;
    unsigned short numPerguntas, frequencia;
    unsigned short resposta = 0, contador;

    while (1)
    {

        scanf("%hu %hu", &numPerguntas, &frequencia);

        if (numPerguntas == 0 && frequencia == 0)
            break;

        short perguntas[numPerguntas];
        short perguntasCpy[numPerguntas];

        for (i = 0; i < numPerguntas; i++)
            scanf("%hu", &perguntas[i]);

        for (i = 0; i < numPerguntas; i++)
            perguntasCpy[i] = perguntas[i];

        for (i = 0; i < numPerguntas; i++)
        {   
            contador = 0;
            for (j = 0; j < numPerguntas; j++)
            {   
                if (perguntas[i] == perguntasCpy[j])
                {
                    perguntasCpy[j] = 0;
                    contador++;
                }

                if (contador == frequencia)
                {   
                    resposta++;
                    for (k = j + 1; k < numPerguntas; k++)
                        if (perguntas[i] == perguntasCpy[k])
                            perguntasCpy[k] = 0;

                    break;
                }
                
            }

            perguntasCpy[i] = 0;

        }

        printf("%hu\n", resposta);
        resposta = 0;

    }

    return 0;
}
