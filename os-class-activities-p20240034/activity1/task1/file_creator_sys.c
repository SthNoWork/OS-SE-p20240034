/* file_creator_sys.c */
#include <fcntl.h>  // open(), O_WRONLY, O_CREAT, O_TRUNC
#include <unistd.h> // write(), close()
#include <string.h> // strlen()

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    const char* message = "Hello from Operating Systems class!\n";
    if (write(fd, message, strlen(message)) == -1) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }
    close(fd);
    const char* success_message = "File created successfully!\n";
    if (write(STDOUT_FILENO, success_message, strlen(success_message)) == -1) {
        perror("Error writing to terminal");
        return 1;
    }
    return 0;
}