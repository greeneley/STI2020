// ------------------------------------------------------------------
// exemple-sigaction-2.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
void gestionaire(){
	printf ("ahihi d0 ng0k's\n");
	
}
int main (void)
{
	int i;
	struct sigaction action;
	signal(SIG_IGN, gestionaire);
	for (i = 1; i < NSIG; i ++) { // tant que nsignal boucle
		if (sigaction(i, NULL, & action) != 0) // khong phai installe un signal, vi 1e parametre la i, khong phai structure sigaction. // REcupere le comportement a chaque signal, luu vao structure action
			fprintf(stderr, "%d : Erreur\n", i);
		if (action.sa_handler != SIG_DFL) { // soit il est dfr au  sig-default
			fprintf(stdout, "%d (%s) : ", // print i et le nom de signal
				i, sys_siglist[i]);
			if (action.sa_handler == SIG_IGN) // si ignorer le signal
				fprintf(stdout, "ignore\n"); 
			else
				fprintf(stdout, "personnalise\n");  // pour ce signal la, on a installe in gestionaire, c'est etait personnalise
		}
	}
	return EXIT_SUCCESS;
}
