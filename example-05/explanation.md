# Example 05 – Fork System Call (Process Creation)

## Purpose

This program demonstrates how to create a new process using the `fork()` system call in Linux. It illustrates the concept of parent and child processes and how they execute concurrently.

## System Calls / Functions Used

- `fork()`: Creates a new process by duplicating the calling process.
  - Returns `0` to the child process.
  - Returns the child's PID to the parent process.
  - Returns a negative value on failure.
- `getpid()`: Returns the Process ID (PID) of the calling process.
- `getppid()`: Returns the Process ID of the parent process.

## How It Works

1. The program starts as a single process (parent).
2. It calls `fork()`, which creates a duplicate process (child).
3. After the fork, **both** processes continue execution from the next instruction.
4. The return value of `fork()` is stored in variable `q`.
   - The `if (q == 0)` block runs only in the Child process.
   - The `else` block (where `q > 0`) runs only in the Parent process.
5. Both processes execute the final `printf("Common\n")` statement.
