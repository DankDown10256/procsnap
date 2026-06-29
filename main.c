#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proc.h"
#include "json_output.h"

void usage(void) {
    fprintf(stderr, "Usage:\n procsnap <pid> (find a PID)\n procsnap --json <pid> (json output mode)\n procsnap --diff <pid> (view diff in a given PID)\n procsnap -g <name>\n");
}

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        if (argv[1][0] == '-') {
            if (strcmp(argv[1], "--json") == 0) {
                // JSON mode
                if (argc < 3) {
                    fprintf(stderr, "Entry not valid\n");
                    return 1;
                }
                else {
                    char *endptr;
                    long pid = strtol(argv[2], &endptr, 10);
                    if (*endptr != '\0' || pid <= 0) {
                        fprintf(stderr, "Entry not valid\n");
                        return 1;
                    }

                    ProcInfo info = get_proc_infos(pid);
                    if (info.name[0] == '\0') {
                        fprintf(stderr, "Process not found\n");
                        return 1;
                    }
                    print_json(info);
                }
            }
            else if (strcmp(argv[1], "--diff") == 0) {
                // diff mode
                if (argc < 3) {
                    fprintf(stderr, "Entry not valid\n");
                    return 1;
                }
                else {
                    // code diff
                }
            }
            else if (strcmp(argv[1], "-g") == 0) {
                // g mode
                if (argc < 3) {
                    fprintf(stderr, "Entry not valid\n");
                    return 1;
                }
                else {
                    // code g
                    printf("Process name: %s\n", argv[2]);
                }
            }
            else {
                fprintf(stderr, "Invalid Arguments\n");
                usage();
                return 1;
            }
        }
        else {
            char *endptr;
            long pid = strtol(argv[1], &endptr, 10);
            if (*endptr != '\0' || pid <= 0) {
                fprintf(stderr, "Entry not valid\n");
                return 1;
            }
            else {
                ProcInfo info = get_proc_infos(pid);
                if (info.name[0] == '\0' ) {
                    return 1;
                }
                printf("PID infos:\n Name: %s\n State: %c\n PPID: %ld\n VmRSS: %lu\n VmSize: %lu\n Command Line: %s\n", info.name, info.state, info.ppid, info.vmrss, info.vmsize, info.cmdline);
            }
        }
    }
    else {
        fprintf(stderr, "Invalid Arguments\n");
        usage();
        return 1;
    }

return 0;
}
