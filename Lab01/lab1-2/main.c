#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 99

int main(int argc, char *argv[]){
    if (argc != 4) return 1;
    char V[MAX][80], tmp;
    int i;
    FILE *f_in, *f_out, *f_diz;
    f_in=fopen(argv[1], "r");
    f_diz=fopen(argv[2], "r");
    f_out=fopen(argv[3], "w");
    while (fscanf(f_diz, "%d", &i) != EOF){
        fscanf(f_diz, "%s", V[i]);
    }//while fscanf
    while (fscanf(f_in, "%c", &tmp) != EOF){
            if (tmp!='$'){
                fprintf(f_out, "%c", tmp);
            }else{
                fscanf(f_in, "%d", &i);
                fprintf(f_out, "%s", V[i]);
            }
    }//while fscanf
    fclose(f_in);
    fclose(f_diz);
    fclose(f_out);
    return 0;
}
