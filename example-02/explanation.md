# Example 03 – Open System Call (File Creation and Append)

## Purpose

This program demonstrates how to manipulate files using the `open` system call in Linux. Unlike `read` and `write` which work with existing file descriptors, `open` allows us to create new files or access existing ones with specific modes (read, write, append) and permissions.

## System Calls / Functions Used

- `open(const char *pathname, int flags, mode_t mode)`: Opens a file and returns a file descriptor.
  - `flags`:
    - `O_CREAT`: Creates the file if it does not exist.
    - `O_WRONLY`: Opens the file in write-only mode.
    - `O_APPEND`: Appends data to the end of the file instead of overwriting.
  - `mode`: Specifies file permissions (e.g., `0644` for read/write owner, read-only others).
- `read(int fd, void *buf, size_t count)`: Reads input from the user (stdin).
- `write(int fd, const void *buf, size_t count)`: Writes the captured input into the file using the file descriptor returned by `open`.
- `close(int fd)`: Closes the file descriptor to release resources.

## How It Works

1. The program asks the user to type some text.
2. It reads the input from the keyboard using `read` (fd 0).
3. It calls `open` to access "target.txt".
   - If the file doesn't exist, it creates it.
   - If it exists, it prepares to add text to the end.
4. It writes the user's input into "target.txt" using the new file descriptor.
5. Finally, it closes the file.

## How to Compile and Run

$gcc main.c -o app$ ./app
(Type some text and press Enter)
$ cat target.txt
(Check the file content)
