#include <stdio.h>
#include <stdlib.h>

// struttura dati
typedef struct d{
    int colonna, valore;
} n0; // elementi che non sono zero nella matrice sparsa

int simmetrica_sparsa(int**, int, int);
int simmetrica_compatta(n0**, int, int*);

int main (int argc, char **argv){
  int **mat=NULL, x, i, flag=0, j, R, C, num=0, *cnt;
  FILE *f_in=NULL;
  n0 **vett=NULL;
  if ((f_in=fopen(argv[1], "r")) == NULL) return 1;
  fscanf(f_in, "%d %d", &R, &C);
  mat=malloc(R*sizeof(int*));
  printf("Matrice \"standard\":\n");
  for (i=0; i<R; i++){
    mat[i]=malloc(C*sizeof(int));
    for (j=0; j<C; j++){
      fscanf(f_in, "%d", &mat[i][j]);
      if (mat[i][j]!=0) num++; // conto elementi non nulli
      printf("%d ", mat[i][j]);
    }printf("\n");
  }printf("\n\nMatrice \"compatta\":\n");
    // ora la matrice è correttamente caricata dal file argv[1];
    // ogni casella di vett deve essere un puntatore a struct
  vett=malloc(num*sizeof(n0*));
  cnt=malloc(num*sizeof(int));        // cnt[] contiene il numero di vettori allocati per ogni cella di vett
  for (i=0; i<R; i++){
    num=0;
    for (j=0; j<C; j++){
      if (mat[i][j] != 0) num++;  // conto occorrenze di numeri non zero nella matrice
    }
    vett[i]=malloc(num*sizeof(n0)); // ora ogni casella del vettore è allocata
    cnt[i]=num;                     // in modo da poter contenere num esatto dei
                                    // punti non 0 della matrice
    num=0;
    for (j=0; j<C; j++){
      if (mat[i][j]!=0){
        vett[i][num].colonna=j;
        vett[i][num].valore=mat[i][j];
        //printf("%d -> |%d|%d|\n", i, vett[i][num].colonna, vett[i][num].valore);
        num++;
      }
    }
  }
  // stampa matrice (totalmente inutile)
  for (i=0; i<R; i++){
    num=0;
    printf("%d -> ", i);
    for (j=0; j<cnt[i]; j++){
      printf("|%d|%d| ", vett[i][num].colonna, vett[i][num].valore); num++;
    }printf("\n");
  }
  // chiedo all'utente a quale valore vuole accedere.
  printf("\nA quale elemento vuoi accedere? (specificare i e j): ");
  scanf("%d %d", &i, &j);
  if (i>R || j>C){
    printf("i o j troppo grossi.\n");
  }else{
    printf("Matrice \"standard\": mat[%d][%d]=%d\n", i, j, mat[i][j]);
    for (x=0; x<cnt[i]; x++){
      if(vett[i][x].colonna==j && flag==0){
        printf("Nella matrice \"compatta\" l'elemento %d si trova in vett[%d][%d].valore\n", vett[i][x].valore, i, x);
        flag++;
      }
    }// entra nell'if se il valore è uno zero, quindi non è salvato nella matrice compatta
    if (flag==0) printf("in quella posizione c'è uno zero quindi non è salvato nella matrice compatta.\n");
    }flag=0;
    // ricerca di simmetricità sulla matrice standard sparsa
    if (simmetrica_sparsa(mat, R, C)){
      printf ("La matrice \"standard\" non è simmetrica.\n");
    }else{
      printf ("La matrice \"standard\" è simmetrica.\n");
    }
    // ricerca di simmetricità sulla matrice compatta
    if (simmetrica_compatta(vett, R, cnt)){
      printf ("La matrice \"compatta\" non è simmetrica.\n");
    }else{
      printf ("La matrice \"compatta\" è simmetrica.\n");
    }

    return 0;
}//main

int simmetrica_sparsa(int **matrice, int rig, int col){
  int i, j;
  for (i=0; i<rig; i++){
    for(j=i+1; j<col; j++){
      if (matrice[i][j] != matrice[j][i]) return 1;
    }
  }
  return 0;
}//int simmetrica_sparsa

int simmetrica_compatta(n0 **vett, int max, int *cnt){
  int i, j;
  for (i=0; i<max; i++){
    for (j=0; j<cnt[i]; j++){
      if (vett[i][j].colonna > max){
        return 1; // uscirei dalla matrice
      }else{
        if (vett[i][j].valore != vett[vett[i][j].colonna][i].valore){
          return 1;
        }
      }
    }// for j
  }//for i
  printf("\n");
  return 0;
}//int simmetrica_compatta()
