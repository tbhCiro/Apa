#include <stdio.h>
#include <stdlib.h>
#define N 20
int main(int argc, char *argv[]){
    int m1[N][N], nc, nr, i, j;
    float m2;
    FILE *f_in, *f_out;
    f_in=fopen(argv[1], "r");
    f_out=fopen(argv[2], "w");
    // dimensione matrice
    fscanf(f_in, "%d %d", &nr, &nc);
    for (i=0; i<nr; i++){
        for (j=0; j<nc; j++){
            fscanf(f_in, "%d", &m1[i][j]);
        }//for j
    }//for i
    fprintf(f_out, "%d %d\n", nr, nc);
    for (i=0; i<nr; i++){
        for (j=0; j<nc; j++){
            if (i==0 && j==0){ // elemento in alto a sinistra
                m2=(float)(m1[0][1] + m1[1][0] + m1[1][1])/3;
            }else if (i==0 && j==nc-1){ // elemento in alto a destra
                m2=(float)(m1[i][j-1] + m1[i+1][j-1] + m1[i+1][j])/3;
            }else if (i==nr-1 && j==0){ // elemento in basso a sinistra
                m2=(float)(m1[i-1][j] + m1[i-1][j+1] + m1[i][j+1])/3;
            }else if(i==nr-1 && j==nc-1){ // elemento in basso a sinistra
                m2=(float)(m1[i][j-1] + m1[i-1][j-1] + m1[i-1][j])/3;
            }else if (i==0 && j>0 && j<nc){ // riga in alto
                m2=(float)(m1[i][j-1] + m1[i+1][j-1] + m1[i+1][j] + m1[i+1][j+1] + m1[i][j+1])/5;
            }else if (j==0 && i>0 && i<nr){ // bordo sinistro
                m2=(float)(m1[i-1][j] + m1[i-1][j+1] + m1[i][j+1] + m1[i+1][j+1] + m1[i+1][j])/5;
            }else if ((j==nc-1) && i>0 && i<nr){ // bordo destro
                m2=(float)(m1[i-1][j] + m1[i-1][j-1] + m1[i][j-1] + m1[i+1][j-1] + m1[i+1][j])/5;
            }else if ((i==nr-1) && j>0 && j<nc){ //riga in basso
                m2=(float)(m1[i][j-1] + m1[i-1][j-1] + m1[i-1][j] + m1[i-1][j+1] + m1[i][j+1])/5;
            }else{
                m2=(float)(m1[i-1][j-1] + m1[i-1][j] + m1[i-1][j+1] + m1[i][j-1] + m1[i][j+1] + m1[i+1][j-1] + m1[i+1][j] + m1[i+1][j+1])/8;
            }
            fprintf(f_out, "%.2f ", m2);
        }//for j
    fprintf(f_out, "\n");
    }//for i
    fclose(f_in);
    fclose(f_out);
    return 0;
} // main
