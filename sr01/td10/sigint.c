#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int attente;

/*Commentaires dans le fichier .txt joint*/

void routinesigint (int signum)
{
    printf("SIGINT\n");
}


int main()
{
    attente=10;
    printf("%d\n", getpid());
    signal(SIGINT,routinesigint);
    while(attente>0) {
        attente = sleep(attente);
        printf("restait %d sec. -- attente %d sec\n",attente,attente);
    }
    printf("fin\n");
}
