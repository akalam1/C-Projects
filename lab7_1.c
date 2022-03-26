#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 1000

int main(int argc, char **argv)
{

    // this section is for captaring thye file

    char line[255];
    FILE *fp1;

    fp1 = fopen("bottlesofbeer.txt", "r");

    //till here
    int ppid;
    // this for captering
    int file;
    int saved_stdout;

    // till here
    // you are mom at the start

    int varifiedintput, bottles;

    int kidpid, mompid, babypid;
    int status, wstatus, ret;
    //    char *theargs [] = { NULL };
    char *theargs[2];
    char *theenv[] = {NULL};
    char command[128];

    theargs[0] = "LOVE you MA!!!";
    theargs[1] = "10";
    theargs[2] = NULL;

   

    system("clear");

    while (1)
    {
        //3

        printf("Enter How Many Bottles of Beer are on the Wall: \n");
        scanf("%d", &bottles);

        if (bottles <= 1 || bottles > 100)
        {
            //4
            printf("Not a valid no !!\n");
        }
        else
        {
            //passitaround(bottles);
            varifiedintput = bottles;

            printf("\n");
            break;
        }
    }

    fp1 = fopen("bottlesofbeer.txt", "r");

    printf("Program Started \n");
    sleep(2);
    printf("Getting pid id\n");
    sleep(2);

    mompid = getpid();

    printf("Pid for lab7=%i\n", ppid);

    //  printf("Pid for lab7_2=%i\n", kidpid);
    printf("Main PPID=%i\n", mompid);

    printf("\n");

    //running first txt file
    // for captaring

    file = open("beer.out", O_WRONLY | O_CREAT, 0600);
    if (file == -1)
    {
        return 2;
    }

    saved_stdout = dup(STDOUT_FILENO);

    //printf("Starting to capture", file);
    int file2 = dup2(file, STDOUT_FILENO);

    //printf("This is captaring%d\n", file2);

    dup2(saved_stdout, STDOUT_FILENO);

    //tull here

    while (varifiedintput > 1)
    {

        fp1 = fopen("bottlesofbeer.txt", "r");

        fgets(line, 255, fp1);
        printf("%d %s", varifiedintput, line);

        sleep(2);

        fgets(line, 255, fp1);
        printf("%d %s", varifiedintput, line);
        sleep(2);

        kidpid = fork();
        if (kidpid == 0)
        {

            execvp("./lab7_2", theargs);
        }
        sleep(2);

        varifiedintput--;

        babypid = fork();
        if (babypid == 0)
        {
            execvp("./lab7_3", theargs);
        }

        printf("..%d\n", varifiedintput);
        sleep(2);
    }

    //printf("This is the last processs\n");
    printf("%d bottle of beer on the wall,\n", varifiedintput);
    sleep(2);
    printf("%d bottle of beer!\n", varifiedintput);
    sleep(2);
    printf("if one of those bottles just happens to fall,\n");
    sleep(2);
    printf("No more bottles of beer!\n\n");
    sleep(2);

    printf("You have Reach the end \n");

    return (0);
}

