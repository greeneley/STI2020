// ------------------------------------------------------------------
// exemple-nice.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#define _GNU_SOURCE
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

	volatile long compteur = 0;
	static int    gentillesse;

void gestionnaire (int numero)
{
	if (compteur != 0) {
		fprintf(stdout, "Fils %ld (nice %2d) Compteur = %9ld\n",
		                 (long) getpid(), gentillesse, compteur);
		exit(EXIT_SUCCESS);
	}
}

#define NB_FILS    5

int main (void)
{
	pid_t   pid;
	int     fils;

	/* Creation d'un nouveau groupe de processus */
	setpgid(0, 0); // pouvoir manipuler les processus par manier atomique , de cho bon processus nay nhan tin hieu quaisi stimulatement
			// 1e argument : cai nao la chef trong 1 group
			//  numero de PID qu'on donne au groupe
			// ham ket thuc khi trong group chi con 1 cai processus chef


	signal(SIGUSR1, gestionnaire); // installe un gestionaire au signal, SIGUSR1 reserve aux utilisateur, may cai con lai danh cho he thong
	for (fils = 0; fils < NB_FILS; fils ++) { // Boucle 5 fois, goi len 5 lan appel system fork
		if ((pid = fork()) < 0) { // ERREUR -> sefaire un kill, affiche l'ecran
			perror("fork");
			exit(EXIT_FAILURE);
		}
		if (pid != 0) // la variable retour de fork un source conclude dfr que 0
	// fork xong co 2 processus, khi con dc tao, a la fin du fork le pere recois pid du fils. thang con nhan valeur heritage 0 . do vay neu pid la pere thi la continue , tuc la quay lai boucle for, cree le boucle suivant(buoc nay la buoc cuoi cung roim xay ra sau 5 vong lap)
			continue;
		gentillesse = fils * (20 / (NB_FILS - 1)); // valeur cang grand, fils cang gentil
		if (nice(gentillesse) < 0) { // le processis plus mechant aura plus de temp au processor. LUL
			perror("nice");
			exit(EXIT_FAILURE);
		}
		/* attente signal de demarrage */
		pause();
		/* comptage */
		while (1)
			compteur ++;
	}
	/* processus pere */
	signal(SIGUSR1, SIG_IGN);// install sigin pour ignorer sigusr1
	sleep(1); // dors 1 seconde
	kill(-getpgid(0), SIGUSR1); // revoie ID au process groupe mais avec -: au groupe, pas de pere
	sleep(5); // dort 5 second
	kill(-getpgid(0), SIGUSR1);
	while (wait(NULL) > 0) // vi sao lai wait: cu moi lan con fils passe a l'etat zombi.
		;
	exit(EXIT_SUCCESS);
}

