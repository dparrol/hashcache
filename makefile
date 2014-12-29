CFLAGS=-Wall -Os
all: hitrate-trivial
hitrate-trivial: hitrate.o trivial.o
	$(CC) $^ -o $@ $(LDFLAGS)
