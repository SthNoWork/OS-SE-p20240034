#define _GNU_SOURCE
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

struct linux_dirent64 {
    ino64_t d_ino;
    off64_t d_off;
    unsigned short d_reclen;
    unsigned char d_type;
    char d_name[];
};

int main(int argc, char *argv[]) {
    const char *path = (argc > 1) ? argv[1] : ".";
    int fd = syscall(SYS_openat, AT_FDCWD, path, O_RDONLY | O_DIRECTORY, 0);
    if (fd == -1) {
        perror("openat");
        return EXIT_FAILURE;
    }

    char buffer[4096];
    for (;;) {
        int nread = syscall(SYS_getdents64, fd, buffer, sizeof(buffer));
        if (nread == -1) {
            perror("getdents64");
            close(fd);
            return EXIT_FAILURE;
        }
        if (nread == 0) {
            break;
        }

        for (int bpos = 0; bpos < nread;) {
            struct linux_dirent64 *d = (struct linux_dirent64 *)(buffer + bpos);
            printf("%s\n", d->d_name);
            bpos += d->d_reclen;
        }
    }

    if (close(fd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
