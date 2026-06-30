/*
 * procsnap - minimalist C CLI tool for reading /proc process info
 * Copyright (C) 2026 Lucas Poupeau <lucasp.linux@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <https://www.gnu.org/licenses/>.
 */
#include "proc.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

ProcInfo get_proc_infos(long pid) {
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
  snprintf(info.name, sizeof(info.name), "%.*s", (int)(end - start - 1),
           start + 1);
  sscanf(end + 2, "%c %ld", &info.state, &info.ppid);
  close(fd);

  char path_status[64];
  snprintf(path_status, sizeof(path_status), "/proc/%ld/status", pid);
  int fd_status = open(path_status, O_RDONLY);
  if (fd_status == -1) {
    fprintf(stderr, "PID Not found\n");
    return info;
  }

  char buffer[4096];
  ssize_t m = read(fd_status, buffer, sizeof(buffer) - 1);

  if (m == -1) {
    fprintf(stderr, "Error in reading\n");
    return info;
  }
  buffer[m] = '\0';
  char *line = strstr(buffer, "VmRSS:");
  if (line) {
    sscanf(line, "VmRSS: %lu", &info.vmrss);
  }
  char *line_vmsize = strstr(buffer, "VmSize:");
  if (line_vmsize) {
    sscanf(line_vmsize, "VmSize: %lu", &info.vmsize);
  }
  close(fd_status);

  char path_cmdline[64];
  snprintf(path_cmdline, sizeof(path_cmdline), "/proc/%ld/cmdline", pid);
  int fd_cmdline = open(path_cmdline, O_RDONLY);
  if (fd_cmdline == -1) {
    fprintf(stderr, "PID Not found\n");
    return info;
  }
  char buffer_cmdline[4096];
  ssize_t o = read(fd_cmdline, buffer_cmdline, sizeof(buffer_cmdline) - 1);
  buffer_cmdline[o] = '\0';
  for (int i = 0; i < o - 1; i++) {
    if (buffer_cmdline[i] == '\0') {
      buffer_cmdline[i] = ' ';
    }
  }
  snprintf(info.cmdline, sizeof(info.cmdline), "%s", buffer_cmdline);
  close(fd_cmdline);
  return info;
}
