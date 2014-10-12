#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_POSIZIONI 10

struct search {
    int occorrenze, posizioni[MAX_POSIZIONI];
    char parola[4];
} words[10];

int main(int argc, char *argv[]){
    if (argc != 3) return 1;
    FILE *fdc, *ftext;
    int i, j, pos=1, num;
    char scan[100];

    fdc=fopen(argv[1], "r");
    ftext=fopen(argv[2], "r");
    fscanf(fdc, "%d", &num);
    for(i=0; i<num; i++){
        fscanf(fdc, "%s", words[i].parola);
        words[i].occorrenze=0;      // azzero tutti i parametri delle struct che uso
        for (j=0; j<MAX_POSIZIONI; j++){
            words[i].posizioni[j]=0;
        }
    }
    while(fscanf(ftext, "%s", scan)!= EOF){
        for (i=0; i<num; i++){
            if(strncmp(scan, words[i].parola, strlen(words[i].parola)) == 0){
                words[i].posizioni[words[i].occorrenze]=pos;
                words[i].occorrenze++;
            }
        } //for
        pos++;
    }//while
    for (i=0; i<num; i++){
            printf("%s - %d occorrenza/e - ", words[i].parola, words[i].occorrenze);
            for (j=0; j<words[i].occorrenze; j++){
                printf("%d ", words[i].posizioni[j]);
            }//for j
            printf("\n");
    }//for i



















/*    while(fscanf(ftext,"%s",scan) != EOF){
        for (i=0; i<num; i++){
            if(strncmp(scan, words[i].parola, strlen(words[i].parola)) == 0){
                words[i].posizioni[x]=1;
                words[i].occorrenze++;

            }
        }
        x++;
    }//while fscanf
*/
    fclose(fdc);
    fclose(ftext);
    return 0;
} //main
