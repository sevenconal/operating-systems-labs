# Example 06 – Wait System Call (Process Synchronization)

## Purpose

This program demonstrates the use of the `wait()` system call to synchronize parent and child processes. It ensures that the parent process pauses its execution and waits for the child process to complete its task before continuing.

## System Calls / Functions Used

- `fork()`: Creates a new child process.
- `wait(int *status)`: Suspends the execution of the calling process (parent) until one of its children terminates. passing `NULL` means we don't care about the exit status details.
- `sleep(unsigned int seconds)`: Pauses execution for a specified number of seconds (used here to simulate work).
- `exit(int status)`: Terminates the process.

## How It Works

1. The program calls `fork()` to create a child process.
2. **In the Child:**
   - It prints a message indicating it started.
   - It calls `sleep(2)` to simulate a task taking 2 seconds.
   - It prints a finish message and calls `exit(0)`.
3. **In the Parent:**
   - It prints a message saying it is waiting.
   - It calls `wait(NULL)`. At this point, the parent stops and does nothing.
   - Once the child calls `exit()`, the parent wakes up (resumes).
   - The parent prints the final message.

## How to Compile and Run

$gcc main.c -o app$ ./app
