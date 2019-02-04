#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string.h>
#include <rpc/des_crypt.h>
typedef unsigned long int Huge;
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
void error(char *msg)
{
    perror(msg);
    exit(0);
}


int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    /*
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    */
    // ENVOI D UN MESSAGE
    //n = write(sockfd,&p,sizeof(Huge));
    //TODO DH
    Huge p = 23;
    Huge g = 3;
    Huge a = 6;
    Huge A = modexp(g,a,p);
    printf("g: %li,p %li , A %li\n", g,p,A);
     
    write(sockfd,&g,sizeof(Huge));
    write(sockfd,&p,sizeof(Huge));
    write(sockfd,&A,sizeof(Huge));
    
    Huge B;
    read(sockfd,&B, sizeof(Huge));
    Huge K = modexp(B,a,p);
    printf("g: %li,p %li , A %li, B %li, K %li\n", g,p,A,B,K);

    // Receive message
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    char key[8];
    bzero(key,8);
    sprintf(key,"%li",K);
    des_setparity(key);
    ecb_crypt(key,buffer,8*sizeof(char),DES_DECRYPT);
     // Attention message multipe de 8 bits
    printf("BUFFER %s\n", buffer);
    
    /*
    if (n < 0) 
         error("ERROR writing to socket");
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0) 
         error("ERROR reading from socket");
    printf("%s\n",buffer);
    */
    return 0;
}
