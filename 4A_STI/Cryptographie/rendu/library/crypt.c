#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "crypt.h"
#include "encrypt.h"
#include "md5.h"
#include "bit.h"
#include <math.h>



/**
 *  * chiffrement utilisant le ou exclusif
 *   */
void xor_crypt(char * key, char * texte, char* chiffre)
{
    char *cle;
    int i, c;
    if((cle = key) && texte){
        for(i = 0; (c = texte[i]) != '\0'; chiffre[i++] = (char) c){
            if(*cle == '\0') cle = key;
            c ^= *(cle++);
        }
        chiffre[i] = '\0';
    }
}

/**
 *  * d�chiffrement utilisant le ou exclusif
 *   */
void xor_decrypt(char * key, char * texte, char* chiffre)
{
    xor_crypt(key, texte, chiffre);
}

/**
 *  * chiffrement utilisant cesar
 *   */
void cesar_crypt(int decallage, char * texte, char* chiffre)
{
    int i, c;
    if(texte){
        for(i = 0; (c = texte[i]) != '\0'; chiffre[i++] = (char) c){

            c = c > 'Z' ? 'a' + (decallage + c - 'a') % 26 : 'A' + (decallage + c - 'A') % 26;
        }
        chiffre[i] = '\0';
    }
}

/**
 *  * d�chiffrement utilisant  cesar
 *   */
void cesar_decrypt(int decallage, char * texte, char* chiffre)
{
    cesar_crypt(26-decallage, texte, chiffre);
}

/**
 *  * chiffrement utilisant viginere
 *   */
void viginere_crypt(char * key, char * texte, char* chiffre)
{
    char *cle;
    int i, j, c;
    if((cle = key) && texte){
        for(i = 0; (c = texte[i]) != '\0'; chiffre[i++] = (char) c, cle++){
            if(*cle == '\0') cle = key;

            j = *cle - (*cle > 'Z' ? 'a' : 'A');
            c = c > 'Z' ? 'a' + (j + c - 'a') % 26 : 'A' + (j + c - 'A') % 26;
        }
        chiffre[i] = '\0';
    }
}

/**
 *  * d�chiffrement utilisant viginere
 *   */
void viginere_decrypt(char * key, char * texte, char* chiffre)
{
    char *cle;
    int i, j, c;
    if((cle = key) && texte){
        for(i = 0; (c = texte[i]) != '\0'; chiffre[i++] = (char) c, cle++){
            if(*cle == '\0') cle = key;

            j = *cle - (*cle > 'Z' ? 'a' : 'A');
            c = c > 'Z' ? 'a' + (26 - j + c - 'a') % 26 : 'A' + (26 - j + c - 'A') % 26;
        }
        chiffre[i] = '\0';
    }
}

/**
 *  * chiffrement utilisant des
 *   */
void des_crypt(char * key, char * texte, char* chiffre, int size) // ecb
{
    unsigned char src[8] = {0};
    int i, c;
    for(i = c = 0; i < size - 1; c = ++i << 3){
        memcpy(src, texte + c, 8);
        des_encipher(src,(unsigned char *) chiffre + c, (unsigned char *) key);

    }
    memset(src, 0, 8);
    strncpy((char*) src, texte + c, 8);
    des_encipher(src,(unsigned char *) chiffre + c, (unsigned char *) key);
}
/**
 *  * d�chiffrement utilisant des
 *   */
void des_decrypt(char * key, char * texte, char* chiffre, int size)
{
    unsigned char src[8] = {0};
    int i, c;
    for(i = c = 0; i < size; c = ++i << 3){
        memcpy(src, texte + c, 8);
        des_decipher(src,(unsigned char *) chiffre + c, (unsigned char *) key);
    }
}
/*
 * chiffrement utilisant des CBC
 */
void des_crypt_cbc(char* vect_init, char* key, char* texte, char* chiffre, int size)
{
    unsigned char buf[8] = {0}, buf2[8] = {0};
    int i, c;
    memcpy((char*)buf, (char*) vect_init, 8);
    for(i = c = 0; i < size; c = ++i << 3){
        bit_xor((unsigned char *)texte+c, buf, buf2, 64);
        des_encipher(buf2,buf, (unsigned char *) key);
        memcpy(chiffre + c, buf, 8);
    }

}

/*
 * dechiffrement utilisant des CBC
 */
void des_decrypt_cbc(char* vect_init, char* key, char* chiffre, char* clair, int size)
{
    unsigned char buf[8] = {0}, *tmp;
    int i, c;
    tmp = vect_init;
    for(i = c = 0; i < size; c = ++i << 3){
        des_decipher((unsigned char *)chiffre + c, buf, (unsigned char*)key);
        bit_xor(buf, tmp, (unsigned char *)clair + c, 64);
        tmp = (unsigned char *)chiffre + c;
    }
}


/**
 *  * chiffrement utilisant 3des
 *   */
void tripledes_crypt(char * key1, char * key2, char * texte, char* chiffre,int size)
{
    unsigned char src[8] = {0};
    int i, c;
    for(i = c = 0; i < size - 1; c = ++i << 3){
        memcpy(src, texte + c, 8);
        des_encipher(src,(unsigned char *) chiffre + c, (unsigned char *) key1);
        des_decipher((unsigned char *) chiffre + c, src, (unsigned char*) key2);
        des_encipher(src, (unsigned char *) chiffre + c, (unsigned char *) key1);
    }
    memset(src, 0, 8);
    strncpy((char*) src, texte + c, 8);
    des_encipher(src,(unsigned char *) chiffre + c, (unsigned char *) key1);
    des_decipher((unsigned char *) chiffre + c, src, (unsigned char*) key2);
    des_encipher(src, (unsigned char *) chiffre + c, (unsigned char *) key1);
}


/**
 *  * d�chiffrement utilisant 3des
 *   */
void tripledes_decrypt(char* key1, char* key2, char* texte, char* chiffre, int size)
{
    unsigned char src[8] = {0};
    int i, c;
    for(i = c = 0; i < size; c = ++i << 3){
        memcpy(src, texte + c, 8);
        des_decipher(src,(unsigned char *) chiffre + c, (unsigned char *) key1);
        des_encipher((unsigned char *) chiffre + c,src, (unsigned char *) key2);
        des_decipher(src, (unsigned char *) chiffre + c, (unsigned char *) key1);
    }
}

/*
 * chiffrement utilisant 3des CBC
 */
void tripledes_crypt_cbc(char * vect_init, char* key1, char* key2, char* texte, char* chiffre, int size)
{
    unsigned char src[8] = {0}, buf[8] = {0}, buf2[8] = {0};
    int i, c;
    memcpy(buf, vect_init, 8);
    for(i = c = 0; i < size - 1; c = ++i << 3){
        memcpy((char*)src, texte + c, 8);
        bit_xor(src, buf, buf2, 64);
        des_encipher(buf2,buf, (unsigned char *) key1);
        des_decipher(buf, buf2, (unsigned char*) key2);
        des_encipher(buf2, buf, (unsigned char *) key1);
        memcpy(chiffre + c, (char*)buf, 8);
    }
    memset(src, 0,8);
    strncpy((char*)src, texte + c, 8);
    bit_xor(src, buf, buf2, 64);
    des_encipher(buf2,buf, (unsigned char *) key1);
    des_decipher(buf, buf2, (unsigned char*) key2);
    des_encipher(buf2, buf, (unsigned char *) key1);
    memcpy(chiffre + c, (char*)buf, 8);

}


/*
 * dechiffrement utilisant 3des CBC
 */
void tripledes_decrypt_cbc(char * vect_init, char* key1, char* key2, char* chiffre, char* clair, int size)
{
    unsigned char src[8] = {0}, buf2[8] = {0}, *buf;
    int i, c;
    buf = vect_init;
    for(i = c = 0; i < size; c = ++i << 3){
        memcpy((char*)src, chiffre + c, 8);
        des_decipher(src,buf2, (unsigned char *) key1);
        des_encipher(buf2,src, (unsigned char *) key2);
        des_decipher(src, buf2, (unsigned char *) key1);
        bit_xor(buf2, buf, (unsigned char *) clair + c, 64);
        buf = (unsigned char *)chiffre + c;
    }

}

/*
 * Calcul du condense MD5 du texte
 */
void md5(char * texte, char * hash){
	md5_bis (texte, strlen (texte), hash);
}

/****************************************************************
 *                                                               *
 *  -------------------------- modexp -------------------------  *
 *                                                               *
 ****************************************************************/

static Huge modexp(Huge a, Huge b, Huge n) {

	Huge               y;

	/****************************************************************
	 *                                                               *
	 *  Calcule (pow(a, b) % n) avec la m�thode du carr� binaire     *
	 *  et de la multiplication.                                     *
	 *                                                               *
	 ****************************************************************/

	y = 1;

	while (b != 0) {

		/*************************************************************
		 *                                                            *
		 *  Pour chaque 1 de b, on accumule dans y.                   *
		 *                                                            *
		 *************************************************************/

		if (b & 1)
			y = (y * a) % n;

		/*************************************************************
		 *                                                            *
		 *  �l�vation de a au carr� pour chaque bit de b.             *
		 *                                                            *
		 *************************************************************/

		a = (a * a) % n;

		/*************************************************************
		 *                                                            *
		 *  On se pr�pare pour le prochain bit de b.                  *
		 *                                                            *
		 *************************************************************/

		b = b >> 1;

	}

	return y;

}


/**
 * Transforme une chaine de caractere en chaine d'entier
 */
void texttoint(char * texte, char* chiffre, int size){
	*chiffre='\0';
	int tmp;
	int i;
	for(i=0;i<size;i++){
	    // on ajoute 10 pour eviter le probleme de disparition du 0 devnt les entiers entre 1 et 9 (01 a 09)
		// ceci evite de decouper le texte en bloc de taille < n et de les normaliser ensuite
		tmp=(*(texte+i)-'a'+10);
		sprintf(chiffre+strlen(chiffre),"%d%c",tmp,'\0');
	}
}

/**
 * Transforme une chaine d'entier en chaine de caractere
 */
void inttotext(char * texte, char* chiffre){
	*chiffre='\0';
	int tmp=0;
	while((*texte) != '\0'){
	    // lettre de l'alphabet (0..25 correspond pour nous a 10..35)
		if(10*tmp+(*(texte)-'0') > 36){
		    // on deduit donc 10 pour obtenir la bonne lettre dans l'alphabet
			sprintf(chiffre+strlen(chiffre),"%c%c",tmp+'a'-10, '\0');
			tmp=0;
		}
		tmp=10*tmp+(*(texte)-'0');
		texte++;
	}
}

/**
 * Chiffrement RSA
 */
void rsa_crypt(Huge e, Huge n, char * texte, char* chiffre, int size)
{
    Huge tmp;
	Huge buf=0, buf2;
	char* pt;
	char* btmp = (char *)malloc(strlen(texte) * sizeof(char));

	texttoint(texte,btmp,size);
	pt = btmp;
	*chiffre='\0';
	while((*pt) != '\0'){
		tmp=*pt-'0';
		if(10*buf + tmp >= n){
		    // on utilise le $ comme s�parateur de bloc
			sprintf(chiffre+strlen(chiffre),"%ld$%c", modexp(buf, e, n),'\0');
			buf=0;
		}
		buf=10*buf+tmp;
		pt++;
	}
	buf2 = modexp(buf, e, n);
	sprintf(chiffre+strlen(chiffre),"%ld$%c", buf2,'\0');
	printf("\n");
}

/**
 * Dechiffrement RSA
 */
void rsa_decrypt(Huge d, Huge n, char * texte, char* chiffre)
{
	Huge tmp;
	char* pt=texte;
	char* tmpc= (char *)malloc(strlen(texte) * sizeof(char));
	Huge buf=0, buf2;

	*tmpc='\0';
	while((*pt) != '\0'){
		// on utilise le $ comme s�parateur de bloc
	    if((*pt) == '$'){
			sprintf(tmpc+strlen(tmpc),"%ld%c", modexp(buf, d, n),'\0');
			buf=0;
		}else{
			tmp=*pt-'0';
			buf=10*buf+tmp;
		}
		pt++;
	}
	buf2 =  modexp(buf, d, n);
	sprintf(tmpc+strlen(tmpc),"%ld%c", buf2,'\0');

	inttotext(tmpc,chiffre);
}
