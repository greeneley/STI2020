#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vehicule.h"
void init_vehicule(vehicule **v1){
 *v1=(vehicule *)malloc(sizeof(vehicule));
 printf("entrez le nom modele: \n");
 scanf("%s",(*v1)->nom_modele);
 srand(time(NULL));
 (*v1)->puissance=rand()%(301);
 (*v1)->vitesse_max=rand()%(251);
}
void affichage_vehicule(vehicule *v){
 printf("modele de cette vehicule est:%s \n",v->nom_modele);
 printf("la puissance est %d \n",v->puissance);
 printf("la vitesse max est %f \n ", v->vitesse_max);
}
void destroy_vehicule(vehicule *v){
 free(v);
}
