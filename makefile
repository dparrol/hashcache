CFLAGS=-Wall -Os
all: hitrate-trivial
hitrate-trivial: hitrate.o trivial.o hash.o
	$(CC) $^ -o $@ $(LDFLAGS)
