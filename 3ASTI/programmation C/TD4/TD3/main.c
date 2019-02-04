// ==========================================
// DINH THANH HAI 
// PROGRAMMATION C
#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"
#include "matrice.h"
#include "matrice_io.h"
#include "calcul.h"
#include "alloc.h"
int main ()
{struct matrice m1,m2,m;
 FILE* matrice;
 matrice=fopen("add_m1.txt","r");
 m1=read_matrice(matrice);
 fseek(matrice,0,SEEK_SET);
        printf("\n");
 	printf("Affichage d'une matrice m1 pour l'addition:\n");
 	affiche_matrice(m1);
 	fclose(matrice);
 	printf("\n");
	matrice=fopen("add_m2.txt","r");
 	m2=read_matrice(matrice);
	printf("Affichage d'une matrice m2 pour l'addition:\n");
	affiche_matrice(m2);
	fclose(matrice);
	printf("\n");
if((m1.nb_lignes == m2.nb_lignes)&&(m1.nb_colonnes == m2.nb_colonnes))
  {
        m=add_matrice(m1,m2);
 	printf("Resultat de l'ADDITION de la matrice m1 et m2:\n");
	affiche_matrice(m);
	matrice=fopen("add.txt","w");
	write_matrice(matrice, m);
	fclose(matrice);
	printf("\n");
 }
 else printf(" Deux ces matrices ne peuvent pas addtition \n");
 
	matrice=fopen("mult_m1.txt","r");
	m1=read_matrice(matrice);
	printf("Affichage d'une autre matrice m1 pour la multiplication:\n");
	affiche_matrice(m1);
	fclose(matrice);
	printf("\n");

	matrice=fopen("mult_m2.txt","r");
	m2=read_matrice(matrice);
	printf("Affichage d'une autre matrice m2 pour la multiplication:\n");
	affiche_matrice(m2);
	fclose(matrice);
	printf("\n");
if(m1.nb_colonnes == m2.nb_lignes)
  {
        m=multiply_matrice(m1,m2);
	printf("Resultat de la MULTIPLICATION de m1 et m2:\n");
	affiche_matrice(m);

	matrice=fopen("mult.txt","w");
	write_matrice(matrice, m);
	fclose(matrice);
	printf("\n");
 }
else 
 { printf(" Deux ces matrices ne peuvent pas multiply \n");}
        detruire_matrice(&m);
	detruire_matrice(&m1);
	detruire_matrice(&m2);
	return 0;
}

