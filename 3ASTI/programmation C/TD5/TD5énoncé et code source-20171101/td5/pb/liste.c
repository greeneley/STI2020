#include "liste.h"
#include <stdio.h>
#include <stdlib.h>
Liste * init(int i) {

  Liste *liste = (Liste *)malloc(sizeof(Liste));
  liste->item=i;
  liste->next=NULL;
  return liste;
}

Liste * build_Liste_123() {
   Liste *head = init(1);
   Liste *second=init(2);
   Liste *third=init(3);
   head->next=second;
   second->next=third;
   return head;
}

void affiche_Liste(Liste *liste) {
  int i=0;
  Liste * tmp =liste;
  printf("[");
  for (tmp=liste; tmp!=NULL; tmp=tmp->next) 
     printf("%d ",tmp->item);
  printf("]\n");
}

Liste * insere_Tete_Liste_1(Liste *liste, int item) {

    Liste * noeud = init(item);
    Liste * head = liste;
    noeud->next=liste;
    head=noeud;
    return head;

}   
   
void inserer_Tete_Liste_2(Liste **liste, int item) {

    Liste * noeud = init(item);
    noeud->next=*liste;
    *liste=noeud;
}

void inverser_Liste(Liste **head) {
   // votre code
    
}

void inserer_Nieme(Liste **head, int position, int item) {
 // votre code
}


   
