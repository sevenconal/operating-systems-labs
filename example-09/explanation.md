# Example 09 – execl System Call (Process Image Replacement)

## Purpose

This program demonstrates the use of the `execl()` system call. While `fork()` creates a copy of the current process, `exec` family functions (like `execl`) replace the current process's memory space (code, data, stack) with a new program. This is how shells run commands.

## System Calls / Functions Used

- `execl(const char *path, const char *arg, ...)`: Replaces the current process image with a new process image specified by `path`.
  - `path`: The absolute path to the executable (e.g., `/bin/ls`).
  - `arg0`: The name of the program (usually same as the executable name).
  - `arg1...`: Arguments passed to the program.
  - `NULL`: A required terminator for the argument list.
- `fork()`: Creates a new process.
- `wait()`: Waits for the child process to finish.

## How It Works

1. The program creates a child process using `fork()`.
2. **In the Child:**
   - It prints a message.
   - It calls `execl("/bin/ls", "ls", "-l", NULL)`.
   - The OS loads the `ls` program into the child's memory, overwriting the C program code.
   - The child process effectively _becomes_ the `ls` command.
   - The `ls -l` command lists the directory contents.
3. **In the Parent:**
   - It waits for the child to finish.
   - Once the `ls` command finishes (the child exits), the parent resumes and prints a completion message.

## How to Compile and Run

$gcc main.c -o app$ ./app
