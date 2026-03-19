/* dir_list_sys.c */
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h> // only for snprintf to format numbers into strings

int main() {
    char buffer[512];
    DIR* dir = opendir(".");
    if (dir == NULL) {
        const char* err = "Error opening directory\n";
        write(2, err, strlen(err));
        return 1;
    }

    const char* header = "Name\t\tSize (bytes)\n";
    write(1, header, strlen(header));

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        struct stat st;
        if (stat(entry->d_name, &st) == -1) {
            continue;
        }

        int len = snprintf(buffer, sizeof(buffer), "%-16s %ld\n", entry->d_name, (long)st.st_size);
        if (len > 0) {
            write(1, buffer, (size_t)len);
        }
    }

    closedir(dir);

    return 0;
}