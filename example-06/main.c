#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // --- CHILD PROCESS ---
        printf("Child (PID: %d) started and working...\n", getpid());
        
        // Sleep for 2 seconds to simulate a long task
        sleep(2);
        
        printf("Child (PID: %d) finished work and exiting.\n", getpid());
        exit(0); // Terminate child process
    }
    else {
        // --- PARENT PROCESS ---
        printf("Parent (PID: %d) waiting for child to finish...\n", getpid());
        
        // wait(NULL) blocks the parent process until the child terminates
        wait(NULL);
        
        printf("Parent (PID: %d) resumed after child termination.\n", getpid());
    }

    return 0;
}