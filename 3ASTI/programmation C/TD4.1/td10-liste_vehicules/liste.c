/* file name  : liste.c
 * authors    : Simon MORIN / JF Lalande
 * created    : dim 08 jan 2006 16:36:13 CET
 * copyright  : ENSIB
 *
 * modifications:
 * - Le premier élément est désormais un élément "de gestion". Il ne contient
 *   pas de vehicule. Lorsque la liste est vide, le premier element contient:
 *   l->v = NULL;
 *   l->next = NULL;
 * - Par consequent, le "vrai" premier element est juste apres.
 * - Quelques fonctions ont ete renommees.
 *
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "liste.h"

liste_vehicule * init_liste()
{
	liste_vehicule *temp = (liste_vehicule *) malloc(sizeof(liste_vehicule));
	temp->v = NULL;
	temp->next = NULL;
  temp->size = 0;
	return temp;
}

void add_vehicule(vehicule *v,liste_vehicule * l)
{

  l->size++;

	if (l->next != NULL)
  {
		add_vehicule(v,l->next);
	}
	else
  {
		l->next = (liste_vehicule *) malloc(sizeof(liste_vehicule));
		l->next->v = v;
		l->next->next = NULL;
	}
}
void printlistvehicule(liste_vehicule *l){
  if((l->next)!=NULL) 
    {
      printVehicule(l->next->v);
        printlistvehicule(l->next);
    }
  else return NULL; 
}

vehicule* cherche_vehicule(char nom[20],liste_vehicule * l) {
  if(l->next!=NULL)
  {
    if(strcmp(nom,l->next->v->nom_modele)==0) /*chu y l la mot con tro dung de duyet, l->next tuc la no tro toi 1 danh sach tiep theo check xem ok ko*/
        {
          printVehicule(l->next->v);
          return 0;
        }
    else
      cherche_vehicule(nom,l->next);
  }
  else return NULL;
}

vehicule* enlever_vehicule(char nom[20],liste_vehicule * l) {
 if(l->next!=NULL)
 {
  if(strcmp(nom,l->next->v->nom_modele)==0)
  {
    liste_vehicule *Q=(liste_vehicule*)malloc(sizeof(liste_vehicule));
    Q->v=l->next->v;
    Q->next=l->next->next;
    l->next=Q->next;
    free(Q);
  }
  else enlever_vehicule(nom,l->next);
 }
 else return NULL;
}


void add_vehicule_head(vehicule *v, liste_vehicule *l) {
  liste_vehicule *nouv = (liste_vehicule *) malloc(sizeof(liste_vehicule));
  nouv->v = v;
  nouv->next = l->next;
  l->next = nouv;
  l->size++;
}

vehicule * remove_first_vehicule(liste_vehicule * l)
{
	vehicule *v;
  v = l->next->v;
	l->next = l->next->next;
  l->size--;
	return v;
}

vehicule * get_first_vehicule(liste_vehicule * l)
{
  if (l->next != NULL)
  {
    return l->next->v;
  }
  else
  {
    return NULL;
  }
}

vehicule *get_last_vehicule(liste_vehicule * l)
{
  if (l->next != NULL)
  {
    return get_last_vehicule(l->next);
  }
  else
  {
    return l->v;
  }
}

void destroy_list_and_vehicules(liste_vehicule * l)
{
	if(l->next != NULL){
		destroy_list_and_vehicules(l->next);
	}

	if(l->v != NULL) {
           destroy_vehicule(l->v);
        }
        else {
           l->size = 0;
        }
	free(l);

}

int size(liste_vehicule * l)
{
  return l->size;
}
