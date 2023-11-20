#include<stdio.h>
#include<math.h>
float func(float x){  
    return (x*x*x+x-1);  
}   
int main(){  
    float l1, l2, r;  
    unsigned int iter = 1;
    printf("Enter the first approximation of the root: ");  
    scanf("%f", &l1);  
    printf("Enter the second approximation of the root: ");  
    scanf(" %f", &l2);
    r = l1;
    if(func(l1) == 0)  
        printf ("The approximation of the root is: %f \n ", l1);   
    else if(func(l2) == 0)  
        printf ("The approximation of the root is: %f \n ", l2);   
    else if(func(l1)*func(l2) > 0)
        printf("Root Does Not Lie Between Given Approximations\n");
    else{  
        do{     
            if(func(r) == 0)
                break; 
            if(func(l1)*func(r) < 0)
                l2 = r;  
            else if(func(r)*func(l2) < 0)  
                l1 = r;  
            r = ((l1*func(l2))-(l2*func(l1)))/(func(l2)-func(l1));
            printf("After %d iterations ", iter);
            printf("a = %f and b = %f\n", l1, l2);
            printf("x%d = %f \t f(x%d) = %f\n", iter, r, iter, func(r));
            iter++;  
        }while(fabs(func(r)) > 0.0001);
        printf("\nThe approximation of the root is: %f \n ", r);   
    }     
    return 0;  
}    

/*Program to implement false position Method to find the 
root of equation x * x * x -2*x- 5

#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITERATIONS 100

float f(float x) {
    return x * x * x -2*x- 5; // Change this to your desired function
}

float falsePosition(float a, float b, int *iterations) {
    float c;
    
    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (f(c) == 0.0 || fabs(b - a) < EPSILON)
            break;

        if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        (*iterations)++;
    } while (*iterations < MAX_ITERATIONS);

    return c;
}

int main() {
    float a, b, root;
    int iterations = 0;

    printf("Enter values of a and b: ");
    scanf("%f %f", &a, &b);

    if (f(a) * f(b) > 0) {
        printf("Function does not have a root in the given interval.\n");
    } else {
        root = falsePosition(a, b, &iterations);
        if (iterations == MAX_ITERATIONS) {
            printf("False Position method did not converge after %d iterations.\n", MAX_ITERATIONS);
        } else {
            printf("Approximate root: %f\n", root);
            printf("Number of iterations: %d\n", iterations);
        }
    }

    return 0;
}
*/