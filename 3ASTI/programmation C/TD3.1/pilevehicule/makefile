
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=pile

all: $(EXEC)

pile: pile.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

pile.o: pile.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c pile.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
