#ifndef __PILE_H__
#define __PILE_H__
/* Structure de gestion de la pile */
typedef struct vehicule{
 char nom_modele[20];
 int puissance;
 float vitesse_max;
} vehicule;
typedef struct
{
 int nbVehicule;
 vehicule **tpv;/*tpv est un tableau de pointeurs sur véhicules!*/
} pilevehicule;
extern void saisie_vehicule(vehicule*);	
extern pilevehicule *init_pilevehicule();
extern void empile_vehicule(pilevehicule* ,vehicule*);
extern void affiche_vehicule(vehicule*);
extern void affiche_pilevehicule(pilevehicule*);
extern vehicule* depile_vehicule(pilevehicule*);
extern void supprime_pile(pilevehicule*);
#endif
