CFLAGS=-std=c99 -Wall
CC=gcc

binary_search: main.c binary_search.o
	$(CC) $(CFLAGS) main.c binary_search.o -o binary_search

binary_search.o: binary_search.h binary_search.c
	$(CC) $(CFLAGS) -c binary_search.c

clean:
	rm -f binary_search *.o
