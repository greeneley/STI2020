#include "liste.h"
#include <stdlib.h>
int main(void) {
  Liste * head = (Liste *)malloc(sizeof(Liste));
  head = build_Liste_123();
  affiche_Liste(head);//[1 2 3 ]
  inserer_Tete_Liste_2(&head,-1);//push -1
  inserer_Tete_Liste_2(&(head->next),0); // push 0 en seconde position!!
  affiche_Liste(head);//[-1 0 1 2 3 ]
  inverser_Liste(&head);
  affiche_Liste(head); // [3 2 1 0 -1 ]
  return 0;
}
  

