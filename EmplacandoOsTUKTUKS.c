#include <stdio.h>

typedef unsigned int uint;

uint power(uint base, uint exponent);

int main() {
    uint n, x, y;

    scanf("%u", &n);
    while (n--) {
        scanf("%u %u", &x, &y);

        if (x == 0 && y == 0) {
            puts("0");
        } else if (x == 0) {
            printf("%u\n", power(10, y));
        } else if (y == 0) {
            printf("%u\n", power(26, x));
        } else {
            printf("%u\n", power(10, y) * power(26, x));
        }
    }

    return 0;
}

uint power(uint base, uint exponent) {
    uint result = 1;

    while (exponent--) {
        result *= base;
    }

    return result;
}
