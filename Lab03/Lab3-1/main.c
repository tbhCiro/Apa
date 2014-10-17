#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// struttura dati
struct point{
    float x, y, dist_0;
} *punto;

// prototipi
void distanza(float *X1, float *Y1, float *X2, float *Y2, float *dist);
void SelectionSort(struct point punto[], int l, int r);

// funzioni
void distanza(float *X1, float *Y1, float *X2, float *Y2, float *dist){
    *dist=sqrt(pow(*X1-*X2,2)+pow(*Y1-*Y2,2));
}// void distanza

void SelectionSort(struct point punto[], int l, int r){
    int i, j, min;
    float temp, tempx, tempy;
    for (i=l; i<r; i++){
        min=i; // suppongo che l'elemento sia il minimo
        for (j=i+1; j<=r; j++){
            if (punto[j].dist_0 < punto[min].dist_0)
                min = j;
            temp = punto[i].dist_0; tempx = punto[i].x; tempy = punto[i].y;
            punto[i].dist_0 = punto[min].dist_0; punto[i].x = punto[min].x; punto[i].y = punto[min].y;
            punto[min].dist_0 = temp; punto[min].x = tempx; punto[min].y = tempy;
        }// for j
    }//for i

}// void SelectionSort

int main(int argc, char *argv[]){
    if (argc != 4) return 1; // controllo correttezza riga di comando
    float min, max, dist;
    FILE *f_in=NULL, *f_out=NULL;
    int num_punti=0, i, j, p1, p2, p3, p4;

    f_in=fopen(argv[1], "r");
    while (fscanf(f_in, "%f %f", &min, &max) != EOF) num_punti++; //conto il numero dei punti
    rewind(f_in); // rileggo il file dall'inizio
    punto=malloc((num_punti+1)*sizeof(punto));  // malloc della struct
    punto[num_punti+1].x=punto[num_punti+1].y=0; // origine
    for (i=0; i<num_punti; i++){
        fscanf(f_in, "%f %f", &punto[i].x, &punto[i].y); // salvo tutti i punti
    }//for i
    min=max=0;
    printf("Lista dei punti con distanza minore di %d:\n", atoi(argv[2]));
    for (i=0; i<num_punti; i++){
        distanza(&punto[i].x, &punto[i].y, &punto[num_punti+1].x, &punto[num_punti+1].y, &punto[i].dist_0); // calcolo la distanza da zero
        for (j=i+1; j<num_punti; j++){
            distanza(&punto[i].x, &punto[i].y, &punto[j].x, &punto[j].y, &dist); // calcolo la distanza fra tutti i punti
            if ((i==0 && j==1) || dist<min){
                min=dist; p1=i; p2=j;   // salvo distanza minima e punti
            }
            if (((i==0 && j==1)) || dist>max){
                max=dist; p3=i; p4=j;  // salvo distanza massima e punti
            }
            if (dist<=atof(argv[2])){  // stampo tutte le coppie che hanno una distanza inferiore ad argv[2]
                printf("P%d=(%.1f, %.1f) P%d=(%.1f, %.1f) dist=%.2f \n", i, punto[i].x, punto[i].y, j, punto[j].x, punto[j].y, dist);
            }
        }
    }//for i
    printf("\nI punti a distanza minore sono (%d) e (%d) che distano %.2f\n", p1, p2, min);
    printf("I punti a distanza maggiore sono (%d) e (%d) che distano %.2f\n", p3, p4, max);
    SelectionSort(punto, 0, num_punti-1); // ordino
    f_out=fopen(argv[3], "w");
    for (i=0;i<num_punti;i++){
        fprintf(f_out, "P%d=(%.1f, %.1f); dist=%.2f\n", i, punto[i].x, punto[i].y, punto[i].dist_0); // stampa ordinata nel file
    }//for i
    free(punto);
    return 0;

}//main
