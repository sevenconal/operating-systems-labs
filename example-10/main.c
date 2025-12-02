#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// This function will be executed by the thread
void *thread_function(void *arg) {
    printf("Inside Thread: Thread ID is %lu\n", pthread_self());
    printf("Inside Thread: Working for 2 seconds...\n");
    sleep(2);
    printf("Inside Thread: Job finished.\n");
    return NULL;
}

int main() {
    pthread_t thread_id;
    int result;

    printf("Main Process: Before creating thread.\n");
    printf("Main Process: My ID is %d\n", getpid());

    // Create a new thread
    // 1. &thread_id: Pointer to store the ID of the new thread
    // 2. NULL: Default thread attributes
    // 3. thread_function: The function to be executed by the thread
    // 4. NULL: Arguments passed to the function (none in this case)
    result = pthread_create(&thread_id, NULL, thread_function, NULL);

    if (result != 0) {
        perror("Thread creation failed");
        exit(1);
    }

    printf("Main Process: Thread created successfully. Waiting for it to join...\n");

    // Wait for the thread to terminate (similar to wait() for processes)
    pthread_join(thread_id, NULL);

    printf("Main Process: Thread has joined. Exiting program.\n");

    return 0;
}