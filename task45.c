#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define SIZE 10

int **A, **B, **C;

typedef struct {
    int row;
} parameters;

void *multiply_row(void *param) {
    parameters *data = (parameters *)param;
    int row = data->row;

    for (int col = 0; col < SIZE; col++) {
        int sum = 0;
        for (int i = 0; i < SIZE; i++) {
            sum += A[row][i] * B[i][col];
        }
        C[row][col] = sum;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[SIZE];
    parameters params[SIZE];

    // Dynamic allocation of matrices
    A = (int **)malloc(SIZE * sizeof(int *));
    B = (int **)malloc(SIZE * sizeof(int *));
    C = (int **)malloc(SIZE * sizeof(int *));

    for (int i = 0; i < SIZE; i++) {
        A[i] = (int *)malloc(SIZE * sizeof(int));
        B[i] = (int *)malloc(SIZE * sizeof(int));
        C[i] = (int *)malloc(SIZE * sizeof(int));
    }

    // Initialize matrices A and B 
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = i + j;// Example initialization
            B[i][j] = i - j;// Example initialization
        }
    }

    // Record start time
    clock_t start = clock();

    // Create threads for matrix multiplication (row-based)
    for (int i = 0; i < SIZE; i++) {
        params[i].row = i;
        pthread_create(&threads[i], NULL, multiply_row, &params[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

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
    // Display the result matrix C
    printf("\nResultant Matrix C = A * B:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d ", C[i][j]);
        }
        printf("\n");
    }

    printf("\nTime taken: %.2f milliseconds\n", elapsed_time);

    // Deallocate memory
    for (int i = 0; i < SIZE; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);

    return 0;
}
