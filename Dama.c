#include <stdio.h>
#include <math.h>

int main() {
    int x1, y1, x2, y2;
    int movimentos;
    int deltaX, deltaY;

    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) && (x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0)) {
        deltaX = abs(x1 - x2);
        deltaY = abs(y1 - y2);

        if (x1 == x2 && y1 == y2) {
            movimentos = 0;
        } else if (x1 == x2 || y1 == y2 || deltaX == deltaY) {
            movimentos = 1;
        } else {
            movimentos = 2;
        }

        printf("%d\n", movimentos);
    }

    return 0;
}
