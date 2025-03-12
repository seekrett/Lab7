// This program multiplies 2 5x5 randomly-generated matrices
// 6 different ways to compare if results would be identical.

// include statements
#include <stdio.h>

// define statements
#define SIZE 5

// function declarations
void createMatrix(int matrix[SIZE][SIZE]);
void printMatrix(int matrix[SIZE][SIZE]);
int compareMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]);

// main function
int main() {
    // TO DO
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
    // TODO
}