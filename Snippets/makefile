CC= gcc
CFLAGS= -Wall -Werror -std=c99
LIBS= 
BINARIES= allocation cmdlineparameter string 2dmatrix

all: allocation cmdlineparameter string 2dmatrix

allocation: allocation.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

cmdlineparameter: cmdlineparameter.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

string: string.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

2dmatrix: 2dmatrix.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(BINARIES) *.o