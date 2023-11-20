//Gauss Jordon Method
#include <stdio.h>
#define N 3
void gaussJordanElimination(float matrix[N][N + 1]) {
 for (int i = 0; i < N; i++) {
 float maxVal = matrix[i][i];
 int maxRow = i;
 for (int k = i + 1; k < N; k++) {
 if (matrix[k][i] > maxVal) {
 maxVal = matrix[k][i];
 maxRow = k;
 }
 }
 for (int k = i; k <= N; k++) {
 float temp = matrix[i][k];
 matrix[i][k] = matrix[maxRow][k];
 matrix[maxRow][k] = temp;
 }
 float pivot = matrix[i][i];
 for (int j = i; j <= N; j++) {
 matrix[i][j] /= pivot;
 }
 for (int k = 0; k < N; k++) {
 if (k != i) {
 float factor = matrix[k][i];
 for (int j = i; j <= N; j++) {
 matrix[k][j] -= factor * matrix[i][j];
 }
 }
 }
 }
}
int main() {
 float matrix[N][N + 1];
 int i, j;
 printf("Enter the Coefficient Matrix\n");
 for (i = 0; i < N; i++) {


 for (j = 0; j < N; j++) {
 printf("%c%d : ", 97+j, i+1);
 scanf("%f", &matrix[i][j]);
 }
 }
 printf("Enter the Constant Matrix\n");
 for (i = 0; i < N; i++)
 {
 printf("%c%d : ", 97+i, i+1);
 scanf("%f", &matrix[i][N]);
 }
 gaussJordanElimination(matrix);
 printf("Solution:\n");
 for (int i = 0; i < N; i++) {
 printf("x%d = %.2f\n", i + 1, matrix[i][N]);
 }
 return 0;
} 

/*
#include <stdio.h>
#include <math.h>

#define N 3 // Change this to the number of equations/variables you have

void printMatrix(float matrix[N][2 * N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussJordan(float matrix[N][2 * N]) {
    for (int i = 0; i < N; i++) {
        // Pivot element
        float pivot = matrix[i][i];

        // Divide the current row by the pivot element
        for (int j = 0; j < 2 * N; j++) {
            matrix[i][j] /= pivot;
        }

        // Eliminate all other entries in the current column
        for (int k = 0; k < N; k++) {
            if (k != i) {
                float factor = matrix[k][i];
                for (int j = 0; j < 2 * N; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    float coefficients[N][N + 1];
    float augmentedMatrix[N][2 * N];

    printf("Enter the augmented matrix (coefficients + constants):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            scanf("%f", &coefficients[i][j]);
        }
    }

    // Initialize the augmented matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            augmentedMatrix[i][j] = coefficients[i][j];
        }
        for (int j = N; j < 2 * N; j++) {
            augmentedMatrix[i][j] = (i == j - N) ? 1.0 : 0.0;
        }
    }

    printf("Original augmented matrix:\n");
    printMatrix(augmentedMatrix);

    gaussJordan(augmentedMatrix);

    printf("Reduced row-echelon form (Gauss-Jordan elimination):\n");
    printMatrix(augmentedMatrix);

    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i + 1, augmentedMatrix[i][N]);
    }

    return 0;
}
*/