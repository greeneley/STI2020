#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#include "commun.h"

int     shmid,
        semid;

static void usage ()
{
printf("Exemple d'application et des semaphores et memoire partagee \n");
printf(" ---> lecteurs/Ecrivains \n");
printf(" Ecrivain \n\n");
exit (-1);
}
static void erreur(char *msg)
{
fprintf (stderr, "Erreur  Ecrivain :%s : %d \n",msg,errno);
exit(-1);
}
void ecriture(char *source, char *destination, int nb_octets)
{
int i;
semop(semid, demande_ecriture,2); // effectue des operations sur les membre du jeu de semanphore identifier par semid 2: nombre d'operation a operer
// 1e semid qu'on cherche
// demande ecriture : prendre le 1e compteur, decrement au 1, prend le 2d compteur, decrement au 5
// elle est accessible par le processus
printf(" Debut d'ecriture dans la zone partagee de %d octets par le processus %d\n"
        ,nb_octets,getpid()); // nb_octets de getip
for(i=0; i<nb_octets;i++)
     destination[i]=source[i]; // buffer -> memoire partagee
     sleep(1);
printf(" Fin d'ecriture dans la zone partage par le processus  %d\n",getpid()); 
semop(semid,stoppe_ecriture,2);// refaire semop.il peut pas etre bloquant, a partir de moment semop, les autres ne peux pas manipuler. il est oblige de passer
}

void init_ecrivain()
{
   int clef_mem,
        clef_sem; // on vautiliser 2 cle: semanphore et shared memory
    if ((clef_mem= ftok(NOM,PROJ_FTOK_MEM))==-1) // convertir un pathname and l'identifier d'un projet a Sys5 Cle (generer la cle)
    erreur(" Erreur lors du ftok memoire partage");
    if  ((clef_sem= ftok(NOM,PROJ_FTOK_SEM))==-1)
     erreur(" Erreur lors du ftok semaphore");

     if ((shmid = shmget(clef_mem,TAILLE,IPC_CREAT|IPC_EXCL|0777))==-1) // creation ou rechercher d'une memoire partage, 2e argu: combien memoire,IPC_CREATE : cree fichier manier exculsive de drois 0644
     erreur(" Erreur lors du shmget");
     if ((semid = semget(clef_sem,2,IPC_CREAT|IPC_EXCL|0666))==-1) // creer un semanphore identification, argument 2(2): nombre de compteur de semanphore, je veux ensemble de 2 semanphore
     erreur(" Erreur lors du semget");
     if(semctl(semid,2,SETALL,init_sem)==-1)
     erreur("erreur lors du semctl");
     }
/*semctl()  performs  the  control operation specified by cmd on the Sys‐
       tem V semaphore set identified by semid, or on the semnum-th  semaphore
       of that set.  (The semaphores in a set are numbered starting at 0.)
Set  semval  for  all  semaphores of the set using arg.array,
                 updating also the sem_ctime member of the semid_ds  structure
                 associated  with  the  set. 

2 a regler, on va regler tout avec le tableau init_sem
l'ensemble de numero 1 - 5
*/
void ecrivain()
{
char buf[20];
char *addr;
int     i,
        j;
 if ((addr = shmat(shmid,NULL,0))==(char *)-1) //il  attache un zone memoire a un processus 1e: le numero du zone memoire, 2e l'adresse , cela renvoie l'adresse virtuel du processus a la quel le 20s octets sont attache
 erreur ("Erreur lors du shmat");
 for (j=0;j<4;j++)
 {
for (i=0;i<20;i++) // boucle 20fois, de valeur 0>19.
        buf[i]++;
        ecriture (buf,addr,20); // fonction ecriture
        }
        }
void main (int argc,char *argv[])
{
int     i,
        nb_process;
if ((argc !=1)){
    usage();
    exit(1);
    }
    init_ecrivain();
    ecrivain();
    sleep(30);
    if (semctl (semid,0,IPC_RMID,0)==-1) // chercher semctrol, noyau => detruit la semanphore
    erreur("erreur lors du semctl");

    if (shmctl(shmid,IPC_RMID,NULL)==-1) // chercher shmctl => detruit le memoire partagee
    erreur("erreur lors du shmctl");
    exit(0);
    }








