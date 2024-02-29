#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

// thread 1 function: Counts up 
void *count_up(void *arg) {
    int max_count = *(int *)arg;
    for (int i = 0; i <= max_count; i++) {
        printf("Thread 1: Counting up  %d\n", i);
        sleep(1); //  delay 
    }
    pthread_exit(NULL);
}

// thread 2 ft: Counts down
void *count_down(void *arg) {
    int max_count = *(int *)arg;
    for (int i = max_count; i >= 0; i--) {
        printf("Thread 2: Counting down  %d\n", i);
        sleep(1);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int max_count = 10; // max count for both threads
    int result;

    // create 1st thread
    result = pthread_create(&thread1, NULL, count_up, &max_count);
    if (result != 0) {
        fprintf(stderr, "Error creating thread 1\n");
        exit(1);
    }

    // create 2nd thread
    result = pthread_create(&thread2, NULL, count_down, &max_count);
    if (result != 0) {
        fprintf(stderr, "Error creating thread 2\n");
        exit(1);
    }

    // Wait for threads to finish
    result = pthread_join(thread1, NULL);
    if (result != 0) {
        fprintf(stderr, "Error joining thread 1\n");
        exit(1);
    }
    result = pthread_join(thread2, NULL);
    if (result != 0) {
        fprintf(stderr, "Error joining thread 2\n");
        exit(1);
    }

    printf("Both threads completed.\n");
    return 0;
}
