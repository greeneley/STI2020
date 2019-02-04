#include <stdio.h>
#include "des.c"

int main()
{
	unsigned char source[] = "thanhhai", // c'est la character qu'on a besoin de chiffrer
	     dest[256],
	     dest2[256];
	// des_encipher est de chiffrer la character
	des_encipher(source,dest, (unsigned char*)"chabada");
	puts((char*)dest); 
	// des_decipher est de dechiffrer 
	des_decipher(dest, dest2, (unsigned char*)"chabada");
	puts((char*)dest2);
	exit(0);
}


