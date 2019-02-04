#include <stdlib.h>
#include <stdio.h>
#include "alloc.h"
struct matrice allouer_matrice( int nb_lignes, int nb_colonnes){
    struct matrice matrix;
    int i;
    matrix.m = malloc(sizeof(int *) * nb_lignes);
    for (i=0 ; i< nb_lignes ; i++)
        matrix.m[i] = malloc(sizeof(int) * nb_colonnes);

    matrix.nb_colonnes = nb_colonnes;
    matrix.nb_lignes = nb_lignes;

    return matrix;
}
void detruire_matrice(struct matrice *m) {
    int i;
    for (i=0 ; i < m->nb_lignes ; i++)
        free(m->m[i]);
    free(m->m);
    m->m = NULL;
}
