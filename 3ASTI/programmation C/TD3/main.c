#include <stdio.h>
#include <stdlib.h>
#define TMAX 10
#include "pile.h"
int main(){
 /*
 Notew qu'il n'y q pqs besoin de connaitre la structure interne de la pile.
 le meme progamme pourra etre utilise avec une autre implementation.
 */
 int c,n;
 pile *p= cree_pile();
 if (p == NULL){
 /*
 on ne devrait pas passer par la, mais boone habitude
 */
 fprintf(stderr, " Creation de pile impossible. Contacter l'administrateur \n ");
 getchar();
 return 1;
 }
 do {
  /* exemple de menu */
 printf("\n");
 printf("1. Empiler \n");
 printf("2. Depiler \n");
 printf("3. Sommet \n");
 printf("4. Affichage \n");
 printf("\n");
 printf("0. Quitter \n");
 printf(" Votre Choix: \n");
 scanf("%d", &c);
 switch (c) {
 case 1:  if (pile_pleine(p)){
             printf("Pile pleine. Empilement impossible");
             break; 
          }
          printf("Empilement. Entrez le nombre a empiler: ");
          scanf("%d",&n);
          ajoute_pile(p,n);
          break;
 case 2: if (pile_vide(p)){
          printf("Pile Vide. Depilement impossible");
          break;
         }
         printf("Depilement de %d \n", retire_pile(p));
         break;
 case 3: if (pile_vide(p)){
          printf("pile vide. Pas de sommet");
          break;
         }
         printf("Sommet: %d \n", sommet_pile(p));
         break;
 case 4: printf ("Affichage: ");
         affiche_pile(p);
         printf("\n");
         break;
  }
 }while (c !=0 );
 /* bonne habitude de toujours liberer ce que l'on a alloue */
 libere_pile(p);
 getchar();
 return 0; 
}
