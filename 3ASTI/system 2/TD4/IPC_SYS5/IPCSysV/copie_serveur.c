#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h> // repertoire par defaut

#include "copie.h" //  dans repertoire locale

static void usage (char *pgr)
{
printf (" Exemple d'application utilisant les files de messages\n");
printf (" Ce programme est le serveur \n");
printf (" %s fichier1 fichier2 \n\n", pgr);
exit(-1);
}

static void erreur (char *msg, char *appel)
{
fprintf (stderr, " Erreur du Serveur %s :%d \n",msg,errno);
perror(appel);
exit(-1);
}

static void close_all (int id_file, int fd1, int fd2)
{
msgctl (id_file, IPC_RMID, NULL); // delete de file de message
close(fd1);
close(fd2);
}

int main (int argc, char **argv)
{
int fd1,fd2,id_file; // 3 file descripteur : 2 pour 2 clients + la file de message (file de message est comme le fichier) 
key_t clef;// permet de stocker une cle
data_t data1,data2; // enveloppe 
int	end1=1,end2=1;

if (argc != 3)
	usage (argv[0]);

if ((fd1= open (argv[1], O_RDONLY)) == -1)
	erreur("Erreur lors du open1", "open");
if ((fd2= open (argv[2], O_RDONLY)) == -1)
		{
		close(fd1);
		erreur("Erreur lors du open2", "open");
		}

if ((clef = ftok (FICHIER_CLEF, PROJ_FTOK)) == -1) // generer la cle
	{
	close (fd1);
	close (fd2);
	erreur( "Erreur lors du ftok","ftok");
	}

if (( id_file = msgget (clef, IPC_CREAT | IPC_EXCL | 0666)) == -1) { // obtenir la fille message
// IPC_Creat : le sv demande de noyau de creer un nouveau file de message
// IPC_EXCL: exclusif, si le file de message exist deja ca va proquer un erreur.
// 0 - octale 0-7
// 0x - decimal
	close (fd1);
	close (fd2);
	erreur( "Erreur lors du msgget","msgget");
	}
// la cle ne sert a plus maintenant, c'est le fichier discripteur.

printf (" Serveur : File de message (%d) créée \n: copie de %s et %s \n", id_file, argv[1],argv[2]);

data1.type= TYPE_FIC1;
data2.type= TYPE_FIC2;
data1.taille=data2.taille=1;
while (( data1.taille || data2.taille)) {
	if (data1.taille) {
			data1.taille = read (fd1, data1.buf, SIZE_BUF * sizeof(char));
			if (data1.taille == -1) {
			close_all(id_file,fd1,fd2);
			erreur ( "Erreur pendant lecture1","read");
			}
	// mettre le file du message		
	if (msgsnd (id_file, (struct msgbuf *) &data1, sizeof(data1.buf) + sizeof (int),0 )== -1)
			erreur (" Erreur pendant envoi file de message 1", "msgsnd");
			}
	if (data2.taille) {
			data2.taille = read (fd2, data2.buf, SIZE_BUF * sizeof(char));
			if (data2.taille == -1) {
				close_all(id_file,fd1,fd2);
				erreur ( "Erreur pendant lecture2","read");
			}
			if (msgsnd (id_file, (struct msgbuf *) &data2, sizeof(data2.buf) + sizeof (int),0 )== -1)
				erreur (" Erreur pendant envoi file de message 2", "msgsnd");
	}
}


        printf (" Serveur : Copie des fichiers dans la file terminée \n");
        printf ( " Serveur : En attente des clients \n");

        while ((end1) || (end2)) {
                                               data_t rec;

     if (msgrcv (id_file, &rec, sizeof (data_t), TYPE_END1, IPC_NOWAIT) != -1)
                                                end1=0;
     if (msgrcv (id_file, &rec, sizeof (data_t), TYPE_END2, IPC_NOWAIT) != -1)
                                                end2=0;
                                   }

 printf ("Serveur : Travail terminé \n");

 close_all (id_file,fd1,fd2);
 
}

