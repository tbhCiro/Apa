#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void usage(char *);
int randomize(int);

int randomize(int num){
    return ((rand() % num)+1);
}//int randomize

void usage(char *str){
    printf("\n\t USO: %s N\n", str);
    exit(1);
}

int main(int argc, char *argv[]){
    int N, i;
    if (argc != 2) usage(argv[0]);
    srand(time(NULL));
    N=atoi(argv[1]);
    for (i=1; i<=50; i++){
        printf("%2d) %d\n", i, randomize(N) );
    }
    return 0;
} //main


