//
//  root.c
//  DINH THANH HAI
//  20/09/2017 devoir programmation C
//
#include<stdio.h>
#define ZERO 1e-100
#define EPSILON 1e-10
#include<math.h>
#include "root.h"
//Exercice 3
int proche(double a, double b){
 return fabs(a)<ZERO ? fabs(b)<ZERO:fabs(a-b)<EPSILON*fabs(a);
}
double moyenne(double t[],int n)
//Calcule la moyenne des n premiers element du tableau t
{
 int i;
 double a=0.0;
 for (i=0;i<n;i++)
     a =a+t[i];
 return a/i;
}
double moyenne_positif(double t[])
//Calcule la moyenne des element du tableau t jusqu'a rencontrer un element negatif et -1.0 si le premier element est deja negatif
{
 int i;
 double a=0.0;
 for(i=0;t[i]>=0;i++)
   a=a+t[i];
 if (a==0)
	return -1;
 else
	return a;
}
double test_moyenne(){
 double v[]={1.0,2.0,3.0,4.0,5.0,6.0,-1.0};
 double d,attendu;
 attendu=1;
 //test moyenne
 if(!proche((d=moyenne(v,1)),attendu)){
  printf("Pb moyenne.Attendu:%f Obtenu: %f \n",attendu,d);
 }
 attendu=2.0;
 if(!proche((d=moyenne(v,3)),attendu)){
  printf("Pb moyenne.Attendu:%f Obtenu: %f \n",attendu,d);
 }
 attendu=3.5;
 if(!proche((d=moyenne(v,3)),attendu)){
  printf("Pb moyenne.Attendu:%f Obtenu: %f \n",attendu,d);
 }
//test moyenne positifs
 attendu=3.5;
 if(!proche((d=moyenne_positif(v)),attendu)){
  printf("Pb moyenne.Attendu:%f Obtenu: %f \n",attendu,d);
 }
 attendu=5.0;
 if(!proche((d=moyenne_positif(v+3)),attendu)){
  printf("Pb moyenne.Attendu:%f Obtenu: %f \n",attendu,d);
 }
 attendu=-1.0;
 if(!proche((d=moyenne_positif(v+6)),-1.0)){
  printf("Pb moyenne_positif.Attendu: %f Obtenu: %f\n",attendu,d);
 }
}
//Exercice 4
int chaine_longueur_rec(char *s)
//calculer recursivement la longueur d'une chain de caracteres terminee par '\o'
{
 if(*s==0)
  return 0;
 else return 1+chaine_longueur_rec(s+1);
}	
int chaine_debute_par(char *s1, char *s2)
//retourner un entier non nul si s1 commence par s2 et 0 sinon
{
 if (*(s2+0)==0)
   return 1;
 else
 if(*s2!=*s1)
    return 0;
 else return chaine_debute_par(s1+1,s2+1);
 }
//Exercice 5
int chaine_indice(char *s1,char *s2)
//retourner la position de s2 dans s1
{
 int i;
 for (i=0; s1[i]!='\0';++i)
   if(chaine_debute_par(s1+i,s2))
	return i;
 return -1;
}
//Exercice 6
void elever_au_cude(int* p)
{
 int x;
 x=*p;
 *p=x*x*x;
}

 
 
 
