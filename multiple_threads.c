#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// thread function
void *thread_function(void *arg) {
    int thread_id = *(int *)arg;
    printf("Thread %d: Running...\n", thread_id);
    free(arg); // free memory allocated for argument
    pthread_exit(NULL);
}

int main() {
    const int NUM_THREADS = 4; 
    pthread_t threads[NUM_THREADS];
    int i, result;

    // create threads
    for (i = 0; i < NUM_THREADS; i++) {
        int *arg = malloc(sizeof(int)); // allocate memory for thread ID
        *arg = i;
        result = pthread_create(&threads[i], NULL, thread_function, arg);
        if (result != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(1);
        }
    }

    // wait for threads to finish
    for (i = 0; i < NUM_THREADS; i++) {
        result = pthread_join(threads[i], NULL);
        if (result != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(1);
        }
    }

    printf("All threads completed.\n");
    return 0;
}
