#include <stdio.h>
#include <stdlib.h>

// Function to perform matrix addition
void matrixAddition(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to perform matrix subtraction
void matrixSubtraction(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform traditional matrix multiplication
void matrixMultiplication(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Strassen's Matrix Multiplication Algorithm
void strassenMatrixMultiplication(int n, int A[][n], int B[][n], int C[][n]) {
    if (n <= 64) {
        // If the matrix size is small, perform traditional multiplication
        matrixMultiplication(n, A, B, C);
        return;
    }

    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int P1[newSize][newSize], P2[newSize][newSize], P3[newSize][newSize], P4[newSize][newSize];
    int P5[newSize][newSize], P6[newSize][newSize], P7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Divide matrices A and B into 4 submatrices each
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate 7 products P1, P2, ..., P7
    matrixAddition(newSize, A11, A22, temp1);
    matrixAddition(newSize, B11, B22, temp2);
    strassenMatrixMultiplication(newSize, temp1, temp2, P1);

    matrixAddition(newSize, A21, A22, temp1);
    strassenMatrixMultiplication(newSize, temp1, B11, P2);

    matrixSubtraction(newSize, B12, B22, temp1);
    strassenMatrixMultiplication(newSize, A11, temp1, P3);

    matrixSubtraction(newSize, B21, B11, temp1);
    strassenMatrixMultiplication(newSize, A22, temp1, P4);

    matrixAddition(newSize, A11, A12, temp1);
    strassenMatrixMultiplication(newSize, temp1, B22, P5);

    matrixSubtraction(newSize, A21, A11, temp1);
    matrixAddition(newSize, B11, B12, temp2);
    strassenMatrixMultiplication(newSize, temp1, temp2, P6);

    matrixSubtraction(newSize, A12, A22, temp1);
    matrixAddition(newSize, B21, B22, temp2);
    strassenMatrixMultiplication(newSize, temp1, temp2, P7);

    // Calculate submatrices C11, C12, C21, and C22
    matrixAddition(newSize, P1, P4, temp1);
    matrixSubtraction(newSize, temp1, P5, temp2);
    matrixAddition(newSize, temp2, P7, C11);

    matrixAddition(newSize, P3, P5, C12);

    matrixAddition(newSize, P2, P4, C21);

    matrixAddition(newSize, P1, P3, temp1);
    matrixSubtraction(newSize, temp1, P2, temp2);
    matrixAddition(newSize, temp2, P6, C22);

    // Combine submatrices to get the result
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    
        printf("AABHAS KUMAR JHA - A2305221279\n\n");


    int n;

    printf("Enter the size of the square matrices: ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform Strassen's matrix multiplication
    strassenMatrixMultiplication(n, A, B, C);

    // Display the result matrix C
    printf("Resultant matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
