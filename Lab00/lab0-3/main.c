#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float calcola(float x);
void simmetrica(float m2[10][10], int dim);

float calcola(float x){
    int pw;
    if (x <= 0) return 0;
    if (x < 1){
        pw=(int)log10(x);
        return pow(10,pw);
    }else{
        pw=(int)log10(x);
        return pow(10,++pw);
    }
}

void simmetrica(float m2[10][10], int dim){
    int i, j, simm=0;
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){
            if (m2[i][j] != m2[j][i]){
                simm=1;
            }
        }
    }
    if (simm==1){
        printf("Non simmetrica.\n");
    }else{
        printf("Simmetrica.\n");
    }
}

int main(int argc, char *argv[]){
    float m2[10][10], tmp;
    int i, j, dim;
    FILE *filein;
    FILE *fileout;
    filein = fopen(argv[1], "r");
    fileout= fopen(argv[2], "w");
    fscanf(filein, "%d", &dim);
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){
            fscanf(filein, "%f", &tmp);
            m2[i][j]=calcola(tmp);
        }
    }
    for (i=0; i<dim; i++){
        for (j=0; j<dim; j++){
            fprintf(fileout, "%f ", m2[i][j]);
        }
        fprintf(fileout, "\n");
    }
    simmetrica(m2, dim);

    fclose(filein);
    fclose(fileout);
    return 0;
}
