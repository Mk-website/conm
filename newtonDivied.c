#include <stdio.h>

void calculateCoefficients(double x[], double y[], int n, double coeff[]) {
    for (int i = 0; i < n; i++) {
        coeff[i] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            coeff[i] =(coeff[i] - coeff[i - 1])/(x[i] - x[i - j]);
        }
    }
}

double interpolate(double x[], double coeff[], int n, double xVal) {
    double result = coeff[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        result = result * (xVal - x[i]) + coeff[i];
    }
    return result;
}

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the data points (x, y):\n");
        scanf("%lf %lf", &x[i], &y[i]);
    }

    double coeff[n];
    calculateCoefficients(x, y, n, coeff);

    printf("Enter the value to interpolate: ");
    double xVal;
    scanf("%lf", &xVal);

    double interpolatedValue = interpolate(x, coeff, n, xVal);
    printf("Interpolated value at %lf is %lf\n", xVal, interpolatedValue);

    return 0;
}
