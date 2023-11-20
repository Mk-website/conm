#include<stdio.h>
#define max 10

float lagrangianCalc(float arr[2][max], int n, float x){
    float  sum = 0, temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        temp = 1;
        for(j = 0; j < n; j++)
        {
            if(i != j)
                temp *= (x-arr[0][j])/(arr[0][i]-arr[0][j]);
        }
        sum += (temp*arr[1][i]);
    }
    return sum;
}

int main(){
    float arr[2][max], x;
    int i, n;
    
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

    printf("y(%f) = %f\n", x, lagrangianCalc(arr, n, x));

    return 0;
}