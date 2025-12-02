# Example 10 – Thread Creation (pthread)

## Purpose

This program demonstrates how to create and manage threads in Linux using the POSIX Threads (pthread) library. Unlike `fork()`, which duplicates the entire process, `pthread_create()` creates a new thread of execution within the _same_ process, sharing memory and resources.

## System Calls / Functions Used

- `pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)`: Creates a new thread.
  - `thread`: Pointer to a variable that will store the thread ID.
  - `attr`: Thread attributes (NULL for defaults).
  - `start_routine`: The function the thread will execute.
  - `arg`: Argument to pass to the function (NULL if none).
- `pthread_join(pthread_t thread, void **retval)`: Blocks the calling thread until the specified thread terminates.
- `pthread_self()`: Returns the ID of the calling thread.

## How It Works

1. The main function prints its Process ID (PID).
2. It calls `pthread_create` to start a new thread that executes `thread_function`.
3. **In the Thread:**
   - Prints its own Thread ID.
   - Sleeps for 2 seconds to simulate work.
   - Finishes execution.
4. **In the Main Thread:**
   - Calls `pthread_join` to wait for the new thread to finish.
   - Once the thread finishes, the main program continues and exits.

## How to Compile and Run

**Note:** You must link the pthread library using `-lpthread`.

$gcc main.c -o app -lpthread$ ./app
