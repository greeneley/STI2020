// ------------------------------------------------------------------
// exemple-siginterrupt.c
// Fichier d'exemple du livre "Developpement Systeme sous Linux"
// (C) 2000-2010 - Christophe BLAESS -Christophe.Blaess@Logilin.fr
// http://www.logilin.fr
// ------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

void gestionnaire (int numero)
{
	fprintf(stdout, "\ngestionnaire de signal %d\n", numero); 
}

int main (int argc, char *argv[])
{
	int i;

	if ((argc != 2) || (sscanf(argv[1], "%d", & i) != 1)) { // chuyen gia tri %d (sang gia tri numerique ) vao i, kiem tra xem no co phai so nguyen hay khong
		fprintf (stderr, "Syntaxe : %s {0|1}\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	signal(SIGINT, gestionnaire); // installe gestionaire au sigint
	// siginterrupt(SIGINT, i); // signal concerne m sigint la Control + C 

	while (1) { // boucle infinie
		fprintf(stdout, "appel read()\n"); 
		if (read(STDIN_FILENO, &i, sizeof (int)) < 0) // appel systeme read
			{if (errno == EINTR) // quel valeur renvoyer appel system read - nombre caractere elle lire reussir - donc si zero -> mal passer . 
// La valeur errno == EINTR. -> khong retourner appel systeme nua
				fprintf(stdout, "je suis sorti du read EINTR \n");} // lancer read mais sortir du premier read
				else
				fprintf(stdout, "Valeur de i : %s\n",i);  // muon hien thi 12 thi %s
	}
	return EXIT_SUCCESS;	
}
