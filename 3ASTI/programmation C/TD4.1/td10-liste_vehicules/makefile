CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=matrice

all: $(EXEC)
vehicule.o: vehicule.c 
	$(CC) -o vehicule.o -c vehicule.c $(CFLAGS)
liste.o: liste.c 
	$(CC) -o liste.o -c liste.c $(CFLAGS)
main.o: vehicule.c vehicule.h liste.h liste.c main.c
	$(CC) -o main.o -c main.c $(CFLAGS)
vehicule: vehicule.o liste.o main.o
	$(CC) -o vehicule vehicule.o liste.o main.o $(LDFLAGS)
clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)