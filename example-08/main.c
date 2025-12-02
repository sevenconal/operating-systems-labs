#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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
        printf("Child (PID: %d) is running...\n", getpid());
        
        // Child exits immediately
        // Since Parent is sleeping and not calling wait(), this Child becomes a ZOMBIE
        printf("Child (PID: %d) exiting and becoming a Zombie.\n", getpid());
        exit(0);
    }
    else {
        // --- PARENT PROCESS ---
        printf("Parent (PID: %d) created Child (PID: %d)\n", getpid(), pid);
        
        // Sleep for 10 seconds to keep the Parent alive but busy (not waiting)
        // During this time, the Child is in a ZOMBIE state
        printf("Parent (PID: %d) sleeping for 10 seconds. Check 'ps' command now!\n", getpid());
        sleep(10);
        
        printf("Parent (PID: %d) woke up and exiting.\n", getpid());
    }

    return 0;
}