#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    int n, fd;
    char buffer[10];

    // Open the file "seeking" (Assumed to contain: 1234567890abcdefghijxxxxxxxxxx)
    fd = open("seeking", O_RDWR);
    if (fd < 0) {
        perror("Failed to open file 'seeking'");
        return 1;
    }

    // 1. Read first 10 characters
    read(fd, buffer, 10);
    write(1, buffer, 10); // Output: 1234567890
    printf("\n");

    // 2. Skip next 10 characters from CURRENT position
    // lseek(fd, 10, SEEK_CUR); 
    // This moves the pointer past 'abcdefghij'
    lseek(fd, 10, SEEK_CUR);

    // 3. Read next 10 characters after the skip
    read(fd, buffer, 10);
    write(1, buffer, 10); // Output: xxxxxxxxxx
    printf("\n");

    // Optional: Go back 10 positions from END and read
    // lseek(fd, -10, SEEK_END);
    // read(fd, buffer, 10);
    // write(1, buffer, 10);

    close(fd);

    return 0;
}