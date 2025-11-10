CFLAGS=-O2 -Wall -std=c23 -m32
LDFLAGS=-lbu

.PHONY: all clean

all: clean bin/chrismail bin/client

bin:
	mkdir -p bin

bin/chrismail: bin/chrismail.o | bin
	cc $(CFLAGS) $^ -o $@ $(LDFLAGS)

bin/chrismail.o: chrismail.c chrismail.h | bin
	cc $(CFLAGS) -c $< -o $@

bin/client: bin/client.o | bin
	cc $(CFLAGS) $^ -o $@ $(LDFLAGS)

bin/client.o: client.c chrismail.h | bin
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f ./bin/*.o ./bin/chrismail ./bin/client