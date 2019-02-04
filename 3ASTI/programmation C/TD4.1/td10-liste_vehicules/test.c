#include <stdlib.h>
#include <string.h>
#include <stdio.h>
typedef struct {
	char nom_modele[20];
	int puissance;
	float vitesse_max;
} vehicule;
typedef struct LISTE_VEHICULE{
	vehicule *v;
	struct LISTE_VEHICULE *next;
  int size;
} liste_vehicule;


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

void printVehicule(vehicule *v){
	printf("=========================\n");
	printf("Modele : %s\n",v->nom_modele);
	printf("Puissance : %i\n",v->puissance);
	printf("Vitesse maxi : %f\n",v->vitesse_max);
	printf("=========================\n");
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
    if(strcmp(nom,l->next->v->nom_modele)==0)
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

liste_vehicule *renverser_liste(liste_vehicule *l) {
 liste_vehicule *parent=(liste_vehicule*)malloc(sizeof(liste_vehicule));
 liste_vehicule *current=(liste_vehicule*)malloc(sizeof(liste_vehicule));
 parent=l;
 current=l->next;
 l->next=current->next;
 parent->next=NULL;
 current->next=parent;
 while(l->next!=NULL)
 {
 	parent=current;
 	current=l;
 	l->next=l->next->next;
 	current->next=parent;
 }l->next=current;
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
int size(liste_vehicule * l)
{
  return l->size;
}

int main()
{


	vehicule *v1, *v2, *v3, *v4;
	liste_vehicule *l;
	liste_vehicule *renverser_liste;
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
	/*printf("danh sach sau khi enlever\n");
	enlever_vehicule(nom,l);
	printlistvehicule(l);
	printf("Taille de la liste : %i\n", size(l));*/
	renverser=renverser_liste(l);
	printf("Danh sach sau khi dao nguoc\n");
	printlistvehicule(renverser);

}
