#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehicule.h"
int main(){
 vehicule *v;
 init_vehicule(&v);
 affichage_vehicule(v);
 destroy_vehicule(v);
 return 0;
}
