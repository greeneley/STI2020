#ifndef _MATRICE_H
#define _MATRICE_H
struct matrice read_matrice(FILE *);
void write_matrice(FILE*,struct matrice );
struct matrice add_matrice(struct matrice, struct matrice);
struct matrice multiply_matrice(struct matrice , struct matrice);
struct matrice allouer_matrice(int, int);
void detruire_matrice(struct matrice *);
void affiche_matrice(struct matrice);
 
#endif
