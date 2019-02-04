#include <stdio.h>
/*
* Usage: main key input_file output_file
*/
int main(int argc, char *argv[]) {
    FILE *fi, *fo;
    char *cp;
    int c;
    if (cp = argv[1]) {
        if ((fi = fopen(argv[2], "rb")) != NULL) {
            if ((fo = fopen(argv[3], "wb")) != NULL) {
                while ((c = getc(fi)) != EOF) { //EOF: end of file ,
                if (*cp == '\0' ) cp = argv[1];
                c = ((c - 65 + *cp - 65 ) % 26 ) + 65 ; //continuer pointer cp , a la fin de cp , il retourne argv[1]
                putc(c,fo);
                }
                fclose(fo);
            }     
            fclose(fi);
        }
    }
    return 1;
}