##
# Procsnap
#
# @file
# @version 1.0.0

CC = gcc
CFLAGS = -Wall -Wextra

procsnap: main.c proc.c print_json.c diff.c search.c
	$(CC) $(CFLAGS) -o procsnap main.c proc.c print_json.c diff.c search.c

clean:
	rm -f procsnap

# end
