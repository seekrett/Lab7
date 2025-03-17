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
    //TODO
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
    //TODO
}