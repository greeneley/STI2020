#include <stdio.h>
extern char ** env;
int main ( int argc, char ** argv, char ** env){
	// La valeur environnement est comme les arguments
	int i;
	// afficher tout les arguments (co argc arguments)
	for (i=0; i< argc;i++){
		printf("L'argument numero %i est %s\n",i, argv[i]);}
	i=0;	
	while (env[i] != NULL) {
		printf("Variable d'environnement %d contient: %s\n", i, env[i]);
		i++;
	}
	printf("L'address de argv %x et %p\n",&argv, &argv);
	// %p hien thi 4 octets,considerer l'adresse memore 4 octets - 32 bits => LITTLE INDIAN
	// %x hiej thi 8 octest, 64 bits -> BIG INDIAN
	return 0;
}
