#ifndef PROC_H_
#define PROC_H_

typedef struct {
    char  name[256];
    char  state;
    long  ppid;
    unsigned long vmrss;
    unsigned long vmsize;
    char cmdline[4096];
} ProcInfo;

ProcInfo get_proc_infos(long pid);

#endif // PROC_H_
