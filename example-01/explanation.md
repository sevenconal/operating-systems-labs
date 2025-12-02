# Example 02 – Read and Write System Calls

## Purpose

The purpose of this program is to demonstrate the usage of basic I/O system calls `read` and `write` in Linux. It shows how to read input directly from the keyboard (Standard Input) and write it back to the screen (Standard Output) without using high-level functions like `printf` or `scanf`.

## System Calls / Functions Used

- `read(int fd, void *buf, size_t count)`: Reads data from a file descriptor.
  - `fd`: File descriptor (0 for Standard Input).
  - `buf`: Buffer to store the data.
  - `count`: Maximum number of bytes to read.
- `write(int fd, const void *buf, size_t count)`: Writes data to a file descriptor.
  - `fd`: File descriptor (1 for Standard Output).
  - `buf`: Buffer containing data to write.
  - `count`: Number of bytes to write.

## How It Works

1. The program defines a character buffer of size 30.
2. It calls `read` with file descriptor `0` (stdin). It attempts to read up to 30 bytes from the user's input.
3. The `read` function returns the actual number of bytes read (stored in variable `n`).
4. It calls `write` with file descriptor `1` (stdout), passing the buffer and the exact number of bytes (`n`) that were read. This ensures that only the typed characters are printed, avoiding garbage values from the uninitialized parts of the buffer.

## How to Compile and Run

$gcc main.c -o app$ ./app
(Type something and press Enter)
