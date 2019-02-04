#define TMAX 10
#ifndef _PILE_H
#define _PILE_H
typedef struct pile{
 int tab[TMAX]; /* le tableau contient les donnees */
 int curseur; /* le curseur contiendra indice du tableau auquel le prochain empilement pourra se faire */
}pile;
pile *cree_pile();
extern int retire_pile(pile *p);
extern void ajoute_pile(pile *p, int n);
extern void libere_pile(pile *p);
extern int sommet_pile(pile *p);
extern int pile_vide(pile *p);
extern int pile_pleine(pile *p);
extern void affiche_pile(pile *p);
#endif 

