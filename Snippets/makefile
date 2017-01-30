CC= gcc
CFLAGS= -Wall -Werror -std=c99
LIBS= 
BINARIES= allocation cmdlineparameter string

all: allocation cmdlineparameter string

allocation: allocation.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

cmdlineparameter: cmdlineparameter.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

string: string.c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -rf $(BINARIES) *.o