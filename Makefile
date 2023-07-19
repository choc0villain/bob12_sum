CC = gcc
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

all: test3

test3: test3.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

clean:
	rm -f test3
