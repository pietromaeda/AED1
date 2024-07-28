#include <stdio.h>

#define INF 1e9

double min(double a, double b);

int main()
{
    int n, cost;
    double gram, mim;

    scanf("%d", &n);

    mim = INF;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf %d", &gram, &cost);
        mim = min(mim, (gram * 1000.0) / cost);
    }

    printf("%.2lf\n", mim);

    return 0;
}

double min(double a, double b)
{
    return a < b ? a : b;
}
