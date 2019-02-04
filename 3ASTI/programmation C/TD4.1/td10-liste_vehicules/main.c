/* file name  : main.c
 * authors    : Simon MORIN / JF Lalande
 * created    : dim 08 jan 2006 16:38:14 CET
 *
 * modifications: Programme de test de la liste.
 *
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vehicule.h"
#include "liste.h"

void test_liste();
void test_avance_liste();

int main()
{


	vehicule *v1, *v2, *v3, *v4;
	liste_vehicule *l;
	char nom[]="Lada 1962";

	
	v1 = newVehicule("Peugeot 106",1,200);
	v2 = newVehicule("Renault Megane",2,240);
	v3 = newVehicule("Lada 1962",3,32);
	v4 = newVehicule("Volkswagen Polo",4,180);
	
	l = init_liste();
	printf("Taille de la liste : %i\n", size(l));
	add_vehicule(v1,l);
	add_vehicule(v2,l);
	add_vehicule(v3,l);
	add_vehicule(v4,l);
	printf("Taille de la liste : %i\n", size(l));
	printf("\n");
	
	printf("=====================\n");
	cherche_vehicule(nom,l);
	printf("Danh sach truoc khi enlever\n");
	printlistvehicule(l);
	printf("danh sach sau khi enlever\n");
	enlever_vehicule(nom,l);
	printlistvehicule(l);

	
	/*printf("Affichage du premier vehicule de la liste : \n");
	printVehicule(get_first_vehicule(l));
	printf("\n");
	printf("Affichage du dernier vehicule de la liste : \n");
	printVehicule(get_last_vehicule(l));
	printf("\n");
	printf("On enleve le premier vehicule.\n");
  	old = remove_first_vehicule(l);
	printf("Affichage du premier vehicule de la liste : \n");
	printVehicule(get_first_vehicule(l));
	printf("\n");

	printf("Taille de la liste : %i\n", size(l));
	
	destroy_list_and_vehicules(l);*/
	return 0;
}

