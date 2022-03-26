#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX 80
#define PORT 8080
//#define Port_Number
#define SA struct sockaddr

int number_Ofm = 1;

void func(int sockfd)
{
    char buff[MAX];
    int n;
    bzero(buff, sizeof(buff));

    // so setting while loop to keep writing
    // and also keep reading from the server
    while (1)
    {

        // so this while reads the number of messages it has received and printed

        // it reads number of messages
        while (number_Ofm < sizeof(buff))
        {

            printf("Enter the string : ");
            n = 0;
            while ((buff[n++] = getchar()) != '\n')
                ;

            write(sockfd, buff, sizeof(buff));

            // this is for exit

            if ((strncmp("exit", buff, 4)) == 0)
            {
                printf("Client Exit...\n");
                exit(0);
                //adding this section to kill this
            }
            else if ((strncmp("EXIT", buff, 4)) == 0)
            {
                printf("Client Exitt...\n");
                exit(0);
            }
            else if ((strncmp("Exit", buff, 4)) == 0)
            {
                printf("Client Exitt...\n");
                exit(0);
            }
            else if ((strncmp("e,x,i,t", buff, 4)) == 0)
            {
                printf("Client Exitt...\n");
                exit(0);
            }

            //till here

            bzero(buff, sizeof(buff));

            read(sockfd, buff, sizeof(buff));
            printf("From Server Message #%d: %s", number_Ofm, buff);

            number_Ofm++;

            if ((strncmp(buff, "exit", 4)) == 0)
            {
                printf("Client Exit...\n");
                exit(0);
                //adding this section to kill this
            }
        }
    }

    // this ncode is for exit from the client side
    /*
    if ((strncmp( "exit", buff, 4)) == 0){
    
        printf("client exit...\n");
        exit(0);

    
    }
    */
}

int main()
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and varification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
    {
        printf("Socket successfully created..\n");
    }

    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);
    //  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    // connect the client socket to server socket
    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
    {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
    {
        printf("connected to the server..\n");
    }

    // function for chat
    func(sockfd);

    // close the socket
    close(sockfd);
}

