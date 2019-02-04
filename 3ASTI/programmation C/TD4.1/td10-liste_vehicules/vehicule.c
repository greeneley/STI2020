/* file name  : vehicule.c
 * authors    : Simon MORIN / JF Lalande
 * created    : dim 08 jan 2006 16:38:35 CET
 *
 * modifications: neant.
 *
 */
#include "vehicule.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void printVehicule(vehicule *v){
	printf("=========================\n");
	printf("Modele : %s\n",v->nom_modele);
	printf("Puissance : %i\n",v->puissance);
	printf("Vitesse maxi : %f\n",v->vitesse_max);
	printf("=========================\n");
}

vehicule *newVehicule(char *m,int p,float v){
	vehicule *temp = (vehicule *) malloc(sizeof(vehicule));
	strcpy(temp->nom_modele,m);
	temp->puissance = p;
	temp->vitesse_max = v;
	return temp;
}

void destroy_vehicule(vehicule *v){
	free(v);
}
