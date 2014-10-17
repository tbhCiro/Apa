#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// prototipi
void distanza(float *X1, float *Y1, float *X2, float *Y2, float *dist);

//struttura dati
struct {
    float x, y/*, dist*/;
} *punto;

void distanza(float *X1, float *Y1, float *X2, float *Y2, float *dist){
    *dist=sqrt(pow(*X1-*X2,2)+pow(*Y1-*Y2,2));
}// void distanza


int main(int argc, char *argv[]){
    if (argc != 4) return 1; // controllo correttezza riga di comando
    float min, max, dist;
    FILE *f_in, *f_out;
    int num_punti=0, i, j, p1, p2, p3, p4;

    f_in=fopen(argv[1], "r");
    while (fscanf(f_in, "%f %f", &min, &max) != EOF) num_punti++;
    rewind(f_in); // rileggo il file dall'inizio
    punto=malloc(num_punti*sizeof(punto));
    for (i=0; i<num_punti; i++){
        fscanf(f_in, "%f %f", &punto[i].x, &punto[i].y);
    }//for i
    min=max=0;
    printf("Lista dei punti con distanza minore di %d:\n", atoi(argv[2]));
    for (i=0; i<num_punti; i++){
        for (j=i+1; j<num_punti; j++){
            distanza(&punto[i].x, &punto[i].y, &punto[j].x, &punto[j].y, &dist);
            if ((i==0 && j==1) || dist<min){
                min=dist; p1=i; p2=j;
            }
            if (((i==0 && j==1)) || dist>max){
                max=dist; p3=i; p4=j;
            }
            if (dist <= atof(argv[2])){
                printf("P%d=(%.1f, %.1f) P%d=(%.1f, %.1f) dist=%.2f \n", i, punto[i].x, punto[i].y, j, punto[j].x, punto[j].y, dist);
            }
        }
    }//for i
    printf("i punti a distanza minore sono (%d) e (%d) che distano %.2f\n", p1, p2, min);
    printf("i punti a distanza maggiore sono (%d) e (%d) che distano %.2f\n", p3, p4, max);

    f_out=fopen(argv[3], "w");


    printf("Hello world!\n");
    fclose(f_in);
    fclose(f_out);
    return 0;
}//main
