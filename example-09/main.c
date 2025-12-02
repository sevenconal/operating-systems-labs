#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    printf("Main program started. Creating a child process...\n");

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }
    else if (pid == 0) {
        // --- CHILD PROCESS ---
        printf("Child (PID: %d) is preparing to replace its image with 'ls -l'...\n", getpid());
        
        // execl() replaces the current process image with a new program.
        // 1st argument: Full path to the executable (/bin/ls)
        // 2nd argument: Name of the program (conventionally the file name)
        // 3rd argument: Option/Argument (-l for long listing)
        // Last argument: NULL (must be terminated with NULL)
        execl("/bin/ls", "ls", "-l", NULL);

        // If execl is successful, this line will NEVER be executed.
        // If we reach here, it means execl failed.
        perror("execl failed");
        exit(1);
    }
    else {
        // --- PARENT PROCESS ---
        printf("Parent (PID: %d) waiting for child execution...\n", getpid());
        
        // Wait for the child (which is now running 'ls') to finish
        wait(NULL);
        
        printf("Parent: Child process finished. Back to main program.\n");
    }

    return 0;
}