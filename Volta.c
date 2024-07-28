#include <stdio.h>
#include <math.h>

int main ()
{
    float maisLento, maisRapido;
    float qtsVoltas;

    scanf("%f %f", &maisLento, &maisRapido);

    if (maisLento >= maisRapido) {
        printf("Erro\n");
        return 1;
    }

    qtsVoltas = maisRapido / (maisRapido - maisLento);
    printf("%.0f\n", ceil(qtsVoltas));

    return 0;
}
