$CC = gcc
$CFLAGS = -Wall -c99

all: rps

rps: main.o
	$(CC) $(CFLAGS) main.o -o rps
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
