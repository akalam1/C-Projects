#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{

    //int waiting = atoi(argv[1]);

    FILE *file_pointer;
    char buffer[30], c;

    file_pointer = fopen("happenstofall.txt", "r");
    // printf("reading a line\n");vi d2.c

    fgets(buffer, 50, file_pointer);
    printf("%s\n", buffer);
    sleep(2);

    // printf(" If one of those bottles just happens to fall\n");

    // sleep(3);

    //printf("mom\'s process id or my parent process id is.2:  %i\n", getppid());

    //printf("Going back to the main function\n");
    //printf("\n");

    //sleep(waiting);

    exit(0);
}

