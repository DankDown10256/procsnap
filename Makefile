##
# Procsnap
#
# @file
# @version 1.0.9

VERSION := $(shell grep -m1 '@version' Makefile | sed 's/.*@version *//')

CC = gcc
CFLAGS = -Wall -Wextra -DPROCSNAP_VERSION=\"$(VERSION)\"

procsnap: main.c proc.c print_json.c diff.c search.c
	$(CC) $(CFLAGS) -o procsnap main.c proc.c print_json.c diff.c search.c

clean:
	rm -f procsnap

install: procsnap
	install -m 755 procsnap /usr/local/bin/procsnap

uninstall:
	rm -f /usr/local/bin/procsnap
