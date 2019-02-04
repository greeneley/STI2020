 // ------------------------------------------------------------------
// exemple-signal-3.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------
// #define	_XOPEN_SOURCE  constant symbolique , la norme POSIX,
// #define	_GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int i;
void gestionnaire (int numero)
{
	//int i;
	int compteur = 42;
	compteur++;
	signal(numero, gestionnaire); // La fonction installe lui meme , ONESHOT
	fprintf(stdout, "debut du gestionnaire de signal %d\n", numero);
	for (i = 1; i < 4; i ++) {
		fprintf(stdout, "%d\n", i);
		sleep(1); // 3 lan lap, thuc hien hon 3s 1 teo.
	}
	fprintf(stdout, "fin du gestionnaire de signal %d\n", numero); 
}

int main (void)
{
	signal(SIGUSR1, gestionnaire);
// creer un gestionaire du signal
// argument 1: signal concerne'.
// argument 2: la fonction du code execute, chercher la fonction gestionnaire et l'executer au debut .SI non, le signal ne declenche pas.
	// signal(SIGCHLD , gestionnaire);	
	if (fork() == 0) {
// appel system fork: le processus fait un appel vers le noyau en disant: creer moi un processus fils. Le noyau fait dupliquer le pere, il ne duplique qu'en memoire. il va donner un autre numero ( PIB). Le pere va recevoir PIB du fils.le fils recois 0 comme PIB. 
		kill(getppid(), SIGUSR1);
// 2e : nom du signal envoye' par cette fonction ( get ppid()) -> PIB du pere)
		sleep(1);
// con se ngu trong 1s
		kill(getppid(), SIGUSR1);
// il va se mettre dans un etat zombie, getppid return 0;

// Lam tiep vong thu 3
		sleep(1);
		kill(getppid(), SIGUSR1);
		while (1) pause();
	} else {
		while (1) // boucle infinie, le noyau il se mettre a l'etat stopper, il n'est plus content du temps pour exercuter le processor.  Fils dans l'etat attent et attendre un nouveau signal a arriver.
			pause();
	}
	return EXIT_SUCCESS;	
}

// 2Lam cach nao de biet le pere recoit le signal SIGCHILD, on doit voire le numero different
// kill -l Liste de signaux
//  ps "aux | grep sig2" l'etat zombie( defunct , Z+)

//3 Modifier le programme pour que le fils ne s'arrette pas.
// kill -SIGUSR1 numero processus de fils -> envoyer un signal

//4. Commenter la ligne signal dans la fonction gestionnaire

// 5 . Chuyen i thanh bien local => global . Vong lap for ko duoc thuc hien khi i= 4 (xuat hien may dong fin du...)
