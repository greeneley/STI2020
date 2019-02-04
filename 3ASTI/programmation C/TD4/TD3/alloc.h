#ifndef __ALLOC_H__
#define __ALLOC_H__
struct matrice{
 int **m;
 int nb_lignes;
 int nb_colonnes;
};
struct matrice allouer_matrice(int, int);
void detruire_matrice(struct matrice *);
#endif

