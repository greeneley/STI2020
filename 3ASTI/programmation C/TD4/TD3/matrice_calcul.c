#include <stdlib.h>
#include <stdio.h>
#include "calcul.h"
#include "alloc.h"
struct matrice add_matrice(struct matrice m1,struct matrice m2){
 struct matrice matrix;
 int i,j;
 matrix=allouer_matrice(m1.nb_lignes,m1.nb_colonnes);
 for (i=0;i<m1.nb_lignes;i++)
  {
    for(j=0;j<m1.nb_colonnes;j++)
     {
      matrix.m[i][j]=m1.m[i][j]+m2.m[i][j];
     }
  }
 return matrix;
}
struct matrice multiply_matrice(struct matrice m1, struct matrice m2){
  struct matrice matrix;
  int i,j,k,c;
  matrix=allouer_matrice(m1.nb_lignes,m2.nb_colonnes);
  for (i=0;i<m1.nb_lignes;i++)
   {
     for(j=0;j<m2.nb_colonnes;j++)
    {
      c=0;
      for(k=0;k<m1.nb_colonnes;k++)
     {
       c=c+m1.m[i][k]*m2.m[k][j];
     }
    matrix.m[i][j]=c;
    }
   }
  return matrix;
}
