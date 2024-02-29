Task 1: Thread Creation and Termination

Learn how to create and terminate a thread using pthreads.
Activities

Write a simple program to create a single thread.
Use pthread_create to start the thread and pthread_join to wait for its completion.
In the thread, print a message and then exit.
In the main thread, wait for the thread to finish and then print a completion message.
Task 2: Create Multiple Threads

Understand how to manage multiple threads and their execution order.
Activities

Write a program that creates multiple threads (e.g., 3 or 4).
Pass a unique identifier or message to each thread.
In each thread, print a message that includes its unique identifier.
Use pthread_join in the main thread to wait for all threads to complete.
Task 3: Manipulate Two Threads with Two Tasks

Learn to coordinate tasks between threads and understand the independence of thread executions.
Activities

Create a program with two different functions to be executed by two different threads.
Use pthread_create to start the threads, each with its respective function.
In one function, perform a simple task (e.g., count up to a number).
In the second function, perform a different simple task (e.g., count down from a number).
Use pthread_join to wait for both threads to finish their tasks.
Task 4: Parallel Calculation using Threads (Matrix Multiplication)

Utilize threads to perform a parallel computation, demonstrating the performance benefit of multithreading.
Activities

Write a program that performs matrix multiplication using threads.
Create two matrices and initialize them with values.
Divide the task of matrix multiplication so that each thread computes a part of the result matrix.
Start a thread for each part of the calculation, passing the necessary data for computation.
Use pthread_join to wait for all threads to complete their calculations.
Combine the results from each thread and display the final matrix.
