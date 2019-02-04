#include <stdio.h>
typedef unsigned long int Huge;
// a^b mod n
static Huge modexp(Huge a,Huge b, Huge n){
	Huge y;
	y = 1;
	while(b!=0){
		if(b&1)
			y = (y*a) % n;
		a = (a*a)%n;
		b = b >> 1;
	}
	return y;
}
static Huge gcd(Huge a,Huge b){
	if ( a < b )
		return gcd( b, a)
	if (b == 0)
    		return a;
  	else
    		return gcd(b, a % b);
}
static Huge* clefs(Huge p,Huge q){
	/*
	This function generates key from 2 number p and q
	*/
	static Huge clefs[3]; 
	Huge n,phi_n;
	n = p*q;
	phi_n = (p-1)*(q-1);
	Huge i,e,d;
	// trouver e min
	for (i = 965;i < phi_n;i++){
		if ((gcd(i,phi_n) == 1)) {e=i; break;}
	}
	// trouver d min
	for (i = 1;i < phi_n;i++){
		if (((e*i) % phi_n == 1 )) {d=i;break;}
	}
	// afficher
	printf("phi %d\n ",phi_n);
	clefs[0] = e;
	clefs[1] = n;
	clefs[2] = d;
	return clefs;
}
static Huge plus_grand_premier(Huge N){
	Huge i;
	for (i = N;i > 1;i--){
		if (gcd(N,i) == 1) return i;
	}
}
static Huge* clefs_generateur(Huge A, Huge B){
	/*
	Key generator, takes 2 parameters A and B, generate key from the greatest premier number that < A and < B
	*/
	Huge P = plus_grand_premier(A);
	Huge Q = plus_grand_premier(B);
	Huge *clefs_pair = clefs(P,Q);
	return clefs_pair;

}
static Huge rsa_crypt(Huge e, Huge n, Huge M){
	/*
	This function takes input e,n est public key, M is the code that needs to be crypted. This function return the crypted message c.
	*/
	Huge c = modexp(M,e,n);
	printf ("Cle chiffre %d \n", c);
	return c;
}
static Huge rsa_decrypt(Huge d, Huge n, Huge C){
	/*
	This function takes input d as private key, C is the code that needs to be decrypted. This function return the decrypted message M
	*/
	Huge M = modexp(C,d,n);
	printf ("Message dechiffre %d \n", M);
	return M;
}
int main()
{
	Huge c,M;
	Huge *cle = clefs_generateur(32,138); printf("OK\n");
	// Cle[0] and Cle[1] are public keys, e and n respectively, Cle[2] is private key d.
	printf("Clef publics: e %d and n %d\n",*cle,*(cle + 1));
	printf("Clef privee:  d %d\n",*(cle + 2));
	c = rsa_crypt(cle[0],cle[1],3333);
	M = rsa_decrypt(cle[2],cle[1],c);
	return 1;
}
