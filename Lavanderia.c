#include <stdio.h>

int main(void) {
    unsigned short roupas;
    unsigned short lavaRoupasMin, lavaRoupasMax;
    unsigned short secaRoupasMin, secaRoupasMax;

    scanf("%hu", &roupas);

    scanf("%hu %hu", &lavaRoupasMin, &lavaRoupasMax);
    scanf("%hu %hu", &secaRoupasMin, &secaRoupasMax);

    if ((roupas >= lavaRoupasMin && roupas <= lavaRoupasMax) &&
        (roupas >= secaRoupasMin && roupas <= secaRoupasMax)) {
        printf("possivel\n");
    } else {
        printf("impossivel\n");
    }

    return 0;
}
