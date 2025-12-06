# Example 04 – dup and dup2 System Calls

## Purpose

This program demonstrates how to duplicate file descriptors in Linux using `dup` and `dup2` system calls. This technique is often used in I/O redirection (e.g., redirecting standard output to a file).

## System Calls / Functions Used

- `dup(int oldfd)`: Creates a copy of the file descriptor `oldfd`, using the lowest-numbered unused file descriptor.
- `dup2(int oldfd, int newfd)`: Creates a copy of `oldfd` using the descriptor number specified by `newfd`. If `newfd` was previously open, it is silently closed before being reused.
- `open`, `close`, `printf`: Basic file and output operations.

## How It Works

1. The program opens (or creates) a file named "dup_test.txt".
2. It prints the original file descriptor assigned by the OS (e.g., 3).
3. It calls `dup()` on this descriptor. The OS assigns the next available number (e.g., 4) as a copy. Both descriptors now point to the same open file table entry.
4. It calls `dup2()` to force the duplicate to have a specific number (e.g., 7).
5. Finally, it closes all descriptors.

## How to Compile and Run

$gcc main.c -o app$ ./app

