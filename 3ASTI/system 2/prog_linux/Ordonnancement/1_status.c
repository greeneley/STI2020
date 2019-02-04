/***********************************************************************\
   exemple_status
 
   Programme d'exemple du livre "Developpement systeme en C sous Linux"
   
   (c) 2000,2005 - Christophe Blaess
 
\***********************************************************************/

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>
	#include <sys/wait.h>

	void
affiche_status (pid_t pid)
{
	FILE * fp;
	char   chaine[80];
	sprintf(chaine, "/proc/%u/status", pid);
	if ((fp = fopen(chaine, "r")) == NULL) {
		fprintf(stdout, "Processus inexistant\n");
		return;
	}
	while (fgets(chaine, 80, fp) != NULL)
		if (strncmp(chaine, "State", 5) == 0) {
			fputs(chaine, stdout);
			break;
		}
	fclose(fp);
}


	int
main (void)
{
	pid_t	pid;
	char	chaine[5];

	fprintf(stdout, "PID = %ld\n", (long) getpid());
	fprintf (stdout, "�tat attendu = Running\n");
	affiche_status(getpid());
	if ((pid = fork()) == -1) {
		perror ("fork()");
		exit(EXIT_FAILURE);
	}
	if (pid != 0) {
		sleep(5);
		fprintf(stdout, "Consultation de l'etat de mon fils...\n");
		fprintf(stdout, "Etat attendu = Zombie\n");
		affiche_status(pid);
		fprintf(stdout, "Pere : Lecture code retour du fils...\n");
		wait(NULL);
		fprintf(stdout, "Consultation de l'etat de mon fils...\n");
		fprintf(stdout, "Etat attendu = inexistant\n");
		affiche_status(pid);
	} else {
		fprintf(stdout, "Fils : consultation de l'etat du p�re...\n");
		fprintf(stdout, "Etat attendu = Sleeping\n");
		affiche_status(getppid());	
		fprintf(stdout, "Fils : Je me termine\n");
		exit(EXIT_SUCCESS);
	}
	fprintf(stdout, "Attente de saisie de cha�ne \n");
	fgets(chaine, 5, stdin);
	exit(EXIT_SUCCESS);
}
