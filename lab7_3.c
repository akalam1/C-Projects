
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  //printf("third\n");
  int waiting = atoi(argv[1]);

  FILE *file_pointer;
  char buffer[30], c;

  file_pointer = fopen("remaining.txt", "r");
  //printf("reading a line\n");
  fgets(buffer, 50, file_pointer);
  printf("%s\n\n", buffer);
  sleep(2);

  //printf("bottles of beer on the wall..  \n");

  //we will use this at the end
  // printf("mom\'s process id or my parent process id is3: %i\n", getppid());

  sleep(waiting);
}

