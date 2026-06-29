##
# Procsnap
#
# @file
# @version 0.1

CC = gcc
CFLAGS = -Wall -Wextra

procsnap: main.c proc.c
	$(CC) $(CFLAGS) -o procsnap main.c proc.c print_json.c

clean:
	rm -f procsnap

# end
