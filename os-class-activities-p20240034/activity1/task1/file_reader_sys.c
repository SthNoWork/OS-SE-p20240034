#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : "created_by_syscall.txt";
    char buffer[256];

    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    ssize_t nread;
    while ((nread = read(fd, buffer, sizeof(buffer))) > 0) {
        ssize_t total_written = 0;
        while (total_written < nread) {
            ssize_t nwritten = write(STDOUT_FILENO, buffer + total_written, (size_t)(nread - total_written));
            if (nwritten == -1) {
                perror("write");
                close(fd);
                return EXIT_FAILURE;
            }
            total_written += nwritten;
        }
    }

    if (nread == -1) {
        perror("read");
        close(fd);
        return EXIT_FAILURE;
    }

    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
