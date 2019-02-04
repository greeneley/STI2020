#ifndef __VEHICULE_H__
#define __VEHICULE_H__
struct vehicule {
	char nom_modele[20];
	int puissance;
	float vitesse_max;
};
typedef struct vehicule vehicule;
extern void init_vehicule(vehicule**);
extern void affichage_vehicule(vehicule*);
extern void destroy_vehicule(vehicule*);
#endif
