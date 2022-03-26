#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <dirent.h>
#include <pwd.h>

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
char command[150];

// change it later to message[80];
char arr1[80];
int fdw;

//change it later to userplusmessage[80];
char arr2[80];

int main(int argc, char *argv[])
{

  // initialize meaningful variable names from passed arguments
  // then populate the parameter array "theargs"
  user = argv[1];
  //myfifo = argv[2];
  myrecording = argv[3];
  theargs[0] = "./listen";
  theargs[1] = user;
  theargs[2] = myfifo;
  theargs[3] = myrecording;
  theargs[4] = NULL;

  char *myfifo = "myfifolab8.txt";

  // instruct the user
  printf("\nType in a Message you want to Send\n");

  // make or ensure their exists a fifo
  mkfifo(myfifo, 0666);

  // accept the input from the user

  /*
  fgets(arr1, 80, stdin);
  strcpy(arr2, user);
  strcat(arr2, ":");
  strcat(arr2, arr1);
  */

  while (1)
  {

    fgets(arr2, 80, stdin);

    //open the fifo in Writing mode (WRONLY)
    //then write the message to the writing side of the FIFO using fdw
    fdw = open(myfifo, O_RDWR);
    write(fdw, arr2, strlen(arr2) + 1);
    printf("sending -> %s", arr2);

    //close(fdw);
  }

  fdw = open(myfifo, O_RDONLY);
  read(fdw, arr1, sizeof(arr1));
  printf("User2: %s\n", arr1);

  //go back to listening by overwriting this process (without forkig)

  execvp(theargs[0], theargs);

  //strcpy( ps -ef | egrep "listen|speak");
}

