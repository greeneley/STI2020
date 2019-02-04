#ifndef _LISTE_H
#define _LISTE_H

typedef struct liste {
  int item;
  struct liste * next;
} Liste;

Liste * build_Liste_123();
Liste * init(int i);
void affiche_Liste(Liste *liste);
Liste * inserer_Tete_Liste_1(Liste *head,int item);
void inserer_Tete_Liste_2(Liste **head, int item);
void inverser_Liste(Liste **head);// A implémenter
void inserer_Nieme(Liste **head, int position, int item);// A implémenter
#endif

