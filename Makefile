##
# Procsnap
#
# @file
# @version 1.0.1

CC = gcc
CFLAGS = -Wall -Wextra

procsnap: main.c proc.c print_json.c diff.c search.c
	$(CC) $(CFLAGS) -o procsnap main.c proc.c print_json.c diff.c search.c

clean:
	rm -f procsnap

install: procsnap
	install -m 755 procsnap /usr/local/bin/procsnap

uninstall:
	rm -f /usr/local/bin/procsnap

# end
