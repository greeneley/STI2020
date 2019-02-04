#ifndef _ALLOC_H
#define _ALLOC_H

struct matrice read_matrice(FILE *);
void write_matrice(FILE *, struct matrice);
void affiche_matrice(struct matrice);
#endif
