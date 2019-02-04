// ------------------------------------------------------------------
// exemple-sigaction-1.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void gestionnaire (int numero)
{
	switch (numero) {
		case SIGQUIT :
			fprintf(stdout, "\nSIGQUIT recu\n");
			break;
		case SIGINT :
			fprintf(stdout, "\nSIGINT recu\n");
			break;
	}
}

int main (void)
{
	struct sigaction action;

	action.sa_handler = gestionnaire; // Pointeur sur le gestionaire du signal
	sigemptyset(& (action.sa_mask)); // set the signal to empty, with all signals excluded from the set
	action.sa_flags = 0;

	if (sigaction(SIGQUIT, & action, NULL) != 0) { // Fonction installe une gestionaire au signal
// savoir qui envoyer signal.
// c'est un autre processus qui part intermediaire au noyau envoyer signal
// proprietaire
// on peux passer plus numero de signal, soit valeur soit pointeur, par ex: restart
// LUNDI : man sigaction
// de sauvergarder le signal dans la stucture action
		fprintf(stderr, "Erreur %d\n", errno);
		exit(EXIT_FAILURE);
	}

	action.sa_flags = SA_RESTART | SA_RESETHAND;
	// appel system lent
	if (sigaction(SIGINT, & action, NULL) != 0) { // sigint de vi Ctrl + C
		fprintf(stderr, "Erreur %d\n", errno);
		exit(EXIT_FAILURE);
	}

	/* Lecture continue, pour avoir un appel-systeme lent  bloque */
	while (1) {
		int i;
		fprintf(stdout, "appel read()\n");
		if (read(0, & i, sizeof(int)) < 0) // appel systeme lent : read,write
			if (errno == EINTR)
				fprintf(stdout, "EINTR \n");
	}
	return EXIT_SUCCESS;

}

