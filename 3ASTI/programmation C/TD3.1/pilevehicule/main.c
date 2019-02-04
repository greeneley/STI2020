#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pile.h"
int main(void)
{
 vehicule *v1, *v2, *v3;
 pilevehicule *pv;
 v1 =(vehicule *)malloc(sizeof(vehicule));
 v2 =(vehicule *)malloc(sizeof(vehicule));
 saisie_vehicule(v1);
 saisie_vehicule(v2);
 printf("\n\ncréationde la pile");
 pv=init_pilevehicule();
 empile_vehicule(pv, v1);
 empile_vehicule(pv, v2);
 printf("\n\nAffichage de la pile");
 affiche_pilevehicule(pv);
 printf("\n\nSuppression d'un element de la pile\n\n");
 v3=depile_vehicule(pv);
 affiche_vehicule(v2);
 printf("\n\nPile après suppression\n\n");
 affiche_pilevehicule(pv);
 supprime_pile(pv);
 affiche_pilevehicule(pv);
 return 0;
}
