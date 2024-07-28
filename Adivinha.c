#include <stdio.h>
#include <stdlib.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n, s;
        int qt[10], x[10];
        int i, j;
        int indice, menor;

        scanf("%d", &n);
        scanf("%d", &s);

        for (j = 0; j < n; j++) {
            scanf("%d", &qt[j]);
            x[j] = abs(qt[j] - s);
        }

        menor = 101;
        for (j = 0; j < n; j++) {
            if (qt[j] == s) {
                indice = j + 1;
                break;
            } else if (x[j] < menor) {
                menor = x[j];
                indice = j + 1;
            }
        }

        printf("%d\n", indice);
    }

    return 0;
}
