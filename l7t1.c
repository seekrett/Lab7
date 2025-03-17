// This program multiplies 2 5x5 randomly-generated matrices
// 6 different ways to compare if results would be identical.

// include statements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define statements
#define SIZE 5

// function declarations
void createMatrix(int matrix[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);
int compareMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);

// main function
int main() {
    // variable declarations
    int A[SIZE][SIZE], B[SIZE][SIZE];       // base matrices
    int C1[SIZE][SIZE] = {0};               // product matrices
    int C2[SIZE][SIZE] = {0};
    int C3[SIZE][SIZE] = {0};
    int C4[SIZE][SIZE] = {0};
    int C5[SIZE][SIZE] = {0};
    int C6[SIZE][SIZE] = {0};

    // randomize matrices A and B
    srand(time(NULL));
    createMatrix(A);
    createMatrix(B);

    // print matrices A and B
    printf("\nMatrix A:\n");
    printMatrix(A);
    printf("\nMatrix B:\n");
    printMatrix(B);

    // get product 6 different ways

    // ijk
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                C1[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\nProduct IJK:\n");
    printMatrix(C1);

    // ikj
    for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            for (int j = 0; j < SIZE; j++) {
                C2[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\nProduct IKJ:\n");
    printMatrix(C2);

    // kij
    for (int k = 0; k < SIZE; k++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                C3[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\nProduct KIJ:\n");
    printMatrix(C3);

    // jik
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            for (int k = 0; k < SIZE; k++) {
                C4[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\nProduct JIK:\n");
    printMatrix(C4);

    // jki
    for (int j = 0; j < SIZE; j++) {
        for (int k = 0; k < SIZE; k++) {
            for (int i = 0; i < SIZE; i++) {
                C5[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\nProduct JKI:\n");
    printMatrix(C5);

    // kji
    for (int k = 0; k < SIZE; k++) {
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                C6[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    printf("\nProduct KJI:\n");
    printMatrix(C6);

    // compare products
    if (compareMatrices(C1, C2) && compareMatrices(C1, C3) && compareMatrices(C1, C4)
    && compareMatrices(C1, C5) && compareMatrices(C1, C6)) {
        printf("\nAll matrices are equal.\n");
    } else {
        printf("\nMatrices are not equal.\n");
    }
}

// This function populates a given matrix with random integers
void createMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}

// This function prints a given matrix to the screen
void printMatrix(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i ++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// This function compares the 2 matrices.
// Returns 1 if equal, returns 0 if unequal
int compareMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}