#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
typedef unsigned long int Huge;
typedef struct cle{
    Huge e; // cle public
    Huge n; // cle public
    Huge d; // cle private
} cle;
static Huge modexp(Huge a, Huge b, Huge n ){
    Huge y;
    y = 1;
    while(b != 0 ){
        if(b & 1)
            y = (y*a)%n;
        a = (a*a)%n;
        b = b >> 1;
    }
    return y;
}

// PGCD
static Huge gcd(Huge a, Huge b){
    if (b == 0)
    		return a;
  	else
    		return gcd(b, a % b);
}
// Create cle privee d
static Huge secret_keyGen(Huge e, Huge phi){
    Huge compte = 1;
    while(compte != 0 ){
        if((compte*phi + 1) % e == 0){
            return (compte*phi + 1) / e ;
        }
        compte ++;
    }
}
// Generer a prime number
static Huge premier_aleatoire(Huge N){
    bool premier = false;
    while(!premier){
        srand(time(0));
        Huge tmp = rand() % N;
        for(Huge i = 2; i <= sqrt(tmp); i++){
            if( tmp % i == 0 )
                break;
            if(i > sqrt(tmp) - 1)
                return tmp; 
        }
    }
}
// genere Paire Key
static cle generation_cle(Huge P, Huge Q){
    struct cle key;
    //================
    key.n = P*Q;
    Huge phi_n = (P-1)*(Q-1);
    // Create value e
    Huge compte = 965;
    while(compte < phi_n){
        // printf("%ld \n", gcd(compte, phi_n));
        if(gcd(compte, phi_n) == 1){
            key.e = compte;
            break;
        }
        compte++;
    }
    //  Create value d
    key.d = secret_keyGen(key.e , phi_n);
    //
    return key; 
};
// Chiffrer et dechiffrer 
static Huge rsa_encrypt(Huge e, Huge N, Huge message_chiffrer){
    return modexp(message_chiffrer, e, N);
}
static Huge rsa_decrypt(Huge d, Huge N, Huge message_dechiffrer){
    return modexp(message_dechiffrer, d, N);
}
int main(int argc,char *argv[]){
    struct cle Key;
    Key = generation_cle(31, 137);
    printf("%ld , %ld, %ld \n", Key.e, Key.n, Key.d);
  
    return 0;
    
}
