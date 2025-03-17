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
    // universal variable declarations
    int sizes[] = {20, 40, 80, 160, 320, 640, 1280};        // matrix sizes
    int numOfSizes = sizeof(sizes) / sizeof(sizes[0]);      // total num of sizes 
    int numOfOrders = 6;                                    // num of multiplication orders
    
    // for each size,
    for (int i = 0; i < numOfSizes; i++) {
        // local variable declarations
        int size = sizes[i];                                // tracks current size dealing with
        double A[size][size], B[size][size], C[size][size]; // initialize each matrix

        // create a matrix
        createMatrix(size, A);
        createMatrix(size, B);

        // print size
        printf("\n----- MATRICES SIZE %dx%d -----\n", size, size);

        // get product 6 different ways
        for (int order = 0; order < numOfOrders; order++) {
            // get time taken and multiply
            clock_t start = clock();
            multiplyMatrices(size, A, B, C, order);
            clock_t end = clock();
            double timeTaken = (double)(end - start) / CLOCKS_PER_SEC;

            // print time taken
            printf("\nTime taken: %.6f seconds\n", timeTaken);
            // print order
            switch (order) {
                case 0:
                printf("Order: ijk\n");
                break;
                case 1:
                printf("Order: ikj\n");
                break;
                case 2:
                printf("Order: kij\n");
                break;
                case 3:
                printf("Order: jik\n");
                break;
                case 4:
                printf("Order: jki\n");
                break;
                case 5:
                printf("Order: kji\n");
                break;
            }
        }
    }
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