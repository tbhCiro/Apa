#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 100

struct words {
    int counter;
    int pos[N];
}parole[N];

int main(int argc, char* argv[]){
    if (argc != 2) return 1;
    FILE *file;
    int c=1, i, j=0;
    char tmp[N];

    file=fopen(argv[1], "r");
    while (fscanf(file, "%s", tmp) != EOF){
        for (i=0; i<strlen(tmp); i++){
            if (isalpha(tmp[i])){
                tmp[j]=tmp[i]; j++; //pulisco le parole dalla punteggiatura
            }
        }//for i
        parole[j].pos[(parole[j].counter)]=c;
        parole[j].counter++;
        j=0; c++;
    }//while fscanf
    i=1;
    printf("Lunghezza - Conteggio - Posizioni\n");
    while(i<11){
        if (parole[i].counter > 0){
            printf("%d - %d - ", i, parole[i].counter);
            for (j=0; j<parole[i].counter; j++){
                printf("%d ", parole[i].pos[j]);
            } printf("\n");
        }
        i++;
    }//while
    fclose(file);
    return 0;
}
