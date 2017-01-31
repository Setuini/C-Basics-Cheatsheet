CC= gcc
CFLAGS= -Wall -Werror
LIBS=
SOURCE= $(wildcard *.c) 
BINARIES= a1 a2 a3 a4

all: a1 a2 a3 a4

a1: a1.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

a2: a2.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

a3: a3.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

a4: a4.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(BINARIES) *.o