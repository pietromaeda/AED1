#include <stdio.h>

#define MAXSIZE 600

unsigned short grid[MAXSIZE][MAXSIZE];

int main()
{
    unsigned n, x, y;
    int flag = 0;

    scanf("%u", &n);

    while (n--)
    {
        scanf("%u %u", &x, &y);

        if (grid[x][y])
            flag = 1;
        else
            grid[x][y] = 1;
    }

    printf("%c\n", flag ? '1' : '0');

    return 0;
}
