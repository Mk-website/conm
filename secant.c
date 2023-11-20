#include<stdio.h>
#include<math.h>
float func(float x)
{
return (x*x*x*x - x - 10);
}
    
float secCalc(float a, float b){
    float x = a, prevX;
    unsigned int iter = 1;
    do{
        if(func(x)==0)
            return x;
        if(func(a)*func(x)<0)
            b=x;
        else
            a=x;
        prevX = x;
        x = (a-(func(a)*((b-a)/(func(b)-func(a)))));
        printf ("After %d iterations ", iter);
        printf("a = %f and b = %f\n", a, b);
        printf("x%d = %f \t f(x%d) = %f\n", iter, x, iter, func(x));
        iter++;
    }while(fabs(prevX - x) > 0.02);
    return x;
}
int main(){
    float a, b;
    printf("Enter the first approximation of the root: \n");  
    scanf("%f", &a);
    printf("Enter the second approximation of the root: \n");  
    scanf("%f", &b);  
    if(func(a) == 0)
        printf ("The approximation of the root is: %f \n ", a);  
    else if(func(b) == 0)
        printf ("The approximation of the root is: %f \n ", b);
    else if(func(a)*func(b) > 0)
        printf("Root Does Not Lie Between Given Approximations\n");
    else
        printf("The approximate root is %f", secCalc(a,b));
    return 0;
}

/*Program to implement Secant Method to find the 
root of equation cosx-xe^x

#include <stdio.h>
#include<stdlib.h>
#include <math.h>

#define EPSILON 0.001

float f(float x) {
    return cos((float)x)-x*exp((float)x); // Replace this with your desired function
}

float secant(float x0, float x1) {
    float x2, f0, f1;
    int iterations = 0; // Counter for iterations

    do {
        f0 = f(x0);
        f1 = f(x1);

        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);

        x0 = x1;
        x1 = x2;
        iterations++; // Increment the iteration counter
    } while (fabs(f(x2)) >= EPSILON);

    printf("Number of iterations: %d\n", iterations); // Print the number of iterations

    return x2;
}

int main() {
    float x0, x1, root;

    printf("Enter initial values x0 and x1: ");
    scanf("%lf %lf", &x0, &x1);

    root = secant(x0, x1);

    printf("Approximate root: %lf\n", root);

    return 0;
}
*/