#include<stdio.h>
#define max 10

float lagrInvCalc(float arr[2][max], int n, float y){
    float sum = 0, temp;
    int i, j;
    for (i = 0; i < n; i++)
    {
        temp = 1;
        for(j = 0; j < n; j++)
        {
            if(i != j)
                temp *= (y-arr[1][j])/(arr[1][i]-arr[1][j]);
        }
        sum += (temp*arr[0][i]);
    }
    return sum;
}

int main(){
    float arr[2][max], y;
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

    printf("Enter the value of y\t");
    scanf("%f", &y);

    printf("x(%f) = %f\n", y, lagrInvCalc(arr, n, y));

    return 0;
}
