# Example 08 – Zombie Process

## Purpose

This program demonstrates the creation of a "Zombie Process". A zombie process is a child process that has completed its execution (terminated) but still has an entry in the process table because its parent has not yet read its exit status using `wait()`.

## System Calls / Functions Used

- `fork()`: Creates a new child process.
- `exit(int status)`: Terminates the child process.
- `sleep(unsigned int seconds)`: Delays the parent process execution, keeping the child in the zombie state for observation.

## How It Works

1. The program creates a child process using `fork()`.
2. **Child Process:** Prints a message and exits immediately using `exit(0)`.
3. **Parent Process:** - Prints its own PID and the Child's PID.
   - Sleeps for 10 seconds. **Crucially**, it does NOT call `wait()`.
4. While the parent is sleeping, the child has already finished but cannot fully disappear from the system. It becomes a **Zombie**.
5. You can verify this by opening another terminal window while the parent is sleeping and running:
   `$ ps -aux | grep Z`
   or look for the status `Z+` or `<defunct>`.

## How to Compile and Run

$gcc main.c -o app$ ./app
