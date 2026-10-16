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
#ifndef DIFF_H_
#define DIFF_H_

#include "proc.h"

void print_diff (ProcInfo before, ProcInfo after);

#endif // DIFF_H_
