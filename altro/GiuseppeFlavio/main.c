#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

void usage(char *);

void usage (char *str){
   printf(" "
          " Usage: %s N M\n", str);
} //void usage

struct obj{
   int indice;
   struct obj *successivo;
}; // struct obj

int main(int argc, char **argv){
   if (argc != 3){
      usage(argv[0]);
      return 1;
   }
   int M=atoi(argv[1]), N=atoi(argv[2]), i;
   struct obj *point, oggetti[MAX];
   for (i=0; i<N; i++){ //ciclo che imposta la lista
      oggetti[i].indice=i+1; // ogni campo indice contiene un numero da 1 a N
      oggetti[i].successivo=&(oggetti[(i+1)%N]); // ogni campo successivo contiene un puntatore a successivo
   }
   point=&(oggetti[N-1]);
   while (point != point->successivo){
      for (i=1; i<M; i++)/* Conto gli M passi */
         point=point->successivo;
      printf("Elimino %d!\n", point->successivo->indice);
      point->successivo=point->successivo->successivo;
   }// while p != p->successivo
   printf("DONE\n");
   return 0;
}// int mainn
