#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pile.h"
void saisie_vehicule(vehicule *p){
 printf("Entrew le nom modele : \n");
 scanf("%s",p->nom_modele);
 srand(time(NULL));
 p->puissance=rand()%(301);
 p->vitesse_max=rand()%(251);
}
pilevehicule *init_pilevehicule()
{
 pilevehicule * p ;
 p= (pilevehicule*) malloc(sizeof(pilevehicule));
 p->nbVehicule = 0;
 p->tpv = (vehicule **)malloc((p->nbVehicule)*sizeof(vehicule*));
 return p;
}
void empile_vehicule(pilevehicule *p,vehicule *v)
{
 (p->tpv)[p->nbVehicule] = v;
 (p->nbVehicule) ++;
}
void affiche_vehicule(vehicule *v)
{
 printf("modele de cette vehicule est:%s \n",v->nom_modele);
 printf("la puissance est %d \n",v->puissance);
 printf("la vitesse max est %f \n ", v->vitesse_max);
}
void affiche_pilevehicule(pilevehicule *p)
{
 printf("nb Vehicule: %d \n", p->nbVehicule);
 int i;
 for (i=0;i < p->nbVehicule;i++)
 {
  printf("\nNo:%d \n",i+1);
  affiche_vehicule((p->tpv)[i]);
 }
}
vehicule *depile_vehicule(pilevehicule *p)
{
 p->nbVehicule--;
 return (p->tpv[p->nbVehicule]);
}
void supprime_pile(pilevehicule *p)
{
 free(p);
}
