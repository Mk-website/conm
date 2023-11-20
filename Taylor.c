#include<stdio.h>
#include<math.h>
#include<stdlib.h>

long fact(int num){
    if (num == 1 || num == 0)
        return 1;
    return num*fact(num - 1);
}

float root(float coeff[], int degree, float x){
    float sum = 0;
    for (int i = degree; i >= 0; i--)
    {
        sum += (coeff[i]*pow(x, i));
    }
    return sum;
}
void der(float *fx, int degree, float coeff[], int temp){
    int i;
    for (i = 1; i <= degree; i++, temp++)
    {
        fx[i-1] = coeff[i]*temp;
    }
}
int main(){
    int degree, i;
    float a, b, x, fx[10], coeff[10], temp, h, sol, f_x[10], f__x[10], c, d;
    printf("Enter Highest Degree of Equation:\t");
    scanf("%d", &degree);

    temp = 1;
    for (i = 0; i <= degree; i++)
    {
        printf("Enter Coefficient for x^%d:\t", i);
        scanf("%f", &coeff[i]);
    }
    
    printf("\n Entered Equation:\t");
    for (i = degree; i >= 0; i--)
    {
        if (i == 0)
            printf("(%.4f)", coeff[i]);
        else
            printf("(%.4fx^%d)+", coeff[i], i);
    }
    printf("\n Enter The Value of x :\t");
    scanf("%f", &x);
    printf("\n Enter The Value of h :\t");
    scanf("%f", &h);

    a = root(coeff, degree, x);
    der(fx, degree, coeff, temp);
    b = root(fx, degree, x);
    der(f_x, degree, fx, temp);
    c = root(f_x, degree, x);
    der(f__x, degree, f_x, temp);
    d = root(f__x, degree, x);
    der(f__x, degree, f_x, temp);

    sol = a+((h*b)/fact(1))+((h*h*c)/fact(2))+((h*h*h*d)/fact(3));
    printf("\nSolution : %.4f", sol);
    return 0;
}