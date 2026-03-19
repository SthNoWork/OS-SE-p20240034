/* file_reader_sys.c */
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buffer[256];
    ssize_t bytesRead;
    int fd = open("output.txt", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        ssize_t totalWritten = 0;
        while (totalWritten < bytesRead) {
            ssize_t bytesWritten = write(1, buffer + totalWritten, bytesRead - totalWritten);
            if (bytesWritten < 0) {
                perror("Error writing to stdout");
                close(fd);
                return 1;
            }
            totalWritten += bytesWritten;
        }
    }

    if (bytesRead < 0) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    if (close(fd) < 0) {
        perror("Error closing file");
        return 1;
    }

    return 0;
}