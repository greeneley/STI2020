#include <stdlib.h>
#include <stdio.h>
#include "matrice_io.h"
#include "alloc.h"
struct matrice read_matrice(FILE *f){
 struct matrice matrix;
 int lignes, colonnes;
 int i,j;
 fscanf(f,"%d %d \n",&lignes,&colonnes);
 matrix=allouer_matrice(lignes,colonnes);
 for(i=0;i<=matrix.nb_lignes;i++)
  {
   for (j=0;j<matrix.nb_colonnes;j++)
    {fscanf(f, "%d",&matrix.m[i][j]);}
  fscanf(f,"\n");
 }
 return matrix;
}
void write_matrice(FILE *f, struct matrice m){
 int i,j;
 for (i=0;i<m.nb_lignes;i++)
  {
    for(j=0;j<m.nb_colonnes;j++)
     {
       fprintf(f,"%d ",m.m[i][j]);
     }
   fprintf(f,"\n");
  }     
} 
void affiche_matrice(struct matrice m){
 int i,k;
 for (i=0;i< m.nb_lignes; i++){
  for (k=0; k< m.nb_colonnes;k++){
     printf(" %d",m.m[i][k]);
    }
  printf("\n");
   }
}
