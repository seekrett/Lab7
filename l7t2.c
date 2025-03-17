// This program compares the time taken to multiply matrices of different sizes
// to check which process is more efficient in accessing memory.

// include statements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// function declarations
void createMatrix(int size, double matrix[size][size]);
void multiplyMatrices(int size, double A[size][size], double B[size][size], double C[size][size], int order);

// main function
int main() {
    // variable declarations
    int sizes[] = {20, 40, 80, 160, 320, 640, 1280};        // matrix sizes
    int numOfSizes = sizeof(sizes) / sizeof(sizes[0]);      // total num of sizes 
    int numOfOrders = 6;                                    // num of multiplication orders
    
}

// This function populates random elements in a matrix of a given size.
void createMatrix(int size, double matrix[size][size]) {
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = (double) rand() / RAND_MAX;
        }
    }
}

// This function multiplies two matrices of the same size in differing orders.
void multiplyMatrices(int size, double A[size][size], double B[size][size], double C[size][size], int order) {
    // set product matrix C to 0
    for (int i = 0; i < size; i ++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0.0;
        }
    }

    // multiply based on order
    switch (order) {
        // ijk
        case 0:
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    C[i][j] = A[i][k] * B[k][j];
                }
            }
        }
        break;

        // ikj
        case 1:
        for (int i = 0; i < size; i++) {
            for (int k = 0; k < size; k++) {
                for (int j = 0; j < size; j++) {
                    C[i][j] = A[i][k] * B[k][j];
                }
            }
        }
        break;

        // kij
        case 2:
        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        break;

        // jik
        case 3:
        for (int j = 0; j < size; j++) {
            for (int i = 0; i < size; i++) {
                for (int k = 0; k < size; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        break;

        // jki
        case 4:
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                for (int i = 0; i < size; i++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        break;

        // kji
        case 5:
        for (int k = 0; k < size; k++) {
            for (int j = 0; j < size; j++) {
                for (int i = 0; i < size; i++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        break;
    }
}