#ifndef COPIE_H  // si copie_h nest pas connu, on faire la suite, si non on repasse des fois
#define COPIE_H 

#define FICHIER_CLEF "copie.h" // il faut gerer une cle/IPC
// le numero d'inode du fhicier

#define PROJ_FTOK 'a' // pour la fonction key_t ftok

#define TYPE_FIC1 1 // pour l'enveloppe du fichier 1 ( dong dau)
#define TYPE_FIC2 2
#define TYPE_END1 3 // le noyau gere la file de message, pour que le serveur peut elimier le message, le sv doit savoir quand la client aura fini de recuperer dd'enveloppe. Si le sv trouve marque 3-4 -> le sv connais que les clients sont finis
// D'autre facon: gestionaire du signal chez le sv, quand le message est fini le client envoiera le signal SIGUSR1
#define TYPE_END2 4

#define SIZE_BUF 256

typedef struct data_s data_t;
struct data_s {
	long type; // L'etiquette d'envelope -> ne veux pas changer
	int taille; // combien d'octets perninents dans le tableau, donnes utiles
	char buf[SIZE_BUF]; // tableaux de 256 octets. le message est coupe de 256 octets
};
#endif
