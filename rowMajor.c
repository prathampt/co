#include <stdlib.h>

#define SIZE 1024

void matrix_multiply_row_major(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void matrix_multiply_column_major(double A[SIZE][SIZE], double B[SIZE][SIZE], double C[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void initialize_matrix(double matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main() {
    static double A[SIZE][SIZE];
    static double B[SIZE][SIZE];
    static double C[SIZE][SIZE];

    initialize_matrix(A);
    initialize_matrix(B);

    matrix_multiply_row_major(A, B, C);

    return 0;
}
