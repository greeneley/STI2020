/* file name  : vehicule 
 * authors    : Simon MORIN / JF Lalande
 * created    : dim 08 jan 2006 16:39:20 CET
 *
 * modifications:
 *
 */
#ifndef __VEHICULE_H__
#define __VEHICULE_H__

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
	char nom_modele[20];
	int puissance;
	float vitesse_max;
} vehicule;

void printVehicule(vehicule *v);

vehicule *newVehicule(char *m,int p,float v);

void destroy_vehicule(vehicule *v);

#endif
