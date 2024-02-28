// necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// function to be executed by the thread
void *thread_function(void *arg) {
    printf("Inside the thread\n"); // print message indicating thread execution
    pthread_exit(NULL); // exit
}

int main() {
    pthread_t thread; // declare a pthread variable to represent the thread
    int result;

    // create the thread 
    result = pthread_create(&thread, NULL, thread_function, NULL);
    if (result != 0) { // check if thread creation is successful
        fprintf(stderr, "Error creating thread\n");
        exit(1);
    }

    // waiting for the thread to finish
    result = pthread_join(thread, NULL); 
    if (result != 0) { // checking if thread joining was successful
        fprintf(stderr, "Error joining thread\n");
        exit(1);
    }

    printf("Thread finished, back in the main thread\n");  // print message indicating main thread execution
    return 0;
}
