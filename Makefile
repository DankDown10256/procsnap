##
# Procsnap
#
# @file
# @version 1.2.0

VERSION := $(shell grep -m1 '@version' Makefile | sed 's/.*@version *//')

CC = gcc
CFLAGS = -Wall -Wextra -DPROCSNAP_VERSION=\"$(VERSION)\"
SRC = main.c src/proc.c src/print_json.c src/diff.c src/search.c

procsnap: $(SRC)
	$(CC) $(CFLAGS) -o procsnap $(SRC)

clean:
	rm -f procsnap

install: procsnap
	install -m 755 procsnap /usr/local/bin/procsnap

uninstall:
	rm -f /usr/local/bin/procsnap
