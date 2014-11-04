/* Grazie a tbhCiro */

#include <stdio.h>
#include <stdlib.h>

void usage(char*);
void catalan(int, int *);

void usage(char *str){
  printf("Uso: %s <n>, dove n è l'ennesimo numero di Catalan.\n", str);  
}// void usage ()

void catalan(int n, int *v){
	int j;
	v[0]=1;
	if (n>0) 
		catalan(n-1, v); // scomposizione del problema
	for (j=0; j<n; j++)
		v[n]=v[n]+(v[j]*v[n-1-j]);
	return;
}



int main(int argc, char **argv) {
	if (argc != 2){
	    usage(argv[0]);
    	return -1;
	}
	int N=atoi(argv[1]), *vett;
	vett=malloc(N*sizeof(int));
	catalan(N, vett);
	printf ("Il Catalan di %d è: %d.\n", N, vett[N]);
	return 0;
}//main
