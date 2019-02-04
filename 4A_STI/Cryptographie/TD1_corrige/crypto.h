/*
* Chiffrement utilisant le ou exclusif
*/
void xor_crypt(char* key, char* texte, char* chiffre);
/*
* D ́
echiffrement utilisant le ou exclusif
*/
void xor_decrypt(char* key, char* chiffre, char* clair);
/*
* Chiffrement utilisant cesar
*/
void cesar_crypt(int decallage, char* texte, char* chiffre);
/*
* D ́
echiffrement utilisant cesar
*/
void cesar_decrypt(int decallage, char* chiffre, char* clair);
/*
* Chiffrement utilisant viginere
*/
void viginere_crypt(char* key, char* texte, char* chiffre);
/*
* D ́
echiffrement utilisant viginere
*/
void viginere_decrypt(char* key, char* chiffre, char* clair);
/*
* Chiffrement utilisant des
*/
void des_crypt(char* key, char* texte, char* chiffre, int size);
/*
* D ́
echiffrement utilisant des
*/
void des_decrypt(char* key, char* chiffre, char* clair, int size);
/*
* Chiffrement utilisant 3des
*/
void tripledes_crypt(char* key1, char* key2, char* texte, char* chiffre,
, →
int size);
/*
* D ́
echiffrement utilisant 3des
*/
void tripledes_decrypt(char* key1, char* key2, char* chiffre, char*
, →
clair, int size);
/*
* Chiffrement RSA
*/
void rsa_crypt(int e, int n, char* texte, char* chiffre, int size);
/*
* D ́
echiffrement RSA
*/
void rsa_decrypt(int d, int n, char* chiffre, char* clair);