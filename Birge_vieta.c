#include<stdio.h>
#include<conio.h>
#include<math.h>
#define cols 5
float birgeVietaCalc(float arr2[3][cols], float initRoot){
    unsigned int j, iter = 1, i;
    float prevRoot;
    do{
        for (i = 1; i < 3; i++)
        {
            for (j = 1; j < cols; j++)
                arr2[i][j] = (initRoot * arr2[i][j-1]) + arr2[i-1][j];
        }
        printf("After %d iterations ", iter);
	    printf("p%d is : %f\n", iter-1, initRoot);
        prevRoot = initRoot;
        initRoot = (prevRoot - (arr2[1][cols-1] / arr2[2][cols-2]));
        iter++;
    }while (fabs(prevRoot-initRoot) > 0.02);
    return initRoot;
}
int main()
{
    float p0 = 0.5, arr[3][cols];
    unsigned int i;
    for (i = 0; i < cols; i++)
    {
        printf("Enter a%d\n", i);
        scanf("%f", &arr[0][i]);
    }
    printf("Click 1 To Set initial root otherwise any other key\n");
    if (getch() == '1')
    {
        printf("Enter Initial Root\n");
        scanf("%f", &p0);
    }
    arr[1][0] = arr[0][0];
    arr[2][0] = arr[0][0];
    printf("The Approximated Root is %f\n", birgeVietaCalc(arr, p0));
    return 0;
}

/*Program to implement Birge vieta Method to find the 
root of equation

#include <stdio.h>
#include <math.h>

#define MAX_DEGREE 100
#define EPSILON 0.01
float f_prime(float , int);
float coefficients[MAX_DEGREE + 1]; // Coefficients of the polynomial

float f(float x, int degree) {
    float result = coefficients[degree];
    for (int i = degree - 1; i >= 0; i--) {
        result = result * x + coefficients[i];
    }
    return result;
}

void birgeVieta(float guess, int degree) {
    float x0 = guess;
    float x1;

    do {
        x1 = x0 - f(x0, degree) / f_prime(x0, degree);
        if (fabs(x1 - x0) < EPSILON)
            break;
        x0 = x1;
    } while (1);

    printf("Approximate root: %f\n", x1);
}

float f_prime(float x, int degree) {
    float result = degree * coefficients[degree];
    for (int i = degree - 1; i >= 1; i--) {
        result = result * x + i * coefficients[i];
    }
    return result;
}

int main() {
    int degree;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    printf("Enter the coefficients of the polynomial (from highest to lowest degree):\n");
    for (int i = degree; i >= 0; i--) {
        scanf("%f", &coefficients[i]);
    }

    float guess;
    printf("Enter an initial guess for the root: ");
    scanf("%f", &guess);

    birgeVieta(guess, degree);

    return 0;
}
*/