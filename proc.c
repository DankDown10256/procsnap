#include "proc.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

ProcInfo get_proc_infos (long pid) {
    char path[64];
    snprintf(path, sizeof(path), "/proc/%ld/stat", pid);
    ProcInfo info = {0};
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "PID Not found\n");
        return info;
    }

    char buf[4096];
    ssize_t n = read(fd, buf, sizeof(buf) - 1);

    if (n == -1) {
        fprintf(stderr, "Error in reading\n");
        return info;
    }
    buf[n] = '\0';
    char *start = strchr(buf, '(');
    char *end = strrchr(buf, ')');
    snprintf(info.name, sizeof(info.name), "%.*s", (int)(end - start -1), start + 1);
    sscanf(end + 2, "%c %ld", &info.state, &info.ppid);
    close(fd);
    return info;
}
