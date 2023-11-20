/*Program to implement gauss elimination Method to find the 
root of equation
*/
#include <stdio.h>
#define N 3
void gaussElimination(float matrix[N][N + 1], float result[N]) {
 int i, j, k;
 float factor;
 for (i = 0; i < N - 1; i++) {
 for (j = i + 1; j < N; j++) {
 factor = matrix[j][i] / matrix[i][i];
 for (k = i; k < N + 1; k++) {
 matrix[j][k] -= factor * matrix[i][k];
 }
 }
 }
 for (i = N - 1; i >= 0; i--) {
 result[i] = matrix[i][N];
 for (j = i + 1; j < N; j++) {
 result[i] -= matrix[i][j] * result[j];
 }
 result[i] /= matrix[i][i];
 }
}
int main() {
 float matrix[N][N + 1], result[N];
 int i, j;
 printf("Enter the Coefficient Matrix\n");
 for (i = 0; i < N; i++) {
 for (j = 0; j < N; j++) {
 printf("%c%d : ", 97+j, i+1);


 scanf("%f", &matrix[i][j]);
 }
 }
 printf("Enter the Constant Matrix\n");
 for (i = 0; i < N; i++){
 printf("%c%d : ", 97+i, i+1);
 scanf("%f", &matrix[i][N]);
 }
 gaussElimination(matrix, result);
 printf("Solution:\n");
 for (i = 0; i < N; i++) {
 printf("x%d = %f\t", i + 1, result[i]);
 }
 return 0;
} 
/*
#include <stdio.h>

#define N 3 // Change this to the number of equations/variables you have

void printMatrix(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussElimination(float matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            float ratio = matrix[j][i] / matrix[i][i];
            for (int k = 0; k <= N; k++) {
                matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
            }
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            matrix[i][N] = matrix[i][N] - matrix[i][j] * matrix[j][N];
        }
        matrix[i][N] = matrix[i][N] / matrix[i][i];
    }
}

int main() {
    float matrix[N][N + 1];

    printf("Enter the augmented matrix (coefficients + constants):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Original augmented matrix:\n");
    printMatrix(matrix);

    gaussElimination(matrix);

    printf("Row echelon form (Gauss elimination):\n");
    printMatrix(matrix);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][N]);
    }

    return 0;
}
*/