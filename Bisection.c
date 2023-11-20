/*Program to implement Bisection Method to find the 
root of equation x^2-4x-10
*/
#include <stdio.h>
#include <math.h> // Include the math library for fabs function
float f(float x)
{
  return x * x - 4 * x - 10;
}
int main()
{
  float a, b, mid, e = 0.01; // Change the data types to float
  int c = 1; // Counter for iterations

  printf("Enter Value of a\n");
  scanf("%f", &a);
  printf("Enter Value of b\n");
  scanf("%f", &b);
  if (f(a) == 0)
  {
    printf("Root is %f\n", a);
  }
  else if (f(b) == 0)
  {
    printf("Root is %f\n", b);
  }
  else if (f(a) * f(b) > 0)
  {
    printf("Root does not lie between Given Approximation\n");
  }
  else
  {
    while (fabs(b - a) > e) // Use fabs for absolute difference
    {
      mid = (a + b) / 2.0;
      if (f(mid) == 0)
      {
        printf("Root is %f\n", mid);
        return 0;
      }
      if (f(a) * f(mid) < 0)
      {
        b = mid;
      }
      else if (f(mid) * f(b) < 0)
      {
        a = mid;
      }
      printf("After %d iterations a=%f and b=%f\n", c, a, b);
      c++;
    }
    printf("\n The Approximation of the Root is %f \n", (a + b) / 2.0);
  }
  return 0;
}
