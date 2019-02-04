/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
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
    exit(1);
}

int main(int argc, char *argv[])
{   
     int sockfd, newsockfd, portno, clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
     bzero(buffer,256);
     // RECEPTION D UN MESSAGE
     //n = read(newsockfd,&p,sizeof(Huge));

     // TODO DH
     Huge g,p,A;
     read(newsockfd, &g,sizeof(Huge));
     read(newsockfd, &p,sizeof(Huge));
     read(newsockfd, &A,sizeof(Huge));
     printf("g: %li,p %li , A %li\n", g,p,A);

     Huge b=15;
     Huge B = modexp(g,b,p);
     write(newsockfd, &B,sizeof(Huge));
     Huge K = modexp(A,b,p);
     printf("g: %li,p %li , A %li, B %li, K %li\n", g,p,A,B,K);
     char key[8];
    bzero(key,8);
    sprintf(key,"%li",K);
    des_setparity(key);
     // Attention message multipe de 8 bits,
    char * message = "coucou!\n";
    bzero(buffer,256);
    sprintf(buffer,"%s", message);
    printf("%s", buffer);
    ecb_crypt(key,buffer,8*sizeof(char));
     //send message
    write(newsockfd, buffer,8*sizeof(char));



     /*
     if (n < 0) error("ERROR reading from socket");
     printf("Here is the message: %d\n",p);
     n = write(newsockfd,"I got your message",18);
     if (n < 0) error("ERROR writing to socket");
     */
     return 0; 
}
