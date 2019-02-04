CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=matrice

all: $(EXEC)
alloc.o: alloc.c 
	$(CC) -o alloc.o -c alloc.c $(CFLAGS)
matrice_io.o: matrice_io.c 
	$(CC) -o matrice_io.o -c matrice_io.c $(CFLAGS)
calcul.o: matrice_calcul.c 
	$(CC) -o calcul.o -c matrice_calcul.c $(CFLAGS)
main.o: alloc.c alloc.h matrice.h main.c
	$(CC) -o main.o -c main.c $(CFLAGS)
matrice: alloc.o calcul.o matrice_io.o main.o
	$(CC) -o matrice alloc.o calcul.o matrice_io.o main.o $(LDFLAGS)
clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
