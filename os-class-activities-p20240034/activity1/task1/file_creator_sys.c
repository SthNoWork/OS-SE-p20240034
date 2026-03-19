/* file_creator_sys.c */
#include <fcntl.h>  // open(), O_WRONLY, O_CREAT, O_TRUNC
#include <unistd.h> // write(), close()
#include <string.h> // strlen()

int main() {
    const char* text = "Hello from Operating Systems class!\n";
    const char* confirm = "File created successfully!\n";
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        const char* err = "Error creating file\n";
        write(STDERR_FILENO, err, strlen(err));
        return 1;
    }
    write(fd, text, strlen(text));
    close(fd);
    write(STDOUT_FILENO, confirm, strlen(confirm));
    return 0;
}