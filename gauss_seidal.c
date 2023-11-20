//Gauss Seidel Method
#include <stdio.h>
#include <math.h>
#define N 3
#define MAX_ITERERATIONS 50
int dominantMatrix(float A[N][N]){
 int i, j;
 for (i = 0; i < N-1; i++){
 for (j = i+1; j < N; j++){
 if (A[i][i] < A[j][i])
 return 0;
 }
 }
 return 1;
}
void gaussSeidel(float A[N][N], float b[N], float x[N]){
 int iter;
 float temp[N];
 for (iter = 0; iter < MAX_ITERERATIONS; iter++){
 for (int i = 0; i < N; i++){
 temp[i] = b[i];
 for (int j = 0; j < N; j++){
 if (i != j){
 temp[i] -= A[i][j] * x[j];
 }
 }
 x[i] = temp[i] / A[i][i];
 }
 }
}
int main(){
 float coeff[N][N];
 float consts[N];
 float res[N];
 int i, valid;
 printf("Enter the Coefficient Matrix\n");
 for (i = 0; i < N; i++){
 for (int j = 0; j < N; j++){
 printf("%c%d : ", 97+j, i+1);
 scanf("%f", &coeff[i][j]);
 }
 }
 valid = dominantMatrix(coeff);
 if (!valid){
 printf("Matrix is Not Dominant\n");
 return 0;
 }
 printf("Enter the Constant Matrix\n");
 for (i = 0; i < N; i++){
 printf("%c%d : ", 97 + i, i + 1);
 scanf("%f", &consts[i]);
 res[i] = 0.0;
 }
 gaussSeidel(coeff, consts, res);
 printf("Solution:\n");
 for (i = 0; i < N; i++)
 {
 printf("x%d = %.4f\n", i + 1, res[i]);
 }
 return 0;
} 
/*
#include <stdio.h>
#include <math.h>

#define N 3 // Change this to the number of equations/variables you have
#define MAX_ITER 100
#define TOLERANCE 0.0001

void printVector(float vector[N]) {
    for (int i = 0; i < N; i++) {
        printf("x%d = %.6f\n", i + 1, vector[i]);
    }
    printf("\n");
}

int main() {
    float coefficients[N][N + 1];
    float x[N] = {0}; // Initial guess for variables
    float new_x[N];

    printf("Enter the augmented matrix (coefficients + constants):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%f", &coefficients[i][j]);
        }
    }

    printf("Original augmented matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f ", coefficients[i][j]);
        }
        printf("\n");
    }

    printf("Initial guess:\n");
    printVector(x);

    int iter;
    for (iter = 0; iter < MAX_ITER; iter++) {
        for (int i = 0; i < N; i++) {
            float sum = 0;
            for (int j = 0; j < N; j++) {
                if (j != i) {
                    sum += coefficients[i][j] * x[j];
                }
            }
            new_x[i] = (coefficients[i][N] - sum) / coefficients[i][i];
        }

        int convergence = 1;
        for (int i = 0; i < N; i++) {
            if (fabs(new_x[i] - x[i]) > TOLERANCE) {
                convergence = 0;
                break;
            }
        }

        if (convergence) {
            break;
        }

        for (int i = 0; i < N; i++) {
            x[i] = new_x[i];
        }
    }

    printf("Solution after %d iterations:\n", iter + 1);
    printVector(x);

    return 0;
}
*/