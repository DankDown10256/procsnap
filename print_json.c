#include <stdio.h>
#include "json_output.h"
#include "proc.h"

void print_json (ProcInfo info) {
    printf("{\n  \"name\": \"%s\",\n  \"state\": \"%c\",\n  \"ppid\": %ld,\n  \"vmrss\": %lu,\n  \"vmsize\": %lu,\n  \"cmdline\": \"%s\"\n}\n", info.name, info.state, info.ppid, info.vmrss, info.vmsize, info.cmdline);
}
