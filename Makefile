##
# Procsnap
#
# @file
# @version 0.3

CC = gcc
CFLAGS = -Wall -Wextra

procsnap: main.c proc.c print_json.c diff.c
	$(CC) $(CFLAGS) -o procsnap main.c proc.c print_json.c diff.c

clean:
	rm -f procsnap

# end
