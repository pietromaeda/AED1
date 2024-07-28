#include <stdio.h>

typedef unsigned short us;

int main ()
{

    us i, j;
    us numJogadores, numPartidas;

    scanf("%hu %hu", &numJogadores, &numPartidas);

    us tmp, ans = 0;
    for (i = 0; i < numJogadores; ++i)
    {

        us gols = 0;
        for (j = 0; j < numPartidas; ++j)
        {

            scanf("%hu", &tmp);
            if (tmp > 0)
                ++gols;

        }

        if (gols == numPartidas)
            ++ans;

    }

    printf("%hu\n", ans);

    return 0;

}
