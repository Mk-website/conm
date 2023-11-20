#include <stdio.h>
#define MaxSize 10
long fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n - 1);
}
float newtonBack(float arr[MaxSize][MaxSize], float x, int n){
    float  res, u, prod = 1;
    int i, j;

    for (i = 2; i <= n; i++)
    {
        for (j = n-1; j >= i-1; j--)
        {
            arr[i][j] = arr[i-1][j] - arr[i-1][j-1];
        }
    }

    res = arr[1][n-1];
    u = (x-arr[0][n-1])/(arr[0][1]-arr[0][0]);

    printf("%f\n", u);

    for (i = 0; i < n-1; i++)
    {
        prod = 1;
        for (j = 0; j <= i; j++)
        {
            prod *= (u+j);
        }
        prod *= (arr[i+2][n-1]/fact(i+1));
        res += prod;
    }
    return res;
}

int main()
{
    float arr[MaxSize][MaxSize], x;
    int n, i;

    printf("Enter numer of intervals (upto 10)\n");
    scanf("%d", &n);

    if(n > 10 || n <= 0){
        printf("Invalid intervals\n");
        return 0;
    }

    for(i = 0; i < n; i++)
    {
        printf("Enter x%d value: \t", i);
        scanf("%f", &arr[0][i]);
        printf("Enter y%d value: \t", i);
        scanf("%f", &arr[1][i]);
    }
    
    printf("Enter the value of x\t");
    scanf("%f", &x);

    printf("\nValue at f(%f) = %f", x, newtonBack(arr, x, n));
 return 0;
}