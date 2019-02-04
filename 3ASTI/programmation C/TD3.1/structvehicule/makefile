
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=vehicule

all: $(EXEC)

vehicule: vehicule.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

vehicule.o: vehicule.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c vehicule.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
