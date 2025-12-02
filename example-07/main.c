#include <stdio.h>
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
        // Child initially has the original parent
        printf("Child Process: My ID is %d, My Parent ID is %d\n", getpid(), getppid());

        // Sleep for 5 seconds to allow Parent to terminate first
        printf("Child Process: Sleeping for 5 seconds...\n");
        sleep(5);

        // After waking up, Parent should be gone.
        // Child should be adopted by 'init' or 'systemd' (PID 1 or user service manager)
        printf("Child Process: Woke up! My ID is %d, My Parent ID is %d\n", getpid(), getppid());
    }
    else {
        // --- PARENT PROCESS ---
        printf("Parent Process: My ID is %d, My Child ID is %d\n", getpid(), pid);
        
        // Parent exits immediately without waiting for Child
        printf("Parent Process: Exiting now...\n");
    }

    return 0;
}