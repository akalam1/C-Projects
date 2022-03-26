#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

//myfifo contains the file name for my fifo
//myrecording contains the file name for recording the conversation
//user is who is speaking or listening
//the array "theargs" passes the previous variables to processes
//message is what the users has typed
//userplusmessage is what is being sent to the user who is reading
//fdw is the file descriptor of the  writing side of the fifo
char *myfifo;
char *myrecording;
char *user;
char *theargs[5];
char message2[80];

char userplusmessage2[80];

int file_Descriptor;
int numofctrlzs;
// declaring str1 and 2 to for user 2 and 1
char str1[80], str2[80];

// here we are setting up the sigaction method to ask for signal 
// and also indicating signals

void tospeak(int sigtype)
{
    printf(" Asking for permisson to talk \n");

    char *myfifo = "myfifolab8.txt";
     mkfifo(myfifo, 0666);

    // Now open in write mode and write
    // string taken from user.
    fgets(str2, 80, stdin);

    file_Descriptor = open(myfifo, O_WRONLY);
    
    write(file_Descriptor, str2, strlen(str2) + 1);
     printf("sending -> %s",str2);
    printf(" this seems gd so far %d\n");
    //close(file_Descriptor);
}

// till here



int main(int argc, char *argv[])
{



//the sigaction struct is included in signal.h

struct sigaction mysignal;

// configure CTRL-Z to execute the "tospeak" function
// then use sigaction to change CTRL-Z's nature

mysignal.sa_handler =tospeak;
mysignal.sa_flags = SA_NODEFER | SA_RESETHAND;\
sigaction(SIGTSTP, &mysignal, NULL);

//till here


    // initialize meaningful variable names from passed arguments
    // then populate the parameter array "theargs"
    user = argv[1];
    //myfifo = argv[2];
    myrecording = argv[3];
    // theargs[0] = "./listen";
    theargs[1] = user;
    theargs[2] = myfifo;
    theargs[3] = myrecording;
    theargs[4] = NULL;

    char *myfifo = "myfifolab8.txt";

    mkfifo(myfifo, 0666);


    //this ection is for the writing once signal recieved

    if (sigaction(SIGTSTP, &mysignal, NULL)==-1) 
    {
        printf("it failed");

    }else{
        printf("writing");
    }

    //till here 



    
    while (1)
    {
        // First open in read only and read
        //close(fd1);
        file_Descriptor = open(myfifo, O_RDONLY);
        read(file_Descriptor, str1, 80);

        // Print the read string and close
        printf("User1: %s\n", str1);
        //close(file_Descriptor);
    }
    //ps -ef | egrep "listen|speak"

    return 0;
}
