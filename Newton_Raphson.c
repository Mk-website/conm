#include <stdio.h>
#include <math.h>
float func(float x){
    return (x*x*x - 5*x + 3);
}
float dfunc(float x){
    return (3*x*x - 5);
}
float nRCalc(float x){
    unsigned int iter = 1;
    float prevX;
    do{
        if(func(x) == 0){
            return x;
        }
        prevX = x;
        x = prevX - (func(prevX) / dfunc(prevX));
        printf("After %d iterations x%d = %f\n", iter, iter, x);
        printf("f(x%d) = %f\n", iter, func(x));
        printf("f'(x%d) = %f\n", iter, dfunc(x));
        iter++;
    } while (fabs(prevX - x) > 0.02);
    return x;
}
int main(){
    float x;
    printf("Enter the initial root: \n");
    scanf("%f", &x);
    if (func(x) == 0)
        printf("The approximation of the root is: %f \n ", x);
    else
        printf("\nThe approximation of the root is: %f \n ", nRCalc(x));
    return 0;
}

/*Program to implement Newton Raphson Method to find the 
root of equation x * x * x - x - 4

#include <stdio.h>
#include <math.h>

#define EPSILON 0.01

float f(float x) {
    return x * x * x - x - 4; // Replace this with your desired function
}

float f_prime(float x) {
    return 3 * x * x - 1; // Replace this with the derivative of your function
}

float newtonRaphson(float x0) {
    float x1;
    int iterations = 0; // Counter for iterations

    do {
        x1 = x0 - f(x0) / f_prime(x0);
        if (fabs(x1 - x0) < EPSILON)
            break;
        x0 = x1;
        iterations++; // Increment the iteration counter
    } while (1);

    printf("Number of iterations: %d\n", iterations); // Print the number of iterations

    return x1;
}

int main() {
    float x0, root;

    printf("Enter initial guess x0: ");
    scanf("%f", &x0);

    root = newtonRaphson(x0);

    printf("Approximate root: %f\n", root);

    return 0;
}
*/