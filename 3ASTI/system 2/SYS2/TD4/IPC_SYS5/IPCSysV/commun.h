#ifndef COMMUN_H
#define COMMUN_H

#define NOM "commun.h"
#define PROJ_FTOK_SEM 'a'
#define PROJ_FTOK_MEM '0'

#define TAILLE 20
#define N 5

ushort init_sem[]={1,N}; // tb entier u, entre les chiffre 1 et N, passer 1 processus a la fois -> valeur itilisation de compteur.
 struct sembuf demande_ecriture[]={{0,-1,SEM_UNDO},{1,-N,SEM_UNDO}}; // numero de semanphore, operation sur semanphore, options pout operation, undo quand le processus termine.
struct sembuf stoppe_ecriture[]={{0,+1,SEM_UNDO},{1,N,SEM_UNDO}}; //0 =>  bloquer tout le monde d'ecrire dedans

struct sembuf demande_lecture={1,-1,SEM_UNDO};
struct sembuf stoppe_lecture={1,+1,SEM_UNDO};
#endif


