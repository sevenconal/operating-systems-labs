#include <unistd.h>

int main() {
    int n;
    char buffer[30];

    // Read from Standard Input (Keyboard)
    // 0: File Descriptor for Standard Input
    // buffer: Storage location for read data
    // 30: Maximum number of bytes to read
    n = read(0, buffer, 30);

    // Write to Standard Output (Screen)
    // 1: File Descriptor for Standard Output
    // buffer: Data to be written
    // n: Number of bytes actually read (returned by read function)
    write(1, buffer, n);

    return 0;
}