/* file name  : liste.h
 * authors    : Simon MORIN / JF Lalande
 * created    : dim 08 jan 2006 16:39:01 CET
 *
 * modifications:
 * - Renommage de quelques fonctions.
 *
 */
#ifndef __LISTE_H__
#define __LISTE_H__

#include "vehicule.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct LISTE_VEHICULE{
	vehicule *v;
	struct LISTE_VEHICULE *next;
  int size;
} liste_vehicule;


liste_vehicule * init_liste();

void add_vehicule(vehicule *v, liste_vehicule * l);

void add_vehicule_head(vehicule *v, liste_vehicule *l);

vehicule * remove_first_vehicule(liste_vehicule * l);

vehicule * get_first_vehicule(liste_vehicule * l);

vehicule *get_last_vehicule(liste_vehicule * l);

void destroy_list_and_vehicules(liste_vehicule * l);

int size(liste_vehicule * l);

vehicule* cherche_vehicule(char nom[20],liste_vehicule * l) ;
vehicule* enlever_vehicule(char nom[20],liste_vehicule * l) ;
void printlistvehicule(liste_vehicule *l);

#endif
