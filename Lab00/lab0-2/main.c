#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    FILE *list;
    int num, i;
    char cfr[20];
    char parola[20];
    list=fopen(argv[1], "r");
    fscanf(list, "%d %s", &num, cfr);
    for (i=0; i<num; i++){
        fscanf(list, "%s", parola);
        if ((strcmp(cfr, parola)) < 0){
            printf("%s\n", parola);
        }
    }
    return 0;
}
