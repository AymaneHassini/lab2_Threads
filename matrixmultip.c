#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int A[SIZE][SIZE];
int B[SIZE][SIZE];
int C[SIZE][SIZE];

void multiply_matrices() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Initialize matrices A and B
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = i + j;  // Some arbitrary initialization
            B[i][j] = i - j;  // Some arbitrary initialization
        }
    }

    // Record start time
    clock_t start = clock();

    // Perform matrix multiplication
    multiply_matrices();

    // Record end time
    clock_t end = clock();

    // Calculate elapsed time in milliseconds
    double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000.0;

    // Display matrices A and B
    printf("Matrix A:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", B[i][j]);
        }
        printf("\n");
    }

    // Display separator
    printf("\n---------------------------\n");

    // Display the result matrix C
    printf("Resultant Matrix C = A * B:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    // Display elapsed time
    printf("\nTime taken for normal multiplication: %.2f milliseconds\n", elapsed_time);

    return 0;
}
