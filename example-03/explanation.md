# Example 03 – lseek System Call (File Positioning)

## Purpose

This program demonstrates the use of the `lseek` system call to reposition the read/write file offset. It shows how to read data from specific locations in a file by moving the file pointer, rather than reading sequentially from the beginning.

## System Calls / Functions Used

- `lseek(int fd, off_t offset, int whence)`: Repositions the file offset of the open file description associated with the file descriptor `fd`.
  - `offset`: The number of bytes to move.
  - `whence`: The starting point for the move.
    - `SEEK_SET`: The beginning of the file.
    - `SEEK_CUR`: The current position of the file pointer.
    - `SEEK_END`: The end of the file.
- `open`, `read`, `write`, `close`: Basic file operations.

## How It Works

1. The program opens a file named "seeking". **Note:** You must create this file beforehand with content (e.g., `1234567890abcdefghijxxxxxxxxxx`) for the output to match the video example.
2. It reads and prints the first 10 characters.
3. It uses `lseek` with `SEEK_CUR` to skip the next 10 characters (effectively jumping over the middle part of the file).
4. It reads and prints the subsequent 10 characters.

## How to Compile and Run

1. Create the dummy file first:
   $ echo "1234567890abcdefghijxxxxxxxxxx" > seeking
2. Compile and run:
   $ gcc main.c -o app
   $ ./app

