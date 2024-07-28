#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
    short index;
    short temp;
    short totalMergulhou, totalRetornou;
    bool saoIguais = false;

    while (scanf("%hd %hd", &totalMergulhou, &totalRetornou) != EOF) {
        if (totalMergulhou == totalRetornou) {
            saoIguais = true;
        }

        if (saoIguais) {
            for (index = 0; index < totalRetornou; index++) {
                scanf("%hd", &temp);
            }
            printf("*\n");
        } else {
            short retornos[totalMergulhou + 1];
            memset(retornos, 0, sizeof(retornos));

            for (index = 0; index < totalRetornou; index++) {
                scanf("%hd", &temp);
                retornos[temp] = temp;
            }

            for (index = 1; index <= totalMergulhou; index++) {
                if (retornos[index] == 0) {
                    printf("%hd ", index);
                }
            }
            printf("\n");
        }

        saoIguais = false;
    }

    return 0;
}
