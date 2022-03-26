#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

//hard coded file name for my fifo
//hard coded file name for recording the conversation
//the variable "user" is an option on the command line
//the array "theargs" passes the previous variables to processes
char *myfifo = "lab8.txt";
char *myrecording = "Abul.out";
char *theargs[5];
char *user;

int main(int argc, char *argv[])
{

  // clear the screen
  system("clear");

  // test to see if an option has been put on the command line
  if (argc < 2)
  {
    printf("USAGE: \"phone username\"\n");
    exit(1);
  }

  // set the variable "user" from the first the command line option
  // then populate the array "theargs" with values to be passed
  user = argv[1];
  theargs[0] = "./listen";
  theargs[1] = user;
  theargs[2] = myfifo;
  theargs[3] = myrecording;
  theargs[4] = NULL;

  // Greet the user and issue a warning regarding the recording
  printf("Hello %s\n", user);
  printf("WARNING: This Conversation WILL be recorded\n");

  // replace this program "phone" with "listen" without a fork
  // pass all variables
  execvp(theargs[0], theargs);
}
