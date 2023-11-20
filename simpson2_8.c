#include<stdio.h>

float func(float x){
    return (x/(1+x*x));
}

float simp3by8Calc(float a, float b, float n){
    int i;
    float x = a, res, h;
    h = (b-a)/n;
    res = func(a)+func(b);
    for (i = 1; i < n; i++)
    {
        x += h;
        if(i%3 != 0)
        {
            res += (3*func(x));
        }
        else{
            res += (2*func(x));
        }
    }
    res *= (3*h/8);
    return res;
}

int main(){
    float a, b;
    int n;
    
    printf("Enter Lower Limit of Integration\n");
    scanf("%f", &a);
    printf("Enter Upper Limit of Integration\n");
    scanf("%f", &b);
    printf("Enter number of intervals\n");
    scanf("%d", &n);
    printf("The Result of Integration is %f", simp3by8Calc(a, b, n));
    return 0;
}
