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
#include "diff.h"
#include "proc.h"
#include <stdio.h>
#include <stdlib.h>

void print_diff (ProcInfo before, ProcInfo after) {
    // VmRSS snapshots comparison
    if (before.vmrss != after.vmrss) {
        printf("vmrss: %lu -> %lu\n", before.vmrss, after.vmrss);
    }
    // VmSize snapshots comparison
    if (before.vmsize != after.vmsize) {
        printf("vmsize: %lu -> %lu\n", before.vmsize, after.vmsize);
    }
    // State snapshots comparison
    if (before.state != after.state) {
        printf("State: %c -> %c\n", before.state, after.state);
    }
}
