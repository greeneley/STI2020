/* Allez voir dans le répertoire /dev/shm le résultat */
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
// espace de nommage : facon de nommer uniqueLes espaces de nommage sont des zones de déclaration qui permettent de délimiter la recherche des noms des identificateurs par le compilateur. Leur but est essentiellement de regrouper les identificateurs logiquement et d'éviter les conflits de noms entre plusieurs parties d'un même projet. Par exemple, si deux programmeurs définissent différemment une même structure dans deux fichiers différents, un conflit entre ces deux structures aura lieu au mieux à l'édition de liens, et au pire lors de l'utilisation commune des sources de ces deux programmeurs. Ce type de conflit provient du fait que le C++ ne fournit qu'un seul espace de nommage de portée globale, dans lequel il ne doit y avoir aucun conflit de nom. Grâce aux espaces de nommage non globaux, ce type de problème peut être plus facilement évité, parce que l'on peut éviter de définir les objets globaux dans la portée globale. 
// System5 : identifier le IPC : generer un cle
// POSIX: le numero d'inoeud de fichier existant ls-il : cot dau tien la numero inoeud 

// ln-s: creer un lien symbolique , different droit, khong co cung numero d'ineoud
// posix : sepasse dans le systeme de fichier, ajoute dans le systeme de fichier. -> plus facile que sys5
int main() {
sem_t *smutex;
/* creation d’un semaphore mutex initialisé à 1, en recuperant le file descripteur */
// 1e argu: le nom de semanphore dans le systeme de fichier
// les drapeau: creer exculive, en read and write
// 3e : le droit
// 1:  initialiser dedans le valeur 1 dans le semanpore
if ((smutex = sem_open("monsemloz", O_CREAT |O_EXCL | O_RDWR , 0666, 1)) == SEM_FAILED) {
if (errno != EEXIST) {// smp existe deja
perror("sem_open"); exit(1);
}
/* Semaphore deja créé, ouvrir sans O_CREAT, continue quand meme */
smutex = sem_open("monsem", O_RDWR);
}
/* P sur smutex: */
sem_wait(smutex); // wait mais wait pas tout de temp: sem_wait decremente le semanpore => je demande je passe, neu la 0 thi blockque
sleep(10);
//for(;;);
/* V sur smutex */
printf("Duoi loz di %d \n",getpid());
sem_post(smutex);
/* Fermer le semaphore */
sem_close(smutex);
sleep(30);
/* Detruire le semaphore */
sem_unlink("monsem");
return 0;
// GCC khong duoc
// le linkage: ld returned 1 exit status -> erreur
// sem_open : Link with -pthread  => phai them -pthread trong gcc moi duoc, khong ton tai trong GLIBC
// de chay : watch -n1 ls -l /dev/shm
}
