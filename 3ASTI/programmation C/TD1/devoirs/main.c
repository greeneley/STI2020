//
//  main.c
//  DINH THANH HAI
//  20/09/2017 devoir programmation C
//
#include <stdlib.h>
#include <stdio.h>
#include "root.h"
#define ZERO 1e-100
#define EPSILON 1e-10
#include<math.h>
int main(void)
{
		
	test_moyenne();
  	char s1[100],s2[50];
	printf("Entrez la chaine s1 (sans d'espace) ");
	scanf("%s",&s1);
	printf("Le longeur de la chaine '%s' est %d\n",s1,chaine_longueur_rec(s1));
	printf("Entrez la chaine s2 (sans d'espace) ");
	scanf("%s",&s2);
	if(chaine_debute_par(s1,s2) == 1)
		printf("s1 = '%s' commence par s2 = '%s'\n",s1,s2);
	else 	printf("s1 = '%s' ne commence pas par s2 = '%s'\n",s1,s2);
	printf("La position de s2 dans s1 est '%d'\n",chaine_indice(s1,s2));
	int n=5;
	elever_au_cude(&n);
	printf("%d\n",n);
}
	
