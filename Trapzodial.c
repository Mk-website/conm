#include <stdio.h>

float func(float x)
{
    return (1/(1+x*x));
}

float trapezoidalCalc(float a, float b, float n)
{
    int i;
    float x = a, res, h;
    h = (b - a) / n;
    res = func(a) + func(b);
    for (i = 1; i < n; i++)
    {
        x += h;
        res += (2 * func(x));
    }
    res *= (h / 2);
    return res;
}

int main()
{
    float a, b;
    int n;

    printf("Enter Lower Limit of Integration\n");
    scanf("%f", &a);
    printf("Enter Upper Limit of Integration\n");
    scanf("%f", &b);
    printf("Enter number of intervals\n");
    scanf("%d", &n);
    printf("The Result of Integration is %f", trapezoidalCalc(a, b, n));
    return 0;
}
